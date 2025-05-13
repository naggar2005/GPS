#include "LCD.h"
#include "GPS.h"
#include "UART.h"
#include "SysTick.h"
#include "SW.h"
#include "LED.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define NAME_LENGTH 16
	typedef struct {
    char name[NAME_LENGTH];  
    float latitude;
    float longitude;
} landmarks;
    landmarks y[7] = {
				{"Library", 30.06651588, 31.2801509},
				{"Hall C,D" ,30.0636517, 31.2805223},
        {"Gate 2", 30.0646229, 31.2773329},
        {"Modrgat", 30.0642291, 31.2791021},
        {"Mosque", 30.0646420, 31.2804053},
        {"water Fountain", 30.0655363, 31.2784373},
        {"Palestine Hall", 30.0651553, 31.2786119}
};
		
int main(void)
{
    int i = 0;
		float t=0 , T=0.5;
    float min_d = 0.0, d = 0.0, prev_d = 0.0;
    int current = 0 , prev_current = 0;
    int moving_state = 0;
    uart_init();
		SysTick_Init();
		SW_Init();
		LED_LedInit();
    LCD_Init();
    LCD_Clear();
    LCD_String("Waiting for GPS");

    gps_read();
    gps_format();
    while (1)
    {
        gps_read();
        gps_format();
				
        // Find nearest location
        min_d = gps_get_distance(lat_A, long_A, y[0].latitude, y[0].longitude);
        for (i = 1; i < 7; i++)
        {
            d = gps_get_distance(lat_A, long_A, y[i].latitude, y[i].longitude);
            if (d < min_d)
            {
                min_d = d;
                current = i;
            }
        }
				SW1_Pressed (min_d, speed);
				LED_LedOffAll();
				LED_OUTPUT(min_d);
        //Check movement state
        if (current == prev_current)
        {
            if (min_d < prev_d-t)         // approaching 
                moving_state = 1;
            else if (min_d > prev_d+t)          // leaving
                moving_state = 2;
            else
                moving_state = 0;             // stationary
        }
        else
        {
            moving_state = 1;                 // changed location (assume approaching)
        }

       if(lat_A!=0&&long_A!=0){
			if(speed<=T){									//tolerance to avoid GPS noise
						LCD_Clear();
            LCD_String("Stationary near");
			}
			else{
        if (moving_state == 1)
				{
						LCD_Clear();
            LCD_String("Approaching...");
			  }
        else if (moving_state == 2)
				{
						LCD_Clear();
            LCD_String("Leaving...");
				}
				}}
        LCD_SetCursor(0, 0);
        LCD_String(y[current].name);
				SysTick_Wait_n_ms(500);

        // Update previous values
        prev_d = min_d;
        prev_current = current;
    }}

