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

#define BTNS_PORT		'A'
#define BTN_ONOFF_PIN	 0
#define BTN_UP_PIN		 1
#define BTN_DOWN_PIN	 2


void BTNS_init();
uint8 getBTN_UP_val();
uint8 getBTN_DOWN_val();
uint8 getBTN_ONOFF_val();




#endif /* BUTTON_INTERFACE_H_ */