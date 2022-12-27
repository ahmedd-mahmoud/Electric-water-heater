#include "ADC_interface.h"

void ADC_init(ADC_mode mode)
{
	if (mode==freeRunning)
	{
		ADC_Enable(True);
		ADC_setCLK(CLK128);
		ADC_setRefVoltage(Vcc);
		ADC_setInterruptEnable(True);
	}
	else if (mode == autoTrigger)
	{
		//this mode is not complete
		ADC_Enable(True);
		SETBIT(ADCSRA,ADATE);
		ADC_setCLK(CLK128);
		ADC_setRefVoltage(Vcc);
		ADC_setInterruptEnable(True);		
	}
	else //default is single mode
	{
		ADC_Enable(True);
		ADC_setCLK(CLK128);
		ADC_setRefVoltage(Vcc);
		ADC_setInterruptEnable(False);
		
	}
}

void ADC_Enable(Bool val)
{
	ASSIBIT(ADCSRA,ADEN,val);
}

void ADC_setCLK(ADC_CLK clock)
{
	//config clock
	if(clock  == CLK2)
	{

		CLEARBIT(ADCSRA,ADPS2);
		CLEARBIT(ADCSRA,ADPS1);
		SETBIT(ADCSRA,ADPS0);
	}

	else if(clock  == CLK4)
	{
		CLEARBIT(ADCSRA,ADPS2);
		SETBIT(ADCSRA,ADPS1);
		CLEARBIT(ADCSRA,ADPS0);
	}
	else if(clock  == CLK8)
	{
		CLEARBIT(ADCSRA,ADPS2);
		SETBIT(ADCSRA,ADPS1);
		SETBIT(ADCSRA,ADPS0);
	}
	else if(clock  == CLK16)
	{
		SETBIT(ADCSRA,ADPS2);
		CLEARBIT(ADCSRA,ADPS1);
		CLEARBIT(ADCSRA,ADPS0);
	}
	else if(clock  == CLK32)
	{
		SETBIT(ADCSRA,ADPS2);
		CLEARBIT(ADCSRA,ADPS1);
		SETBIT(ADCSRA,ADPS0);
	}
	else if(clock  == CLK64)
	{
		SETBIT(ADCSRA,ADPS2);
		SETBIT(ADCSRA,ADPS1);
		CLEARBIT(ADCSRA,ADPS0);
	}
	else //default CLK 128
	{
		SETBIT(ADCSRA,ADPS2);
		SETBIT(ADCSRA,ADPS1);
		SETBIT(ADCSRA,ADPS0);
	}


}

void ADC_setRefVoltage(ADC_Ref ref)
{
	if(ref == External_Vref)
	{
		CLEARBIT(ADMUX,REFS1);
		CLEARBIT(ADMUX,REFS0);
	}
	else if (ref == Internal_Vref)
	{
		SETBIT(ADMUX,REFS1);
		SETBIT(ADMUX,REFS0);
	}
	else // default reference is Vcc
	{
		CLEARBIT(ADMUX,REFS1);
		SETBIT(ADMUX,REFS0);
	}

}

void ADC_start(uint8 channel)
{
	
	CLEARBIT(DDRA,channel);
	//select channel
	ADMUX|=channel;
	//stats ADC
	SETBIT(ADCSRA,ADSC);
	
}

Bool ADC_getADCFlag()
{
	return CHECKBIT(ADCSRA,ADIF);
}

uint16 ADC_getData()
{
	uint16 data=0;
	data+=ADCL;
	data+=ADCH<<8;
	return data;
}

void ADC_stop()
{
	//stop ADC
	CLEARBIT(ADCSRA,ADSC);
	
}

void ADC_setInterruptEnable(Bool val)
{
	ASSIBIT(ADCSRA,ADIE,val);
}
