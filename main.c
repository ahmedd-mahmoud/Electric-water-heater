/*
 * main.c
 *
 * Created: 12/26/2022 8:14:25 PM
 *  Author: DELL
 */ 
#define F_CPU 16000000UL
#include "MCAL/ADC/ADC_interface.h"
#include "MCAL/DIO/DIO.h"
#include "HAL/7SEG/SevSeg_interface.h"

int main(void)
{
	ADC_setRefVoltage(External_Vref);
	ADC_init(single);
	SEG7_init();
	uint32 data = ADC_getData();
	while(1)
	{
		ADC_start(ADC0);
		while(! ADC_getADCFlag());
		data = ADC_getData();
		if(data>495) // upper limit
		{
			data=495;
		}
		if (data<231) // lower limit
		{
			data = 231;
		}
		data *= 155;
		data /= 1024;
		SEG7_display(data);
	}
}