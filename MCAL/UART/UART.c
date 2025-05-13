
#include "../../LIB/TM4C123GH6PM.h"
#include "../../LIB/COMMON_MACROS.h"
#include "../../LIB/TYPE_DEF.h"
#include "UART.h"

// UART1 initialization on Port B (PB0 = RX, PB1 = TX)
void uart_init()
{
    SET_BIT(SYSCTL_RCGCUART_R, 1); // Enable clock for UART1
    SET_BIT(SYSCTL_RCGCGPIO_R, 1); // Enable clock for PORTB

    while ((SYSCTL_PRUART_R & (1 << 1)) == 0);  // Wait until UART1 is ready
    while ((SYSCTL_PRGPIO_R & (1 << 1)) == 0);  // Wait until PORTB is ready

    CLR(UART1_CTL_R, UART_CTL_UARTEN); // Disable UART1 during configuration

    // Set baud rate to 9600 assuming 16 MHz system clock
    UART1_IBRD_R = 104;
    UART1_FBRD_R = 11;

    // Configure line control for 8-bit word length and enable FIFO
    SET(UART1_LCRH_R, UART_LCRH_WLEN_8);
    SET(UART1_LCRH_R, UART_LCRH_FEN);

    // Enable UART1, TX and RX
    SET(UART1_CTL_R, UART_CTL_UARTEN);
    SET(UART1_CTL_R, UART_CTL_TXE);
    SET(UART1_CTL_R, UART_CTL_RXE);

    // Configure GPIO pins PB0 and PB1 for alternate function (UART1)
    GPIO_PORTB_AFSEL_R |= 0x03;  // Enable alt function for PB0, PB1
    GPIO_PORTB_PCTL_R &= ~0x000000FF;  // Clear PCTL bits for PB0, PB1
    GPIO_PORTB_PCTL_R |= (GPIO_PCTL_PB0_U1RX | (GPIO_PCTL_PB1_U1TX << 4));  // Set PCTL for UART1
    SET(GPIO_PORTB_DEN_R, 0x03);  // Digital enable PB0, PB1
    GPIO_PORTB_AMSEL_R &= ~0x03;  // Disable analog on PB0, PB1
}

// CHECK FOR RECEIVED CHARACTER
char uart_ischar_available()
{
    return ((UART1_FR_R & UART_FR_RXFE) == 0);  // 0 means data is available
}

// GET CHARACTER
char uart_getchar()
{
    while ((UART1_FR_R & UART_FR_RXFE) != 0);                              // Wait while RX FIFO is empty
    return (char)(UART1_DR_R & 0xFF);                                      // Mask to get only data bits
}
