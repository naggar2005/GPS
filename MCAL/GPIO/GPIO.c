#include "GPIO.h"
#include "../../LIB/TM4C123GH6PM.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../../LIB/TYPE_DEF.h"


void GPIO_Init(u8 PortId){
            switch (PortId)
        {
            case GPIO_PORTA:
                SET_BIT(SYSCTL_RCGCGPIO_R, GPIO_PORTA);
                while (BIT_IS_CLEAR(SYSCTL_PRGPIO_R, GPIO_PORTA));
                GPIO_PORTA_LOCK_R = GPIO_LOCK_KEY;
                break;

            case GPIO_PORTB:
                SET_BIT(SYSCTL_RCGCGPIO_R, GPIO_PORTB);
                while (BIT_IS_CLEAR(SYSCTL_PRGPIO_R, GPIO_PORTB));
                GPIO_PORTB_LOCK_R = GPIO_LOCK_KEY;
                break;

            case GPIO_PORTC:
                SET_BIT(SYSCTL_RCGCGPIO_R, GPIO_PORTC);
                while (BIT_IS_CLEAR(SYSCTL_PRGPIO_R, GPIO_PORTC));
                GPIO_PORTC_LOCK_R = GPIO_LOCK_KEY;
                break;

            case GPIO_PORTD:
                SET_BIT(SYSCTL_RCGCGPIO_R, GPIO_PORTD);
                while (BIT_IS_CLEAR(SYSCTL_PRGPIO_R, GPIO_PORTD));
                GPIO_PORTD_LOCK_R = GPIO_LOCK_KEY;
                break;

            case GPIO_PORTE:
                SET_BIT(SYSCTL_RCGCGPIO_R, GPIO_PORTE);
                while (BIT_IS_CLEAR(SYSCTL_PRGPIO_R, GPIO_PORTE));
                GPIO_PORTE_LOCK_R = GPIO_LOCK_KEY;
                break;

            case GPIO_PORTF:
                SET_BIT(SYSCTL_RCGCGPIO_R, GPIO_PORTF);
                while (BIT_IS_CLEAR(SYSCTL_PRGPIO_R, GPIO_PORTF));
                GPIO_PORTF_LOCK_R = GPIO_LOCK_KEY;
                break;
        }

}

void GPIO_Pin_Init(u8 PortId , u8 PinId){
        switch (PortId)
        {
            case GPIO_PORTA:
                SET_BIT(GPIO_PORTA_CR_R, PinId);            //commit register(works as enable)
                CLEAR_BIT(GPIO_PORTA_AMSEL_R, PinId);       //disable analog mode
                CLEAR_BIT(GPIO_PORTA_AFSEL_R, PinId);        //Alternate Function Select Register(0 for GPIO pin not special for UART/PWM)
                GPIO_PORTA_PCTL_R &= ~(0xF << (PinId * 4));  // Clear PCTL bits
                //SET_BIT(GPIO_PORTA_DEN_R, pinId);          //enable digital I/O pin
                break;

            case GPIO_PORTB:
                SET_BIT(GPIO_PORTB_CR_R, PinId);      
                CLEAR_BIT(GPIO_PORTB_AMSEL_R, PinId); 
                CLEAR_BIT(GPIO_PORTB_AFSEL_R, PinId);
                GPIO_PORTB_PCTL_R &= ~(0xF << (PinId * 4)); 
                //SET_BIT(GPIO_PORTB_DEN_R, pinId);
                break;

            case GPIO_PORTC:
                SET_BIT(GPIO_PORTC_CR_R, PinId);      
                CLEAR_BIT(GPIO_PORTC_AMSEL_R, PinId); 
                CLEAR_BIT(GPIO_PORTC_AFSEL_R, PinId);
                GPIO_PORTC_PCTL_R &= ~(0xF << (PinId * 4)); 
                //SET_BIT(GPIO_PORTC_DEN_R, pinId);
                break;

            case GPIO_PORTD:
                SET_BIT(GPIO_PORTD_CR_R, PinId);      
                CLEAR_BIT(GPIO_PORTD_AMSEL_R, PinId); 
                CLEAR_BIT(GPIO_PORTD_AFSEL_R, PinId);
                GPIO_PORTD_PCTL_R &= ~(0xF << (PinId * 4)); 
                //SET_BIT(GPIO_PORTD_DEN_R, pinId);
                break;

            case GPIO_PORTE:
                SET_BIT(GPIO_PORTE_CR_R, PinId);      
                CLEAR_BIT(GPIO_PORTE_AMSEL_R, PinId); 
                CLEAR_BIT(GPIO_PORTE_AFSEL_R, PinId);
                GPIO_PORTE_PCTL_R &= ~(0xF << (PinId * 4)); 
                //SET_BIT(GPIO_PORTE_DEN_R, pinId);
                break;

            case GPIO_PORTF:
                SET_BIT(GPIO_PORTF_CR_R, PinId);      
                CLEAR_BIT(GPIO_PORTF_AMSEL_R, PinId); 
                CLEAR_BIT(GPIO_PORTF_AFSEL_R, PinId);
                GPIO_PORTE_PCTL_R &= ~(0xF << (PinId * 4)); 
                //SET_BIT(GPIO_PORTF_DEN_R, pinId);
                break;
        }
}

