/*
 * ElectricHeater.c
 *
 * Created: 12/27/2022 4:19:29 PM
 *  Author: DELL
 */ 

#include "ElectricHeater.h"

void ElectricHeater_init()
{
	// Buttons init
	BTNS_init();
	// Seven Segment init
	SEG7_init();
	// ADC inits
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

void settingMode(uint8 set_temp)
{
	for(int i=0;i<20;i++)     // assuming i++ takes on tick and tick is 250 ms
	{
		// display set_temp
		displayTemp(set_temp);
		
		/* to achieve blinking every 1 second*/
		// display on
		displayON();
		// delay
		_delay_ms(500);
		// display off
		displayOFF();
		// delay
		_delay_ms(500);
		
		if(getBTN_UP_val())
		{
			// inc set_temp
			inc_SetTemp(&set_temp);
			// store new set_temp
			storeSetTemp(set_temp);
			// reset counter
			i = 0;
		}
		
		//_delay_ms(100);
		
		if(getBTN_DOWN_val())
		{
			// dec set_temp
			dec_SetTemp(&set_temp);
			// store new set_temp
			storeSetTemp(set_temp);
			// reset counter
			i = 0;
		}
	}
}