#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_config.h"


//initialize ADC
void ADC_init(ADC_mode mode);
//enables and disables ADC
void ADC_Enable(Bool val);
//set clock with respect to CPU clock
void ADC_setCLK(ADC_CLK clock);
//set voltage reference
void ADC_setRefVoltage(ADC_Ref ref);
//starts conversion at a certain channel
void ADC_start(uint8 channel);
//returns flag value
Bool ADC_getADCFlag();
//returns data after conversion
uint16 ADC_getData();
//stops ADC 
void ADC_stop();
//enables and disables ADC
void ADC_setInterruptEnable(Bool val);
//selects a trigger for ADC while working in auto trigger mode
/*not complete*/
void ADC_selectTrigger();





#endif /* ADC_INTERFACE_H_ */