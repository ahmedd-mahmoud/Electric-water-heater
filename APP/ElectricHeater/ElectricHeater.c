/*
 * ElectricHeater.c
 *
 * Created: 12/27/2022 4:19:29 PM
 *  Author: DELL
 */ 

#include "ElectricHeater.h"

uint8 set_temp = 60;

void ElectricHeater_init()
{
	BUTTON_INIT();
	SEG7_init();
	ADC_init(single);
	EEPROM_init();
	HEATER_init();
}

uint8 readSensorTemp()		// Review this
{
	uint8 i = 1, sum = 0;
	while(i <= 10)
	{	
		ADC_start(7);
		sum = sum + ADC_getData();
		i++;
		_delay_ms(10);
	}
	return (sum/i);		// avg of 10 sensor readings
}
void HeaterCooler()
{
	if(set_temp > readSensorTemp())
	{
		COOLER_OFF();
		HEATER_ON();
	}
	else if(set_temp < readSensorTemp())
	{
		HEATER_OFF();
		COOLER_ON();
	}
	else
	{
		HEATER_OFF();
		COOLER_OFF();
	}
}

void fetchSetTemp(uint8 page,uint8 add)
{
	set_temp = EEPROM_ReadByte(page,add);
}

void saveSetTemp(uint8 page,uint8 add)
{
	EEPROM_WriteByte(page,add,set_temp);
}

// Review This				// Two enables blinking
void displayON()
{
	DIO_setPinVal('C',6,HIGH);
	DIO_setPinVal('C',7,HIGH);
}
void displayOFF()
{
	DIO_setPinVal('C',6,HIGH);
	DIO_setPinVal('C',7,HIGH);
}

void inc_SetTemp()
{
	if(set_temp <= 70)		// Max set temp is 75
	{
		if(BUTTON_GET(UP_BUT))
		{
			set_temp += 5;
		}
	}
	
}


void dec_SetTemp()
{
	if(set_temp >= 40 )			// Min set temp is 35
	{
		if(BUTTON_GET(DOWN_BUT))
		{
				set_temp -= 5;
		}
	}
	
}

void displayTemp()
{
	uint8 temp = readSensorTemp();
	SEG7_display(temp);
}

