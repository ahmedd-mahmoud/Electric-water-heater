/*
 * BUTTON_interface.h
 *
 * Created: 10/1/2022 8:42:19 PM
 *  Author: DELL
 */ 


#ifndef BUTTON_INTERFACE_H_
#define BUTTON_INTERFACE_H_

//#define F_CPU 16000000UL
#include "util/delay.h"
#include "../../MCAL/DIO/DIO.h"

#define ONOFF_BUT  0
#define UP_BUT  1
#define DOWN_BUT  2

#define PRESSED  1
#define RELEASED 0

void BUTTON_INIT();
uint8 BUTTON_GET (uint8 button_mode);



#endif /* BUTTON_INTERFACE_H_ */