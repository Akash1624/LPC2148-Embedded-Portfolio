/*
This program generates Triangle wave
*/
/****************************************************

Submission Details:
Name: K M AKASH
File: DAC file

Clock Settings:
	FOSC	>>	12MHz (onboard)
	PLL		>>	M=5, P=2
	CCLK	>>  60MHz
	PCLK	>>  15MHz 
		
Hardware Setup:-
P0.25 -> Oscilloscope (A)

*****************************************************/
#include "header.h"

// Initialize DAC on P0.25
void initDAC(void) {
    PINSEL1 |= (1 << 19);  // Configure P0.25 as DAC output (bits 18-19 in PINSEL1)
}

