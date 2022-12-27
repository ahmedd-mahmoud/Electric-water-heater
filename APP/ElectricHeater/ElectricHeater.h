/*
 * ElectricHeater.h
 *
 * Created: 12/27/2022 4:18:50 PM
 *  Author: DELL
 */ 


#ifndef HEATER_INTERFACE_H_
#define HEATER_INTERFACE_H_
#define F_CPU 16000000UL
#include "util/delay.h"
#include <avr/io.h>
#include "../../HAL/HEATER/HEATER_interface.h"
#include "../../HAL/EEPROM/EEPROM_interface.h"
#include "../../HAL/BUTTON/BUTTON_interface.h"
#include "../../HAL/7SEG/SevSeg_interface.h"
#include "../../MCAL/ADC/ADC_interface.h"


// to initialize heater and cooler
void ElectricHeater_init();

// to heat and cool temp according to set temp
void HeaterCooler();

//displays "temp" on 7seg ++++++++++
void displayTemp();

// to achieve blinking 7seg ++++++++++
void displayON();
void displayOFF();

//reads value in chosen page and memory address "add" +++++++++		
void fetchSetTemp(uint8 page,uint8 add);	

//writes value in chosen page and memory address "add" +++++++++
void saveSetTemp(uint8 page,uint8 add);	

// return avg of 10 temp measurements +++++++++++
uint8 readSensorTemp();

// increases set temp to max 75 when up button pressed +++++++++
void inc_SetTemp();

// decreases set temp to min 35 when down button pressed +++++++++
void dec_SetTemp();		


#endif /* HEATER_INTERFACE_H_ */