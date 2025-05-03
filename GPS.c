#include "GPS.h"
#include "bit_utilies.h"
#include<math.h>
#include <string.h>
#include"uart.h"

char gps[80];
char gps_logname[]="$GPRMC,";

const double Earth_Radius=6371000;
void gps_read()
{
	char recieved_char;
	//check that the logname recieved is the gps_logname
	char flag=1;
	do
	{
		flag=1;
		for(char i=0;i<7;i++)
		{
			if( uart_getchar()!=gps_logname[i])
			{
				flag=0;
				break;
			}
		}
		  
	}while(flag==0);
	strcpy(gps,"");
	do
	{
		char fill_gps_counter=0;
		recieved_char=uart_getchar();
		gps[ fill_gps_counter++ ]=recieved_char;
		
	}while(recieved_char != '*');
	
}

float dist_to_degree(float angle)
{
	int degree = (int)angle/100 ;
	float minutes=angle-(float)degree*100;
	return(degree+(minutes/60));
}
float degree_to_rad(float angle)
{
	return angle*pi/180;
}
//A--> current location(latitude,longtude)
//B--> final location(latitude,longtude)
//phi A--> latitude A in rad
//phi B--> latitude B in rad
//lamda A--> longitude A in rad
//lamda B--> longitude B in rad
float gps_get_distance(float lat_A,float long_A ,float lat_B,float long_B)//paarameters will be sended using gps module
{
	//get phi and lamd
	float phi_A=degree_to_rad(dist_to_degree(lat_A));
	float phi_B=degree_to_rad(dist_to_degree(lat_B));
	float lamda_A=degree_to_rad(dist_to_degree(long_A));
	float lamda_B=degree_to_rad(dist_to_degree(long_B));
	//get diffrences
	float lat_diff=phi_B-phi_A;
	float long_diff=lamda_B-lamda_A;
	float a=pow(sin(lat_diff)/2,2)+cos(phi_A)*cos(phi_B)*pow(sin(long_diff)/2,2);
	double c=2*atan2(sqrt(a),sqrt(1-2));
	return Earth_Radius*c;
}


