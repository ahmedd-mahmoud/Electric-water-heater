/*
 * main.c
 *
 * Created: 12/26/2022 8:14:25 PM
 *  Author: DELL
 */ 

#include "APP/ElectricHeater/ElectricHeater.h"
#include "HAL/BUTTON/BUTTON_interface.h"

int main(void)
{
	uint8 current_temp = 0, set_temp = 60;
	set_temp = fetchSetTemp();
	ElectricHeater_init();
	BTNS_init();
	// setting mode flow
	while(1)
	{
	
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
//////////////// Normal Mode ///////////////
/*
int main(void)
{
	uint8 current_temp = 0, set_temp = 60;
	//normal mode flow
	// init app layer
	ElectricHeater_init();
	// read set_temp stored value from eeprom
	/ *set_temp = fetchSetTemp();* /
	// read current_temp

	while(1)
	{
		current_temp = readSensorTemp();
		// display
		displayTemp(current_temp);
		// adjust temp by turning on headter or cooler
		adjustTemp(current_temp,set_temp);

	}
}*/