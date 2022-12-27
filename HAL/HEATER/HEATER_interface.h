/*
 * HEATER_interface.h
 *
 * Created: 12/27/2022 4:18:50 PM
 *  Author: DELL
 */ 


#ifndef HEATER_INTERFACE_H_
#define HEATER_INTERFACE_H_

#include <avr/io.h>
#include "../../MCAL/DIO/DIO.h"


void HEATER_init();

// to control heater and cooler according to measured temp with LED config
void HEATER_ON();
void HEATER_OFF();
void COOLER_ON();
void COOLER_OFF();




#endif /* HEATER_INTERFACE_H_ */