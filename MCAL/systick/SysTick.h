#include <stdint.h>
#define FREQ 16000000 //frequency = 16 MHZ

void SysTick_Init(void); // resetting the SysTick

void SysTick_Wait_n_us(uint32_t n); //delay for n micro secs
	
void SysTick_Wait_1ms(void); // delay of 1 milli sec

void SysTick_Wait_n_ms(uint32_t n); // delay for n milli secs

void SysTick_Wait_n_Sec (uint32_t n); // delay for n seconds 


