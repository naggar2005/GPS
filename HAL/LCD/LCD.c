#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "../../LIB/TYPE_DEF.h"
#include "../../LIB/TM4C123GH6PM.h"
#include "LCD.h"
#include "../../MCAL/systick/SysTick.h"



// Pin bit masks
#define RS 0x80    // PA7
#define EN 0x40    // PA6
#define DATA_MASK 0x3C  // PA2�PA5

// Delay functions
void delayMs(int n) {
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < 3180; j++) {}
}

void delayUs(int n) {
    int i, j;
    for(i = 0; i < n; i++)
        for(j = 0; j < 3; j++) {}
}

// GPIO initialization for LCD (PA2�PA7)
void LCD_GPIO_Init(void) {
    SYSCTL_RCGCGPIO_R |= 0x01;              // Enable clock for Port A
    while((SYSCTL_PRGPIO_R & 0x01) == 0);   // Wait until ready

    GPIO_PORTA_DIR_R |= 0xFC;               // Set PA2�PA7 as output
    GPIO_PORTA_DEN_R |= 0xFC;               // Enable digital on PA2�PA7
    GPIO_PORTA_AFSEL_R &= ~0xFC;            // Disable alternate functions
    GPIO_PORTA_AMSEL_R &= ~0xFC;            // Disable analog
    GPIO_PORTA_PCTL_R &= ~0xFFFFFF00;       // Clear PCTL for PA2�PA7
}

// Pulse EN pin (PA6)
void LCD_EnablePulse(void) {
    GPIO_PORTA_DATA_R |= EN;
    SysTick_Wait_n_us(1);
    GPIO_PORTA_DATA_R &= ~EN;
    SysTick_Wait_n_us(100);
}

// Send 4 bits to PA2�PA5
void LCD_SendNibble(uint8_t nibble) {
    GPIO_PORTA_DATA_R &= ~DATA_MASK;                 // Clear PA2�PA5
    GPIO_PORTA_DATA_R |= (nibble << 2) & DATA_MASK;  // Shift nibble to PA2�PA5
    LCD_EnablePulse();
}

// Send command (RS = 0)
void LCD_Command(uint8_t cmd) {
    GPIO_PORTA_DATA_R &= ~RS;                  // RS = 0 for command
    LCD_SendNibble(cmd >> 4);                  // High nibble
    LCD_SendNibble(cmd & 0x0F);                // Low nibble

    if(cmd < 4)
        SysTick_Wait_n_ms(2);
    else
        SysTick_Wait_n_us(40);
}

// Send character (RS = 1)
void LCD_Char(u8 data) {
    GPIO_PORTA_DATA_R |= RS;                   // RS = 1 for data
    LCD_SendNibble(data >> 4);
    LCD_SendNibble(data & 0x0F);
    SysTick_Wait_n_us(40);
}

// Send string
void LCD_String(char *str) {
    while(*str)
        LCD_Char(*str++);
		SysTick_Wait_n_ms(5);
}
void LCD_Float(float value, u8 precision) {
    char buf[16];
    // formats �value� into buf, e.g. "3.14" if precision==2
    //snprintf(buf, sizeof(buf), "%.*f", precision, value);
	sprintf(buf, "%.*f", precision, value);
    LCD_String(buf);
	SysTick_Wait_n_ms(5);
}
// Set cursor to row, col
void LCD_SetCursor(uint8_t row, uint8_t col) {
    uint8_t pos = (row == 1) ? (0x80 + col) : (0xC0 + col);
    LCD_Command(pos);
}

// Clear screen
void LCD_Clear(void) {
    LCD_Command(0x01);
    SysTick_Wait_n_ms(2);
}

// Initialize LCD
void LCD_Init(void) {
    LCD_GPIO_Init();
    SysTick_Wait_n_ms(20);              // Wait for LCD to power up

    // 4-bit initialization sequence
    GPIO_PORTA_DATA_R &= ~RS;    // RS = 0
    LCD_SendNibble(0x03);
    SysTick_Wait_n_ms(5);
    LCD_SendNibble(0x03);
    SysTick_Wait_n_us(150);
    LCD_SendNibble(0x03);
    SysTick_Wait_n_us(150);
    LCD_SendNibble(0x02);        // Switch to 4-bit mode

    // Now send function set and others
    LCD_Command(0x28);  // 4-bit, 2-line, 5x8 font
    LCD_Command(0x06);  // Increment cursor
    LCD_Command(0x0F);  // Display ON, cursor ON, blink ON
    LCD_Clear();        // Clear display
}


