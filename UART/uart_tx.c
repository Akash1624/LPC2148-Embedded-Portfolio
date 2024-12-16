/*
This program transmits the data to second LPC2148 via UART
is the Push button interfaced to this LPC2148 is pressed.
*/
/****************************************************

Submission Details:
Name: K M AKASH
File: UART Communication between Two LPC2148

Clock Settings:
	FOSC	>>	12MHz (onboard)
	PLL		>>	M=5, P=2
	CCLK	>>  60MHz
	PCLK	>>  15MHz 
		
Hardware Setup:-
P0.10 -> PUSH BUTTON
P0.0 -> TX
P0.1 -> RX

*****************************************************/

#include <lpc214x.h>

void uart_init(void) {
    PINSEL0 |= 0x00000005;  // Enable UART0 Rx and Tx pins (P0.0 -> TX, P0.1 -> RX)
    U0LCR = 0x83;           // 8 bits, no parity, 1 stop bit, DLAB = 1
    U0DLM = 0x00;
    U0DLL = 97;             // Baud rate of 9600
    U0LCR = 0x03;           // DLAB = 0, ready to transmit/receive
}

void uart_transmit(char data) {
    while (!(U0LSR & 0x20)); // Wait for THR to be empty
    U0THR = data;            // Transmit data
}

void gpio_init(void) {
    IO0DIR &= ~(1 << 10);    // Set P0.10 as input (push button)
}

int main(void) {
    uart_init();
    gpio_init();

    while (1) {
        if (!(IO0PIN & (1 << 10))) {  // If button pressed (active-low)
            uart_transmit('1');       // Send '1' to the receiver
            while (!(IO0PIN & (1 << 10)));  // Debounce: Wait for button release
        }
    }
}
