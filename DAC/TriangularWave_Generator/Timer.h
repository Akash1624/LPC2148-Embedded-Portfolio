#include<lpc214x.h>
#include<stdint.h>

#define DELAY_1MS 60000 

void Timer0_init_1Ms(uint32_t delay);
void delay(uint32_t delay);

void Timer0_init_1Ms(uint32_t delay){
	T0CTCR = 0x00;
	T0PR = delay - 1;
	T0TCR = 0x02;
}

void delay(uint32_t delay){
	T0TC = 0;
	T0TCR = 0x02;
	T0TCR = 0x01;
	while(T0TC < delay);
	T0TCR = 0x00;
}
