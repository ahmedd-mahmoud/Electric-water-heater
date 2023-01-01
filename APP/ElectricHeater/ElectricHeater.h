/*
 * ElectricHeater.h
 *
 * Created: 12/27/2022 4:18:50 PM
 *  Author: DELL
 */ 


#ifndef ELECTRICHEATER_H_
#define ELECTRICHEATER_H_
#define F_CPU 16000000UL
#include "util/delay.h"
#include <avr/io.h>
#include "../../HAL/HEATER/HEATER_interface.h"
#include "avr/eeprom.h"
#include "../../HAL/BUTTON/BUTTON_interface.h"
#include "../../HAL/7SEG/SevSeg_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"

#define TEMP_EEPROM_ADDRESS 69

// to initialize heater and cooler
void ElectricHeater_init();

// to heat and cool temp according to set temp
void adjustTemp(uint8 current_value,uint8 set_value);

//displays "temp" on 7seg
void displayTemp(uint32 temp);

// to achieve blinking 7seg
void displayON();
void displayOFF();

// store data in EEPROM	
uint8 fetchSetTemp();
void storeSetTemp(uint8 value);

// return avg of 10 temp measurements
uint16 readSensorTemp();

// increases set temp to max 75 when up button pressed	
void inc_SetTemp(uint8 *value);

// decreases set temp to min 35 when down button pressed
void dec_SetTemp(uint8 *value);		

// enter setting mode
void settingMode(uint8 set_temp);

#endif /* HEATER_INTERFACE_H_ */