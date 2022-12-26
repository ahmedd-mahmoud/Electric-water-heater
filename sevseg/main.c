/*
 * main.c
 *
 * Created: 12/23/2022 3:29:30 PM
 *  Author: ma407
 */ 
#define fcpu 16000000ul
#include "util/delay.h"
#include <xc.h>
#include "Dep/DIO/DIO.h"
// fit for two 7 segs only
// all macros are all caps
#define SEG7_PORT  'C'

void SEG7_init() {
	//set port direction
	DIO_setPortDir(SEG7_PORT,OUT);
}

void SEG7_display(uint8 val) {
	DIO_setLowNibVal(SEG7_PORT,val%10);
	val/= 10;
	DIO_setHighNibVal(SEG7_PORT,val);
	
}
void HEATER_ON()
{

	DIO_setPinDir('D',0,OUT);
	DIO_setPinVal('D',0,HIGH);	
}
void HEATER_OFF()
{

	DIO_setPinDir('D',0,OUT);
	DIO_setPinVal('D',0,LOW);
}
void COOLER_ON()
{
	DIO_setPinDir('D',1,OUT);
	DIO_setPinVal('D',1,HIGH);	
}
void COOLER_OFF()
{
	DIO_setPinDir('D',1,OUT);
	DIO_setPinVal('D',1,LOW);	
}
int main(void)
{
	HEATER_ON();
	COOLER_OFF();
	SEG7_init();
	SEG7_display(75);
	DIO_setPinDir('B',0,OUT);
	DIO_setPinDir('B',1,OUT);
	
	
	
    while(1)
    {
        //TODO:: Please write your application code 
		DIO_setPinVal('B',0,LOW);
		DIO_setPinVal('B',1,LOW);
		_delay_ms(100);
	}
}