void set_Pin_Direction(u8 PortId, u8 PinId, u8 PinDirection) {
    switch (PortId) {
        case GPIO_PORTA:
            SET_BIT(GPIO_PORTA_DEN_R, PinId); // Enable digital I/O
            if (PinDirection == GPIO_OUTPUT)
                SET_BIT(GPIO_PORTA_DIR_R, PinId);
            else
                CLEAR_BIT(GPIO_PORTA_DIR_R, PinId);
            break;

        case GPIO_PORTB:
            SET_BIT(GPIO_PORTB_DEN_R, PinId);
            if (PinDirection == GPIO_OUTPUT)
                SET_BIT(GPIO_PORTB_DIR_R, PinId);
            else
                CLEAR_BIT(GPIO_PORTB_DIR_R, PinId);           
            break;

        case GPIO_PORTC:
            SET_BIT(GPIO_PORTC_DEN_R, PinId);
            if (PinDirection == GPIO_OUTPUT)
                SET_BIT(GPIO_PORTC_DIR_R, PinId);
            else
                CLEAR_BIT(GPIO_PORTC_DIR_R, PinId);          
            break;

        case GPIO_PORTD:
            SET_BIT(GPIO_PORTD_DEN_R, PinId);
            if (PinDirection == GPIO_OUTPUT)
                SET_BIT(GPIO_PORTD_DIR_R, PinId);
            else
                CLEAR_BIT(GPIO_PORTD_DIR_R, PinId);            
            break;

        case GPIO_PORTE:
            SET_BIT(GPIO_PORTE_DEN_R, PinId);
            if (PinDirection == GPIO_OUTPUT)
                SET_BIT(GPIO_PORTE_DIR_R, PinId);
            else
                CLEAR_BIT(GPIO_PORTE_DIR_R, PinId);           
            break;

        case GPIO_PORTF:
            SET_BIT(GPIO_PORTF_DEN_R, PinId);
            if (PinDirection == GPIO_OUTPUT)
                SET_BIT(GPIO_PORTF_DIR_R, PinId);
            else
                CLEAR_BIT(GPIO_PORTF_DIR_R, PinId);          
            break;
    }
}

void set_Port_Direction(u8 PortId , u8 PinDirection){
    switch (PortId) {
        case GPIO_PORTA:
            SET_PORT(GPIO_PORTA_DEN_R); // Enable digital I/O
            if (PinDirection == GPIO_OUTPUT)
                SET_PORT(GPIO_PORTA_DIR_R);
            else
                CLEAR_PORT(GPIO_PORTA_DIR_R);
            break;

        case GPIO_PORTB:
            SET_PORT(GPIO_PORTB_DEN_R);
            if (PinDirection == GPIO_OUTPUT)
                SET_PORT(GPIO_PORTB_DIR_R);
            else
                CLEAR_PORT(GPIO_PORTB_DIR_R);           
            break;

        case GPIO_PORTC:
            SET_PORT(GPIO_PORTC_DEN_R);
            if (PinDirection == GPIO_OUTPUT)
                SET_PORT(GPIO_PORTC_DIR_R);
            else
                CLEAR_PORT(GPIO_PORTC_DIR_R);          
            break;

        case GPIO_PORTD:
            SET_PORT(GPIO_PORTD_DEN_R);
            if (PinDirection == GPIO_OUTPUT)
                SET_PORT(GPIO_PORTD_DIR_R);
            else
                CLEAR_PORT(GPIO_PORTD_DIR_R);            
            break;

        case GPIO_PORTE:
            SET_PORT(GPIO_PORTE_DEN_R);
            if (PinDirection == GPIO_OUTPUT)
                SET_PORT(GPIO_PORTE_DIR_R);
            else
                CLEAR_PORT(GPIO_PORTE_DIR_R);           
            break;

        case GPIO_PORTF:
            SET_PORT(GPIO_PORTF_DEN_R);
            if (PinDirection == GPIO_OUTPUT)
                SET_PORT(GPIO_PORTF_DIR_R);
            else
                CLEAR_PORT(GPIO_PORTF_DIR_R);          
            break;
    }
}

        //Make sure the pin is configured as an output before calling set_Pin_Value()
        //, otherwise writing to DATA will have no effect.
