/*
This program will display a message on 16x2
LCD Module
*/
/****************************************

Submission Details:
Name: K M AKASH
File: LCD Interfacing to LPC2148
Board 		: arm 7
Processor 	: LPC2148

Clock Settings:
	FOSC : 12MHZ
	PLL  : M=5, P=2
	CCLK : 60MHZ
	PCLK : 12MHZ

Hardware Setup:
LCD -> P0.4, P0.5, P0.6, P0.8, P0.9, P0.10, P0.11, P0.12, P0.13, P0.14, P0.15

****************************************/

#include <lpc214x.h>
#include <stdint.h>
#include "Timer.h"
#include "PLL.h"

#define EN_PIN 0x00000040
#define RS_PIN 0x00000010
#define RW_PIN 0x00000020
#define DATA_MASK 0xFFFF00FF

void LCD_WRITE(unsigned int data, unsigned int is_command) {
    if (is_command) {
        IO0CLR = RS_PIN; // RS = 0 for command
    } else {
        IO0SET = RS_PIN; // RS = 1 for data
    }
    IO0PIN = ((IO0PIN & DATA_MASK) | (data << 8));
    IO0SET = EN_PIN; // EN = 1
    delay(20);
    IO0CLR = EN_PIN; // EN = 0
    delay(40);
}

void LCD_INIT(void) {
    IO0DIR = 0x0000FFF0; // Set direction for data and control lines
    delay(200);
    LCD_WRITE(0x38, 1);  // Initialize LCD
    LCD_WRITE(0x0C, 1);  // Display on, cursor off
    LCD_WRITE(0x06, 1);  // Auto increment cursor
    LCD_WRITE(0x01, 1);  // Clear display
    LCD_WRITE(0x80, 1);  // Set cursor to first line, first position
}

void LCD_STRING(const char* msg) {
    while (*msg) {
        LCD_WRITE(*msg++, 0); // Send each character as data
    }
}

int main(void) {
		
		// Timer Initialisation
		PLL_init(PLL0,PLL0_60MHz_pclk_60MHz_cclk);
	  Timer0_init_1us(DELAY_1MS);
	  
		// Initialising LCD
		LCD_INIT();
	
		// Printing the string
    LCD_STRING("Hi ! Welcome");
    LCD_WRITE(0xC0, 1); // Move to second line
    LCD_STRING("Good Day!");
    return 0;
}
