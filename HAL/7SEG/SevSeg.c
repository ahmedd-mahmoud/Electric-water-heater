/*
 * main.c
 *
 * Created: 12/23/2022 3:29:30 PM
 *  Author: ma407
 */ 

#include "SevSeg_interface.h"

void SEG7_init() {
	//set port direction
	DIO_setPortDir(SEG7_PORT,OUT);
	// set enable direction
	DIO_setPinDir('C',6,OUT);
	DIO_setPinDir('C',7,OUT);
}

void SEG7_display(uint8 val) {
	DIO_setLowNibVal(SEG7_PORT,val%10);
	val/= 10;
	DIO_setHighNibVal(SEG7_PORT,val);
	
}
