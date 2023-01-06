#include "Timer_8.h"

Bool timer_getOVF(Timer_8 t)
{
	return CHECKBIT(TIFR,TOV0);
}



void timer_init_8(Timer_8 t,TimerMode8 m)
{
	if (m==normal)
	{
		if (t==TIM0)
		{
			//diable overflow interrupt
			CLEARBIT(TIMSK,TOIE0);
			//setting wave form
			CLEARBIT(TCCR0,WGM00);
			CLEARBIT(TCCR0,WGM01);			
		} 
		else //Timer 2 is the default timer
		{
			//enable overflow interrupt
			SETBIT(TIMSK,TOIE2);
			//setting waveform
			CLEARBIT(TCCR2,WGM20);
			CLEARBIT(TCCR2,WGM21);
		}
	}
	else if (m==CTC)
	{
		
		if (t==TIM0)
		{	
			//enable compare interrupt
			SETBIT(TIMSK,OCIE0);
			//setting waveform
			CLEARBIT(TCCR0,WGM00);
			SETBIT(TCCR0,WGM01);
			
		}
		else //Timer 2 is the default timer
		{	
			//enable compare interrupt
			SETBIT(TIMSK,OCIE2);
			//setting waveform
			CLEARBIT(TCCR2,WGM20);
			SETBIT(TCCR2,WGM21);
		}
	}
	else if (m==PWM)
	{
		
		if (t==TIM0)
		{
			//setting waveform
			SETBIT(TCCR0,WGM00);
			CLEARBIT(TCCR0,WGM01);
			//default  duty cycle 50%
			OCR0=127;
			//default PWM is non-inverting
			timer_setCOM_8(t,clearOnMatch);

		}
		else //Timer 2 is the default timer
		{
			//setting waveform
			SETBIT(TCCR2,WGM20);
			CLEARBIT(TCCR2,WGM21);
			//default  duty cycle 50%
			OCR2=127;
			//default PWM is non-inverting
			timer_setCOM_8(t,clearOnMatch);
		}
	}
	else if (m==FastPWM)
	{
		
		if (t==TIM0)
		{
			//setting waveform
			SETBIT(TCCR0,WGM00);
			SETBIT(TCCR0,WGM01);
			//default  duty cycle 50%
			OCR0=127;
			//default PWM is non-inverting
			timer_setCOM_8(t,clearOnMatch);
			
		}
		else //Timer 2 is the default timer
		{
			//setting waveform
			SETBIT(TCCR2,WGM20);
			SETBIT(TCCR2,WGM21);
			//default  duty cycle 50%
			OCR2=127;
			////default PWM is non-inverting
			timer_setCOM_8(t,clearOnMatch);
		}
	}
}

void timer_setInterruptEnable_8(Timer_8 t,INTERUPT I,Bool val)
{
	if (t==TIM0)
	{
		if (I==COMA||I==COMB)//since timer_8 only has one comparator
		{
			ASSIBIT(TIMSK,OCIE0,val);
		}
		else//default  
		{
			ASSIBIT(TIMSK,TOIE0,val);
		}
	}
	else //Timer 2 is the default timer
	{
		if (I==COMA||I==COMB)//since timer_8 only has one comparator
		{
			ASSIBIT(TIMSK,OCIE2,val);
		}
		else//default
		{
			ASSIBIT(TIMSK,TOIE2,val);
		}	
	}
}

void timer_setCOM_8(Timer_8 t,COMMode m)
{
	if (t==TIM0)
	{
		if (m==clearOnMatch)
		{
			CLEARBIT(TCCR0,COM00);
			SETBIT(TCCR0,COM01);
		}
		else if (m==setOnMatch)
		{
			SETBIT(TCCR0,COM00);
			SETBIT(TCCR0,COM01);
		}
		else if (m==toggOnMatch)//reserved in PWM modes
		{
			SETBIT(TCCR0,COM00);
			CLEARBIT(TCCR0,COM01);
		}
		else//disconnect is the default mode
		{
			CLEARBIT(TCCR0,COM00);
			CLEARBIT(TCCR0,COM01);
		}
	}
	else //default timer 2
	{
		if (m==clearOnMatch)
		{
			CLEARBIT(TCCR2,COM20);
			SETBIT(TCCR2,COM21);
		}
		else if (m==setOnMatch)
		{
			SETBIT(TCCR2,COM20);
			SETBIT(TCCR2,COM21);
		}
		else if (m==toggOnMatch)//reserved in PWM modes
		{
			SETBIT(TCCR2,COM20);
			CLEARBIT(TCCR2,COM21);
		}
		else//disconnect is the default mode
		{
			CLEARBIT(TCCR2,COM20);
			CLEARBIT(TCCR2,COM21);
		}
	}
}

