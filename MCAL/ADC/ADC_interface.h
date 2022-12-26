/*
* ADC.h
*
* Created: 5/27/2022 2:58:55 PM
*  Author: DELL
*/


#ifndef ADC_H_
#define ADC_H_
#include "../DIO/DIO.h"
#include "ADC_config.h"

void ADC_INIT();
uint16 ADC_Read(uint8 ADC_CHANNEL);


#endif /* ADC_H_ */