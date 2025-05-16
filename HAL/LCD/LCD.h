#include "../../LIB/TYPE_DEF.h"
#ifndef LCD_H
#define LCD_H

// Pin bit masks
#define RS 0x80    // PA7
#define EN 0x40    // PA6
#define DATA_MASK 0x3C  // PA2�PA5

void LCD_Init(void);
void LCD_Command(unsigned char cmd);
void LCD_Char(unsigned char data);
void LCD_String(char *str);
void LCD_Float(float value, u8 precision);
void LCD_Clear(void);
void LCD_SetCursor(unsigned char row, unsigned char col);
void delayMs(int n);

#endif
