/*
 * main.c
 *
 *  Authors: AHMED MAHMOUD and MOHAMED AMR
 */ 

#define F_CPU 16000000UL

#include "APP/ElectricHeater/ElectricHeater.h"


int main(void)
{
	uint8 current_temp = 0, set_temp = 60;
	
	// init app layer
	ElectricHeater_init();
	
	while(1)		
	{
		// read set_temp stored value from internal EEPROM
		set_temp = fetchSetTemp();			
		
		if(getBTN_ONOFF_val())
		{
			//////////////// Normal Mode ///////////////
			// read current_temp
			current_temp = readSensorTemp();
		
			// display current_temp
			displayTemp(current_temp);
		
			// adjust temp by turning on heater or cooler
			adjustTemp(current_temp,set_temp);
		
			//////////////// Setting Mode ///////////////
			if((getBTN_UP_val() == True) || (getBTN_DOWN_val() == True) )
			{
				settingMode(set_temp);
			}
		}
		else
		{
			// Everything is OFF
			displayOFF();
			HEATER_OFF();
			COOLER_OFF();
			HEATER_LED(LOW);
		}
	}
}