void set_Pin_Value(u8 PortId, u8 PinId, u8 value){
    switch (PortId) {
        case GPIO_PORTA:
            if (value == LOGIC_HIGH)
                SET_BIT(GPIO_PORTA_DATA_R, PinId);
            else
                CLEAR_BIT(GPIO_PORTA_DATA_R, PinId);
            break;

        case GPIO_PORTB:
            if (value == LOGIC_HIGH)
                SET_BIT(GPIO_PORTB_DATA_R, PinId);
            else
                CLEAR_BIT(GPIO_PORTB_DATA_R, PinId);
            break;

        case GPIO_PORTC:
            if (value == LOGIC_HIGH)
                SET_BIT(GPIO_PORTC_DATA_R, PinId);
            else
                CLEAR_BIT(GPIO_PORTC_DATA_R, PinId);
            break;

        case GPIO_PORTD:
            if (value == LOGIC_HIGH)
                SET_BIT(GPIO_PORTD_DATA_R, PinId);
            else
                CLEAR_BIT(GPIO_PORTD_DATA_R, PinId);
            break;

        case GPIO_PORTE:
            if (value == LOGIC_HIGH)
                SET_BIT(GPIO_PORTE_DATA_R, PinId);
            else
                CLEAR_BIT(GPIO_PORTE_DATA_R, PinId);
            break;

        case GPIO_PORTF:
            if (value == LOGIC_HIGH)
                SET_BIT(GPIO_PORTF_DATA_R, PinId);
            else
                CLEAR_BIT(GPIO_PORTF_DATA_R, PinId);
            break;
    }
}

void set_Port_Value(u8 PortId, u8 value){
    switch (PortId) {
        case GPIO_PORTA:
            GPIO_PORTA_DATA_R = value;
            break;

        case GPIO_PORTB:
            GPIO_PORTB_DATA_R = value;
            break;

        case GPIO_PORTC:
            GPIO_PORTC_DATA_R = value;
            break;

        case GPIO_PORTD:
            GPIO_PORTD_DATA_R = value;
            break;

        case GPIO_PORTE:
            GPIO_PORTE_DATA_R = value;
            break;

        case GPIO_PORTF:
            GPIO_PORTF_DATA_R = value;
            break;

    }
}

void toggle_Pin_value(u8 PortId, u8 PinId){
    switch (PortId) {
        case GPIO_PORTA:
            TOGGLE_BIT(GPIO_PORTA_DATA_R, PinId);
            break;

        case GPIO_PORTB:
            TOGGLE_BIT(GPIO_PORTB_DATA_R, PinId);
            break;

        case GPIO_PORTC:
            TOGGLE_BIT(GPIO_PORTC_DATA_R, PinId);
            break;

        case GPIO_PORTD:
            TOGGLE_BIT(GPIO_PORTD_DATA_R, PinId);
            break;

        case GPIO_PORTE:
            TOGGLE_BIT(GPIO_PORTE_DATA_R, PinId);
            break;

        case GPIO_PORTF:
            TOGGLE_BIT(GPIO_PORTF_DATA_R, PinId);
            break;
    }
}

u8 read_Pin_Direction(u8 PortId , u8 PinId){
    switch (PortId) {
        case GPIO_PORTA:
            return GET_BIT(GPIO_PORTA_DIR_R, PinId);

        case GPIO_PORTB:
            return GET_BIT(GPIO_PORTB_DIR_R, PinId);

        case GPIO_PORTC:
            return GET_BIT(GPIO_PORTC_DIR_R, PinId);

        case GPIO_PORTD:
            return GET_BIT(GPIO_PORTD_DIR_R, PinId);

        case GPIO_PORTE:
            return GET_BIT(GPIO_PORTE_DIR_R, PinId);

        case GPIO_PORTF:
            return GET_BIT(GPIO_PORTF_DIR_R, PinId);
        default:
            return 0; // Default to invalid INPUT
    }
}


