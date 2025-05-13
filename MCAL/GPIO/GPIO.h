#ifndef GPIO_h
#define GPIO_h

#include "../../LIB/TM4C123GH6PM.h"
#include "../../LIB/TYPE_DEF.h"
#include "../../LIB/COMMON_MACROS.h"

//GPIO ports
#define GPIO_PORTA      0
#define GPIO_PORTB      1
#define GPIO_PORTC      2
#define GPIO_PORTD      3
#define GPIO_PORTE      4
#define GPIO_PORTF      5

//GPIO Pins
#define GPIO_PIN0       0
#define GPIO_PIN1       1
#define GPIO_PIN2       2
#define GPIO_PIN3       3
#define GPIO_PIN4       4
#define GPIO_PIN5       5
#define GPIO_PIN6       6
#define GPIO_PIN7       7

            //GPIO pin configurations
                //direction(input or output)
#define GPIO_OUTPUT     1
#define GPIO_INPUT      0

//                  HERE WE CAN USE COMMON MACROS
#define GPIO_HIGH       1
#define GPIO_LOW        0   


void GPIO_Init(u8 PortId);

void GPIO_Pin_Init(u8 PortId , u8 PinId);

void set_Pin_Direction(u8 PortId , u8 PinId , u8 PinDirection);
/*
    0 => input
    1 => output
*/

void set_Port_Direction(u8 PortId , u8 PinDirection);
/*
    0 => input
    1 => output
*/

void set_Pin_Value(u8 PortId, u8 PinId, u8 value);
/*
    //Make sure the pin is configured as an output before calling set_Pin_Value()
    //, otherwise writing to DATA will have no effect.
*/

void set_Port_Value(u8 PortId, u8 value);
/*
    //Make sure the pin is configured as an output before calling set_Pin_Value()
    //, otherwise writing to DATA will have no effect.
*/

void toggle_Pin_value(u8 PortId, u8 PinId);
/*
    //Make sure the pin is configured as an output before calling set_Pin_Value()
    //, otherwise writing to DATA will have no effect.
*/

u8 read_Pin_Direction(u8 PortId , u8 PinId);

u8 read_Pin_Value(u8 PortId , u8 PinId);

void set_Pin_PCTL(u8 PortId, u8 PinId, u8 FunctionCode);

void GPIO_EnablePUR(u8 PortId, u8 PinId);

#endif
