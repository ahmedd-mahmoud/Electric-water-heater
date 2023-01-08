

#ifndef HEATER_INTERFACE_H_
#define HEATER_INTERFACE_H_

#include <avr/io.h>
#include "util/delay.h"
#include "../../MCAL/DIO/DIO.h"

#define HEATER_COOLER_PORT 'D'
#define HEATER_PIN			0
#define COOLER_PIN			1	
#define HEATER_LED_PIN		2

void HEATER_COOLER_init();

// to control heater and cooler according to measured temp with LED config
void HEATER_ON();
void HEATER_OFF();
void COOLER_ON();
void COOLER_OFF();
void HEATER_LED(uint8 val);


#endif /* HEATER_INTERFACE_H_ */