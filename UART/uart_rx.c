/*
This program rceives the data from another LPC2148 and 
switches on the LED if push button interfaced to that LPC2148 
is pressed.
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
P0.8 -> LED
P0.0 -> TX
P0.1 -> RX

*****************************************************/


#include <lpc214x.h>

void uart_init(void) {
    PINSEL0 |= 0x00000005;  // Enable UART0 Rx and Tx pins
    U0LCR = 0x83;           // 8 bits, no parity, 1 stop bit, DLAB = 1
    U0DLM = 0x00;
    U0DLL = 97;             // Baud rate of 9600
    U0LCR = 0x03;           // DLAB = 0
}

char uart_receive(void) {
    while (!(U0LSR & 0x01)); // Wait until RBR has data
    return U0RBR;            // Return received data
}

void gpio_init(void) {
    IO0DIR |= (1 << 8);      // Set P0.8 as output (LED)
}

void delay(int time){
	int i, j;
	for(i = 0; i < time; i++){
		for(j = 0; j < 6000; j++);
	}
}

int main(void) {
    uart_init();
    gpio_init();
		
    while (1) {

				char received_data = uart_receive();  // Receive data from UART

        if (received_data == '1') {
            IO0SET = (1 << 8);  // Turn on LED
						delay(500);
						IO0CLR = (1 << 8);
        }
    }
}

