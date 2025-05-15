#include "../../LIB/TM4C123GH6PM.h"
#include "SysTick.h"
#include <stdint.h>

void SysTick_Init(void){
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 0x00FFFFFF; 
	NVIC_ST_CURRENT_R = 0; 
	NVIC_ST_CTRL_R = 0x00000005;
}

void SysTick_Wait_n_us(uint32_t n){ 
	NVIC_ST_RELOAD_R = (16*n)-1;
	NVIC_ST_CURRENT_R = 0;
	while((NVIC_ST_CTRL_R&0x00010000)==0){ 
	}
}

void SysTick_Wait_1ms(void){
		SysTick_Wait_n_us(1000); 
}	

void SysTick_Wait_n_ms(uint32_t n){
	unsigned long i;
	for(i=0; i<n; i++){
		SysTick_Wait_1ms(); 
	}
}	

void SysTick_Wait_n_Sec(uint32_t n){
	unsigned int i;
	for(i=0; i<n; i++){
		SysTick_Wait_n_ms(1000);
	}
}
