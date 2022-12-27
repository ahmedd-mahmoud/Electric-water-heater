/*
 * main.c
 *
 * Created: 12/26/2022 8:14:25 PM
 *  Author: DELL
 */ 

#include "APP/ElectricHeater/ElectricHeater.h"

int main(void)
{
	ElectricHeater_init();
	while(1)
	{
		displayTemp();	


	}
}