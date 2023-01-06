#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

#include <avr/io.h>
#include "../../MyTypes.h"
#include "../../BitMath.h"

//voltage reference options
typedef enum
{
	External_Vref,	
	Vcc,	
	Internal_Vref	
}ADC_Ref;

//clock options
typedef enum
{
	ADC_CLK2,
	ADC_CLK4,
	ADC_CLK8,
	ADC_CLK16,
	ADC_CLK32,
	ADC_CLK64,
	ADC_CLK128			
}ADC_CLK;

//single ended input channels
#define ADC0			0
#define ADC1			1
#define ADC2			2
#define ADC3			3	
#define ADC4			4
#define ADC5			5
#define ADC6			6
#define ADC7			7
//ADC working modes
typedef enum
{
	single,
	autoTrigger,
	freeRunning
}ADC_mode;


#endif /* ADC_CONFIG_H_ */