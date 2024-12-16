/*
This program generates Sine Wave
*/
/****************************************************

Submission Details:
Name: K M AKASH, RAKESH SG, ASHWINI JAYSHETTY
Reg No: 241039022, 241039034, 241039021
Branch: Embedded Systems
File: DAC file

Clock Settings:
	FOSC	>>	12MHz (onboard)
	PLL		>>	M=5, P=2
	CCLK	>>  60MHz
	PCLK	>>  15MHz 
		
Hardware Setup:-
P0.25 -> Oscilloscope (A)

*****************************************************/

#include "header.h"   // Include the header for function declarations

// Initialize DAC on P0.25
void initDAC(void) {
    PINSEL1 |= (1 << 19);  // Configure P0.25 as DAC output (bits 18-19 in PINSEL1)
}

