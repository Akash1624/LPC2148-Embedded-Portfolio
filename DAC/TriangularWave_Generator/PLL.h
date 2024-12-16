#include <LPC214X.H>
#include <stdint.h>

#define PLL0 	0 
#define PLL0_60MHz_pclk_60MHz_cclk		60000000

void PLL_init(uint32_t clock){
	PLL0CON |= 0x01;
	PLL0CFG |= 0x24;
	PLL0FEED = 0xAA;
	PLL0FEED = 0x55;
	while((PLL0STAT & 0x400) == 0);
	PLL0CON = 0x03;
	PLL0FEED = 0xAA;
	PLL0FEED = 0x55;

	VPBDIV = 0x01;
}
