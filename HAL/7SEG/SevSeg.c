/*
 * main.c
 *
 * Created: 12/23/2022 3:29:30 PM
 *  Author: ma407
 */ 

#include "SevSeg_interface.h"

void SEG7_init() {
	// set port direction
	DIO_setPortDir(SEG7_PORT,OUT);
	// set enable direction
	DIO_setPinDir(SEG7_EN_PORT,SEG7_EN1_PIN,OUT);
	DIO_setPinDir(SEG7_EN_PORT,SEG7_EN2_PIN,OUT);
	SEG7_setEnable(False,False);
}

void SEG7_setEnable(Bool EN1_state,Bool EN2_state) {
	DIO_setPinVal(SEG7_EN_PORT,SEG7_EN1_PIN,EN1_state);
	DIO_setPinVal(SEG7_EN_PORT,SEG7_EN2_PIN,EN2_state);
}

void SEG7_display(uint16 val) {
	DIO_setLowNibVal(SEG7_PORT,val%10); // First digit
	val/= 10;
	DIO_setHighNibVal(SEG7_PORT,val); // Second digit
}
