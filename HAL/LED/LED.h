/*
NAMED:Ahmed Mohamed Elsayed
ID: 2200621
*/
#include "../../LIB/TYPE_DEF.h"

/********************************< MACROS for colours ********************************/
#define LED_RED  	 	1
#define LED_BLUE 		2
#define LED_GREEN	    3

/**********************************< _SELECT_MC_PIN_ ***************************************/
#define LED_RED_PIN  	 	1
#define LED_BLUE_PIN 		2
#define LED_GREEN_PIN	    3
/**********************************< _SELECT_LED_TIME_ON_ **********************************/
#define LED_TIME_ON			100000 // (25 ms)

/********************************< BONUS DESCRIPTION *********************************/

/* 

Green LED turns on when the target destination is reached.
BLUE LED turns on when the target destination is about to be reached (less than 5 meters away).
Red LED turns on when the target destination is far away (more than 5 meters).
 
*/ 

/********************************< functions for LEDs *********************************/

/* Initializes LED pins as output by configuring the relevant GPIO pins.


 */ 
void LED_LedInit(void);

/*	Turns on the specified LED (Red, Green, or Blue) by setting its pin HIGH.*/

void LED_LedOn(u8 LedColour);	 

/*	Turns off the specified LED by setting its pin LOW.*/

void LED_LedOff(u8 LedColour);

/*	Turns off all LEDs by setting their corresponding pins LOW.*/

void LED_LedOffAll(void);

void LED_OUTPUT(float DISTANCE);
