#include "../../LIB/TM4C123GH6PM.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../../HAL/GPS/GPS.h"
#include "../../HAL/LCD/LCD.h"
#include "../../MCAL/systick/SysTick.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "SW.h"

void SW_Init(void)
{
  GPIO_Init(GPIO_PORTF);
  GPIO_Pin_Init(GPIO_PORTF,SW1);
  set_Pin_Direction(GPIO_PORTF, SW1, GPIO_INPUT); 
  GPIO_EnablePUR(GPIO_PORTF, SW1);
}

//if the switch is pressed display the distance and speed
void SW1_Pressed (float distance, float speed){
	if (read_Pin_Value(GPIO_PORTF , SW1) != 1){ 
		LCD_Clear();
    		LCD_String("Distance:");
		LCD_Float(distance, 3);
		LCD_String(" m");
		LCD_SetCursor(0, 0);
		LCD_String("Speed:");
		LCD_Float(speed, 4);
		LCD_String(" m/s");
		SysTick_Wait_n_Sec(5);

	}
	
}