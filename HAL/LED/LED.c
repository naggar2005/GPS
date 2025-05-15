/*
NAMED:Ahmed Mohamed Elsayed
ID: 2200621
*/
#include "../../LIB/TM4C123GH6PM.h"
#include "../../MCAL/GPIO/GPIO.h"
#include "LED.h"
#include "../../MCAL/systick/SysTick.h"
void LED_LedInit(void)
{
  GPIO_Init(GPIO_PORTF);
	GPIO_Pin_Init(GPIO_PORTF,LED_RED_PIN);
	GPIO_Pin_Init(GPIO_PORTF,LED_BLUE_PIN);
	GPIO_Pin_Init(GPIO_PORTF,LED_GREEN_PIN);
	set_Pin_Direction(GPIO_PORTF, LED_BLUE_PIN, GPIO_OUTPUT);   /**< then initialize the LED direction */
	set_Pin_Direction(GPIO_PORTF, LED_GREEN_PIN, GPIO_OUTPUT);  /**< then initialize the LED direction */  
	set_Pin_Direction(GPIO_PORTF, LED_RED_PIN, GPIO_OUTPUT);    /**< then initialize the LED direction */
}

void LED_LedOn(u8 LEDColour)
{
    switch(LEDColour)
    {
        case LED_BLUE:
            set_Pin_Value(GPIO_PORTF, LED_BLUE_PIN, GPIO_HIGH);
            break;
        case LED_GREEN:
            set_Pin_Value(GPIO_PORTF, LED_GREEN_PIN, GPIO_HIGH);
            break;
        case LED_RED:
            set_Pin_Value(GPIO_PORTF, LED_RED_PIN, GPIO_HIGH);
            break;
        default :/**< Error State */ break;
    }
}

void LED_vLedOff(u8 LedColour)
{
    switch(LedColour)
    {
        case LED_BLUE:
            set_Pin_Value(GPIO_PORTF, LED_BLUE_PIN, GPIO_LOW);
            break;
        case LED_GREEN:
            set_Pin_Value(GPIO_PORTF, LED_GREEN_PIN, GPIO_LOW);
            break;
        case LED_RED:
            set_Pin_Value(GPIO_PORTF, LED_RED_PIN, GPIO_LOW);
            break;
        default :/**< Error State */ break;
    }
}

void LED_LedOffAll(void)
{
	set_Pin_Value(GPIO_PORTF, LED_BLUE_PIN, GPIO_LOW);
	set_Pin_Value(GPIO_PORTF, LED_RED_PIN, GPIO_LOW);
	set_Pin_Value(GPIO_PORTF, LED_GREEN_PIN, GPIO_LOW);
}

void LED_OUTPUT(float DISTANCE){
	if(DISTANCE < 5) {
            LED_LedOn(LED_GREEN);
        } else if(DISTANCE < 15) {
            LED_LedOn(LED_BLUE);
        } else {
            LED_LedOn(LED_RED);
        }
}

