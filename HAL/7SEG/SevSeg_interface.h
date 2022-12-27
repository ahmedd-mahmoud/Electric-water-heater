/*
 * SevSeg_interface.h
 *
 * Created: 12/26/2022 11:57:07 PM
 *  Author: DELL
 */ 


#ifndef SEVSEG_INTERFACE_H_
#define SEVSEG_INTERFACE_H_

//#define F_CPU 16000000ul
//#include "util/delay.h"
#include <avr/io.h>
#include "../../MCAL/DIO/DIO.h"
// fit for two 7 segs only
// all macros are all caps
#define SEG7_PORT  'B'

void SEG7_init();

void SEG7_display(uint8 val);





#endif /* SEVSEG_INTERFACE_H_ */