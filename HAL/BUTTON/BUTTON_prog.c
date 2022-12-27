/*
 * BUTTON_prog.c
 *
 * Created: 10/1/2022 8:41:11 PM
 *  Author: DELL
 */ 


#include "BUTTON_interface.h"


void BUTTON_INIT()
{
	DIO_setPinDir('A',ONOFF_BUT,IN);	// ON/OFF button input pin

	DIO_setPinDir('A',UP_BUT,IN);		// UP button input pin
	
	DIO_setPinDir('A',DOWN_BUT,IN);		// DOWN button input pin
}

uint8 BUTTON_GET(uint8 button_mode)
{
	if(button_mode > 2 || button_mode < 0)
	{
		button_mode = 0;
	}
	switch(button_mode) 
	{
		case ONOFF_BUT :
		if (DIO_getPinVal('A',ONOFF_BUT))
		{
			_delay_ms(25);
			if (DIO_getPinVal('A',ONOFF_BUT)) {return PRESSED;}
		}
		else {return RELEASED;}
	
		case UP_BUT :
		if (DIO_getPinVal('A',UP_BUT))
		{
			_delay_ms(25);
			if (DIO_getPinVal('A',UP_BUT)) {return PRESSED;}
		}
		else {return RELEASED;}
		
		case DOWN_BUT :
		if (DIO_getPinVal('A',DOWN_BUT))
		{
			_delay_ms(25);
			if (DIO_getPinVal('A',DOWN_BUT)) {return PRESSED;}
		}
		else {return RELEASED;}
	}
}