/*
This program turns on the LEDs serially on Push button
press.
*/
/************************************************

Submission Details:
Name: K M AKASH
File: LED & Push Button Interfacing to LPC2148

Clock Settings:
	FOSC	>>	12MHz (onboard)
	PLL		>>	M=5, P=2
	CCLK	>>  60MHz
	PCLK	>>  15MHz 
		
Hardware Setup:-
P0.10 - LED 1
P0.11 - LED 2
P0.12 - LED 3
P0.9 - PUSH BUTTON


**************************************************/


#include <lpc214x.h>
#include "Timer.h"
#include "PLL.h"


int main(void)
{
		// Timer Initialisation
		PLL_init(PLL0,PLL0_60MHz_pclk_60MHz_cclk);
		Timer0_init_1sec(DELAY_1MS);
    
		// Configure P0.10, P0.11, and P0.12 as Output (LED control)
    IO0DIR |= (1 << 10) | (1 << 11) | (1 << 12);
    
    // Configure P0.9 as Input (Switch input)
    IO0DIR &= ~(1 << 7);
	
		IO0DIR &= ~(1 << 8);
		
		IO0DIR &= ~(1 << 9);

    while(1)
    { 
        // Read the state of P0.9
        if (!(IO0PIN & (1 << 7))) // Switch pressed (assuming active low)
        {
            // Turn LEDs OFF
          IO0SET = (1 << 10);
					delay(100);
					IO0CLR = (1 << 10);
        }
				else if(!(IO0PIN &(1<<8))){
					IO0SET = ( 1 << 11);
					delay(100);
					IO0CLR = ( 1 << 11);
				}
        else if (!(IO0PIN & (1<<9))){
					IO0SET = (1 << 12);
					delay(100);
					IO0CLR = (1 << 12);
        }
    }
}
