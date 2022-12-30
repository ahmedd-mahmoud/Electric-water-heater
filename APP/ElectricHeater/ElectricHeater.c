/*
 * ElectricHeater.c
 *
 * Created: 12/27/2022 4:19:29 PM
 *  Author: DELL
 */ 

#include "ElectricHeater.h"

void ElectricHeater_init()
{
/*	BUTTON_INIT();*/ // buttons not reusable
	SEG7_init();
	// ADC init's
	ADC_setRefVoltage(External_Vref);
	ADC_init(single);
	// Heater cooler init
	HEATER_COOLER_init();

}

uint16 readSensorTemp()
{
	uint32 result = 0;
	for (uint8 i=0;i<10;i++)
	{
		ADC_start(ADC7);
		while(!ADC_getADCFlag()); // wait until done
		result +=  ADC_getData(); // accumulate 10 readings
		_delay_ms(10);				// time between samples (should be 100ms irl)
	}
	result/=10;
	result = (result*155)/1024;
	
	// reject three digits and negative
	if (result>=99)
	{
		result=99;
	}
	
	if (result <= 0)
	{
		result = 0;
	}
	
	return result;		// avg of 10 sensor readings
}

void adjustTemp(uint8 current_value,uint8 set_value)
{
	if((set_value - current_value) > 5)
	{
		// heater on
		COOLER_OFF();
		HEATER_ON();
	}
	else if((current_value - set_value) > 5)
	{
		// cooler on
		HEATER_OFF();
		COOLER_ON();
	}
	else
	{
		// do nothing
		HEATER_OFF();
		COOLER_OFF();
	}
}

uint8 fetchSetTemp()
{
	return eeprom_read_byte((const uint8*)TEMP_EEPROM_ADDRESS);
}

void storeSetTemp(uint8 value)
{
	eeprom_write_byte((uint8*)TEMP_EEPROM_ADDRESS,value);
}

// Review This				// fixed port and pin
void displayON()
{
	DIO_setPinVal(SEG7_EN_PORT,SEG7_EN1_PIN,HIGH);
	DIO_setPinVal(SEG7_EN_PORT,SEG7_EN2_PIN,HIGH);
}
void displayOFF()
{
	DIO_setPinVal(SEG7_EN_PORT,SEG7_EN1_PIN,LOW);
	DIO_setPinVal(SEG7_EN_PORT,SEG7_EN2_PIN,LOW);
}


void inc_SetTemp(uint8 *value)
{
	if((*value)+5>75)		// Max set temp is 75
	{
		// stay the same
	}
	else 
	{
		(*value)+=5;
	}
	
}


void dec_SetTemp(uint8 *value)
{
	if((*value)-5<35)		// Max set temp is 75
	{
		// stay the same
	}
	else
	{
		(*value)-=5;
	}
	
}

void displayTemp(uint32 temp)
{
	SEG7_display(temp);
}

