/*
* ExINT_prog.h
*
* Created: 4/30/2022 10:55:45 PM
*  Author:  DELL
*/

#include "ExINT_interface.h"


void General_Int_Enable(void){
	SETBIT(SREG,I_BIT);//GIE=1
}

void General_Int_Disable(void){
	CLEARBIT(SREG,I_BIT);//GIE=0
}

void CLOSE_INT0(void){	CLEARBIT(GICR,INT0);}

void CLOSE_INT1(void){	CLEARBIT(GICR,INT1);}

void CLOSE_INT2(void){	CLEARBIT(GICR,INT2);}



void ExINT_SetUp(uint8 INT_PIN, uint8 signal_Mode){

	switch (INT_PIN){
		
		case INT0:
		
		CLEARBIT(DDRD,2);//SET INT0 INPUT PIN
		
		SETBIT(GICR,INT0);//Enable INT0


		
		switch(signal_Mode){
			case IRQ_AT_RISING_EADGE:
			SETBIT(MCUCR,ISC00);
			SETBIT(MCUCR,ISC01);
			//MCUCR= IRQ_AT_RISING_EADGE;
			

			break;

			case IRQ_AT_FALLING_EADGE:

			CLEARBIT(MCUCR,ISC00);
			SETBIT(MCUCR,ISC01);

			break;

			case IRQ_AT_LOW_LEVEL :
			CLEARBIT(MCUCR,ISC00);
			CLEARBIT(MCUCR,ISC01);
			break;

			case IRQ_AT_LOGICAL_CHANGE:
			SETBIT(MCUCR,ISC00);
			CLEARBIT(MCUCR,ISC01);
			break;

		}
		break;

		case INT1:
		
		CLEARBIT(DDRD,3);     //SET INT0 INPUT PIN

		SETBIT(GICR,INT1); //Enable INT0

		switch(signal_Mode){
			case IRQ_AT_RISING_EADGE:
			SETBIT(MCUCR,ISC10);
			SETBIT(MCUCR,ISC11);
			// MCUCR= IRQ_AT_RISING_EADGE<<2;


			break;

			case IRQ_AT_FALLING_EADGE:

			CLEARBIT(MCUCR,ISC10);
			SETBIT(MCUCR,ISC11);

			break;

			case IRQ_AT_LOW_LEVEL :
			CLEARBIT(MCUCR,ISC10);
			CLEARBIT(MCUCR,ISC11);
			break;

			case IRQ_AT_LOGICAL_CHANGE:
			SETBIT(MCUCR,ISC10);
			CLEARBIT(MCUCR,ISC11);
			break;

		}
		break;


		case INT2:
		CLEARBIT(DDRB,2);//SET INT0 INPUT PIN
		SETBIT(GICR,INT2);//Enable INT2
		switch(signal_Mode){
			case IRQ_AT_RISING_EADGE:
			SETBIT(MCUCSR,ISC2);
			break;
			case IRQ_AT_FALLING_EADGE:
			CLEARBIT(MCUCSR,ISC2);
			break;
		}
		break;



	}
	
	
	General_Int_Enable();

}