void timer_load_8(Timer_8 t,uint8 val)
{
		if (t==TIM0)
		{
			TCNT0 = val;
		}
		else //Timer 2 is the default timer
		{
			CLEARBIT(TCCR2,WGM20);
			SETBIT(TCCR2,WGM21);
		}
}

void timer_CLKS_8(Timer_8 t,CLK clock)
{
	if (clock==TIMER_CLK1)
	{
		if (t==TIM0)
		{
			SETBIT(TCCR0,CS00);
			CLEARBIT(TCCR0,CS01);
			CLEARBIT(TCCR0,CS02);
		}
		else //Timer 2 is the default timer
		{
			SETBIT(TCCR2,CS20);
			CLEARBIT(TCCR2,CS21);
			CLEARBIT(TCCR2,CS22);
		}
	}
	else if (clock==TIMER_CLK8)
	{
		if (t==TIM0)
		{
			CLEARBIT(TCCR0,CS00);
			SETBIT(TCCR0,CS01);
			CLEARBIT(TCCR0,CS02);
		}
		else //Timer 2 is the default timer
		{
			CLEARBIT(TCCR2,CS20);
			SETBIT(TCCR2,CS21);
			CLEARBIT(TCCR2,CS22);
		}
	}
	else if (clock==TIMER_CLK64)
	{
		if (t==TIM0)
		{
			SETBIT(TCCR0,CS00);
			SETBIT(TCCR0,CS01);
			CLEARBIT(TCCR0,CS02);
		}
		else //Timer 2 is the default timer
		{
			SETBIT(TCCR2,CS20);
			SETBIT(TCCR2,CS21);
			CLEARBIT(TCCR2,CS22);
		}
	}
	else if (clock==TIMER_CLK256)
	{
		if (t==TIM0)
		{
			CLEARBIT(TCCR0,CS00);
			CLEARBIT(TCCR0,CS01);
			SETBIT(TCCR0,CS02);
		}
		else //Timer 2 is the default timer
		{
			CLEARBIT(TCCR2,CS20);
			CLEARBIT(TCCR2,CS21);
			SETBIT(TCCR2,CS22);
		}
	}
	else if (clock==TIMER_CLK1024)
	{
		if (t==TIM0)
		{
			SETBIT(TCCR0,CS00);
			CLEARBIT(TCCR0,CS01);
			SETBIT(TCCR0,CS02);
		}
		else //Timer 2 is the default timer
		{
			SETBIT(TCCR2,CS20);
			CLEARBIT(TCCR2,CS21);
			SETBIT(TCCR2,CS22);
		}
	}
	else if (clock==TIMER_FALLING_EDGE)
	{
		if (t==TIM0)
		{
			CLEARBIT(TCCR0,CS00);
			SETBIT(TCCR0,CS01);
			SETBIT(TCCR0,CS02);
		}
		else //Timer 2 is the default timer
		{
			CLEARBIT(TCCR2,CS20);
			SETBIT(TCCR2,CS21);
			SETBIT(TCCR2,CS22);
		}
	}
	else if (clock==TIMER_RISING_EDGE)
	{
		if (t==TIM0)
		{
			SETBIT(TCCR0,CS00);
			SETBIT(TCCR0,CS01);
			SETBIT(TCCR0,CS02);
		}
		else //Timer 2 is the default timer
		{
			SETBIT(TCCR2,CS20);
			SETBIT(TCCR2,CS21);
			SETBIT(TCCR2,CS22);
		}
	}

}

void timer_loadComp_8(Timer_8 t,uint8 val)
{
		if (t==TIM0)
		{
			OCR0 = val;
		}
		else //Timer 2 is the default timer
		{
			OCR2 = val;
		}	

}

void timer_stop_8(Timer_8 t)
{
	if (t==TIM0)
	{
		//disconnect OC1 pins
		CLEARBIT(TCCR0,CS00);
		CLEARBIT(TCCR0,CS01);
		CLEARBIT(TCCR0,CS02);
	}
	else //Timer 2 is the default timer
	{
		//disconnect OC2 pin
		CLEARBIT(TCCR2,CS20);
		CLEARBIT(TCCR2,CS21);
		CLEARBIT(TCCR2,CS22);
	}
}

void timer_setDutyCycle_8(Timer_8 t,uint8 DCyc, Bool inverting)
{
	//guard
	if(DCyc>100)
	{
		DCyc=100;
	}
	if(DCyc<0)
	{
		DCyc=0;
	}
	//checks if inverting PWM or non inverting
	if (inverting)
	{
		DCyc=100-DCyc;
	}
	//
	if (t==TIM0)
	{
		OCR0=255*(DCyc/100.00);
	}
	else //Timer 2 is the default timer
	{
		OCR2=255*(DCyc/100.00);
	}

}
