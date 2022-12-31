/*
 * main.c
 *
 * Created: 12/26/2022 8:14:25 PM
 *  Author: DELL
 */ 
#define F_CPU 16000000UL

#include "APP/ElectricHeater/ElectricHeater.h"

int main(void)
{
	uint8 current_temp = 0, set_temp = 60;
	
	// init app layer
	ElectricHeater_init();
	
	// store initial set_temp in EEPROM
	storeSetTemp(set_temp);
	
	while(1)		
	{
		// read set_temp stored value from EEPROM
		set_temp = fetchSetTemp();			
			
		//////////////// Normal Mode ///////////////
		// read current_temp
		current_temp = readSensorTemp();
		
		// display current_temp
		displayTemp(current_temp);
		
		// adjust temp by turning on heater or cooler
		adjustTemp(current_temp,set_temp);
		
		
		//////////////// Setting Mode ///////////////
		// display set_temp
		displayTemp(set_temp);
		
		// display set_temp with blinking
		displayOFF();
		_delay_ms(100);
		displayON();
		_delay_ms(100);

		// continuous check on up,down buttons
		if(getBTN_UP_val())
		{
			inc_SetTemp(&set_temp);
			// store value in EEPROM
			storeSetTemp(set_temp);
		}
		_delay_ms(100);
			
		if(getBTN_DOWN_val())
		{
			dec_SetTemp(&set_temp);
			// store value in EEPROM
			storeSetTemp(set_temp);
		}
	}
}

