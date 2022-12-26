/*
 * ExINT_interface.h
 *
 * Created: 4/30/2022 10:55:32 PM
 *  Author: DELL
 */ 


#ifndef EXINT_INTERFACE_H_
#define EXINT_INTERFACE_H_

#include "ExINT_config.h"
#include "avr/io.h"
#include <avr/interrupt.h>
#include "../../BitMath.h"
#include "../../MyTypes.h"
/*
//----Signal Mode----
 1) IRQ_AT_RISING_EADGE    
 2) IRQ_AT_FALLING_EADGE   
 3) IRQ_AT_LOW_LEVEL       
 4) IRQ_AT_LOGICAL_CHANGE  
*/



void ExINT_SetUp(uint8 INT_PIN, uint8 signal_Mode);

void General_Int_Enable(void);
void General_Int_Disable(void);

void CLOSE_INT0(void);
void CLOSE_INT1(void);
void CLOSE_INT2(void);



#endif /* EXINT_INTERFACE_H_ */