u8 read_Pin_Value(u8 PortId , u8 PinId){
    switch (PortId) {
        case GPIO_PORTA:
            return GET_BIT(GPIO_PORTA_DATA_R, PinId);

        case GPIO_PORTB:
            return GET_BIT(GPIO_PORTB_DATA_R, PinId);

        case GPIO_PORTC:
            return GET_BIT(GPIO_PORTC_DATA_R, PinId);

        case GPIO_PORTD:
            return GET_BIT(GPIO_PORTD_DATA_R, PinId);

        case GPIO_PORTE:
            return GET_BIT(GPIO_PORTE_DATA_R, PinId);

        case GPIO_PORTF:
            return GET_BIT(GPIO_PORTF_DATA_R, PinId);
        default:
            return 0; // Default to invalid INPUT
    }
}

                        //enabling alternate Function   FunctionCode for U1RX , U1TX is 0x1
void set_Pin_PCTL(u8 PortId, u8 PinId, u8 FunctionCode) {
    switch (PortId) {
        case GPIO_PORTA:
            SET_BIT(GPIO_PORTA_AFSEL_R, PinId); // Enable alternate function
            GPIO_PORTA_PCTL_R &= ~(0xF << (PinId * 4));
            GPIO_PORTA_PCTL_R |=  (FunctionCode << (PinId * 4));
            break;

        case GPIO_PORTB:
            SET_BIT(GPIO_PORTB_AFSEL_R, PinId);
            GPIO_PORTB_PCTL_R &= ~(0xF << (PinId * 4));
            GPIO_PORTB_PCTL_R |=  (FunctionCode << (PinId * 4));
            break;

        case GPIO_PORTC:
            SET_BIT(GPIO_PORTC_AFSEL_R, PinId);
            GPIO_PORTC_PCTL_R &= ~(0xF << (PinId * 4));
            GPIO_PORTC_PCTL_R |=  (FunctionCode << (PinId * 4));
            break;

        case GPIO_PORTD:
            SET_BIT(GPIO_PORTD_AFSEL_R, PinId);
            GPIO_PORTD_PCTL_R &= ~(0xF << (PinId * 4));
            GPIO_PORTD_PCTL_R |=  (FunctionCode << (PinId * 4));
            break;

        case GPIO_PORTE:
            SET_BIT(GPIO_PORTE_AFSEL_R, PinId);
            GPIO_PORTE_PCTL_R &= ~(0xF << (PinId * 4));
            GPIO_PORTE_PCTL_R |=  (FunctionCode << (PinId * 4));
            break;

        case GPIO_PORTF:
            SET_BIT(GPIO_PORTF_AFSEL_R, PinId);
            GPIO_PORTF_PCTL_R &= ~(0xF << (PinId * 4));
            GPIO_PORTF_PCTL_R |=  (FunctionCode << (PinId * 4));
            break;
    }
}

void GPIO_EnablePUR(u8 PortId, u8 PinId) {
    switch (PortId)
    {
        case GPIO_PORTA:
            SET_BIT(GPIO_PORTA_PUR_R, PinId);
            break;

        case GPIO_PORTB:
            SET_BIT(GPIO_PORTB_PUR_R, PinId);
            break;

        case GPIO_PORTC:
            SET_BIT(GPIO_PORTC_PUR_R, PinId);
            break;

        case GPIO_PORTD:
            SET_BIT(GPIO_PORTD_PUR_R, PinId);
            break;

        case GPIO_PORTE:
            SET_BIT(GPIO_PORTE_PUR_R, PinId);
            break;

        case GPIO_PORTF:
            SET_BIT(GPIO_PORTF_PUR_R, PinId);
            break;
    }
}




            // test case on UART1
/*
        GPIO_Init(GPIO_PORTB);
        GPIO_Pin_Init(GPIO_PORTB, 0); // PB0 => UART1_RX
        GPIO_Pin_Init(GPIO_PORTB, 1); // PB1 => UART1_TX

        set_Pin_PCTL(GPIO_PORTB, 0, 0x1);
        set_Pin_PCTL(GPIO_PORTB, 1, 0x1);
*/
/*
    GPIO_Init(GPIO_PORTF);
    GPIO_Pin_Init(GPIO_PORTF, GPIO_PIN4);      
    set_Pin_Direction(GPIO_PORTF, GPIO_PIN4, GPIO_INPUT);
    GPIO_EnablePUR(GPIO_PORTF, GPIO_PIN4);     
*/
