/*
* ADC.c
*
* Created: 5/27/2022 2:58:30 PM
*  Author: DELL
*/

#include "ADC_interface.h"


void ADC_INIT(){
	
	#if VOLTAGE_REFERENCE == AREF
	CLEARBIT(ADMUX,REFS0);
	CLEARBIT(ADMUX,REFS1);
	#elif  VOLTAGE_REFERENCE == AVCC
	SETBIT(ADMUX,REFS0);
	CLEARBIT(ADMUX,REFS1);
	#elif  VOLTAGE_REFERENCE == Internal_2_56V
	SETBIT(ADMUX,REFS0);
	SETBIT(ADMUX,REFS1);
	#endif

	
	
	/*Right ADJUST*/
	CLEARBIT(ADMUX, ADLAR);
	
	/*128 Pre-scaler*/
	SETBIT(ADCSRA,ADPS0);
	SETBIT(ADCSRA,ADPS1);
	SETBIT(ADCSRA,ADPS2);
	
	/*Conversion Mode: AutoTrigger/FreeRunning*/
	SETBIT(ADCSRA, ADATE);
	
	SFIOR = (AUTO_TRIGGER_MODE << 5)| (SFIOR & 0x0F);
	/*ADC peripheral Enable*/
	SETBIT(ADCSRA,ADEN);
	/*ADC peripheral interrupt Enable*/
	SETBIT(ADCSRA,ADIE);
	
}


uint16 ADC_Read(uint8 ADC_CHANNEL)
{
	/*Channel select*/
	CLEARBIT(DDRA,ADC_CHANNEL);
	
	ADMUX = ADC_CHANNEL | (ADMUX & 0xE0);
	/*Start of conversion*/
	SETBIT(ADCSRA, ADSC);
	/*End of conversion Polling*/
	while(!(CHECKBIT(ADCSRA, ADIF)));
	/*Converted digital output*/
	return ADC;
}