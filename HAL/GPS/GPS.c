
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include "../../MCAL/UART/UART.h"
#include "../../LIB/TM4C123GH6PM.h"
#include "../../LIB/TYPE_DEF.h"
#include "../../LIB/COMMON_MACROS.h"
#include "GPS.h"
char gps[82];
char gps_logname[]="$GPRMC,";


char gps_formated [12][20];
char * token;
float lat_A , long_A;
int D=0;
float speed=0.0 , M=0.0;
float k=1.94384;

const double Earth_Radius=6371000;
void gps_read(void)
{

	char recieved_char , fill_gps_counter = 0;
	char i = 0;
	//check that the logname recieved is the gps_logname
	char flag = 1;
	do
		{
			flag=1;
			for (i = 0;i<7;i++)
			{
				if (uart_getchar()!= gps_logname[i])
				{
					flag=0;
					break;
				}
			}
		}while(flag==0);

	strcpy(gps,"");
	do
		{
			recieved_char = uart_getchar();
			gps [fill_gps_counter++] = recieved_char;
			
		}
	while(recieved_char != '*');
}

float dist_to_degree(float angle)
{
	int degree = (int)angle/100 ;
	float minutes = angle-(float)degree*100;
	return(degree+(minutes/60));
}
float degree_to_rad(float angle)
{
	return angle*(float)pi/180;
}

//A--> current location(latitude,longtude)
//B--> final location(latitude,longtude)
//phi A--> latitude A in rad
//phi B--> latitude B in rad
//lamda A--> longitude A in rad
//lamda B--> longitude B in rad

float gps_get_distance(float lat_A2,float long_A2 ,float lat_B2,float long_B2)                     //paarameters will be sended using gps module
{
	//get phi and lamd
	float phi_A = degree_to_rad(dist_to_degree(lat_A2));
	float phi_B = degree_to_rad(dist_to_degree(lat_B2));
	float lamda_A = degree_to_rad(dist_to_degree(long_A2));
	float lamda_B = degree_to_rad(dist_to_degree(long_B2));
	
	//get diffrences
	float lat_diff = phi_B - phi_A;
	float long_diff = lamda_B - lamda_A;
	
	//calculate the distance
	float a = pow(sin(lat_diff)/2,2) + cos(phi_A) * cos(phi_B)* pow(sin(long_diff)/2,2);
	double c = 2 * atan2(sqrt(a),sqrt(1-a));
	return Earth_Radius * c;
}

void gps_format(void)
{
	char no_OF_strings = 0;
	token = strtok(gps,",");
	do
	{
		strcpy (gps_formated[no_OF_strings] , token);
		token = strtok(NULL , ",");
		no_OF_strings++;
	}
	while(token != NULL);
	
		if (strcmp (gps_formated[1] , "A") == 0)           //A means valid
		{
			if (strcmp (gps_formated[3] , "N") == 0)         //N for north (Positive)
			{
				lat_A = atof (gps_formated[2]);
			}
			else                                             //south (Negaative)
			{
				lat_A = - atof (gps_formated[2]);
			}
			if (strcmp (gps_formated[5] , "E") == 0)         //E for east (positive)
			{
				long_A = atof (gps_formated[4]);
			}
			else                                             //West (Negative)
			{
				long_A = - atof (gps_formated[4]);
			}
		speed= atof(gps_formated[6]);
		speed=speed/k;	
		}
		
	D = lat_A/100 ;
	M = lat_A - D*100;
	lat_A = D + M/60;
	D = long_A/100 ;
	M=long_A-D*100;
	long_A = D + M/60;
}




