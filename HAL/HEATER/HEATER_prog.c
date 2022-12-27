/*
 * HEATER_prog.c
 *
 * Created: 12/27/2022 4:19:29 PM
 *  Author: DELL
 */ 

#include "HEATER_interface.h"

void HEATER_init()
{
		DIO_setPinDir('D',0,OUT);
		DIO_setPinDir('D',1,OUT);
		DIO_setPinDir('D',2,OUT);	//LED direction
}

void HEATER_ON()
{
	DIO_setPinVal('D',0,HIGH);
	
	// LED blinking
	TOGGLE(PORTD,2);
	_delay_ms(20);
}

void HEATER_OFF()
{
	DIO_setPinVal('D',0,LOW);	
	// LED OFF
	DIO_setPinVal('D',2,LOW);
}

void COOLER_ON()
{
	DIO_setPinVal('D',1,HIGH);
	// LED ON
	DIO_setPinVal('D',2,HIGH);
}
void COOLER_OFF()
{
	DIO_setPinVal('D',1,LOW);
	// LED OFF
	DIO_setPinVal('D',2,LOW);
}


