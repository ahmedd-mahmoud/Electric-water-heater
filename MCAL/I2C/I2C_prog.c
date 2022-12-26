/*
 * I2C_prog.c
 *
 * Created: 11/19/2022 3:51:50 PM
 *  Author: DELL
 */ 

#include "I2C_interface.h"
#define Null     (void*)(0)




void I2C_init(void)
{
	/*Global Interrupt*/
	SREG = 1<<7;
	
	//Peripheral Interrupt
	TWCR = (1<<TWEN)|(1<<TWIE);
	
	//Frequency generation
	TWBR = 12;
	TWSR = 0X00;
	
}

void I2C_SendStartCond(void)
{
	/*Sending Start condition*/
	TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
	while (!(TWCR & (1<<TWINT))); //Polling on interrupt flag until the flag is raised up

}
void I2C_SendRepStartCond(void)
{
	/*Sending Repeated Start condition*/
	TWCR = (1<<TWSTA)|(1<<TWEN)|(1<<TWINT);
	while (!(TWCR & (1<<TWINT))); //Polling on interrupt flag until the flag is raised up

}

void I2C_SendSlaveAdd_WriteOP(uint8 SLA_Add)
{
	TWDR = SLA_Add<<1;
	TWCR = (1<<TWEN)|(1<<TWINT);
	while (!(TWCR & (1<<TWINT))); //Polling on interrupt flag until the flag is raised up

}
void I2C_SendSlaveAdd_ReadOP(uint8 SLA_Add)
{
	TWDR = (SLA_Add<<1) | (1);
	TWCR = (1<<TWEN)|(1<<TWINT);
	while (!(TWCR & (1<<TWINT))); //Polling on interrupt flag until the flag is raised up
	
}

void I2C_SendData(uint8 Data)
{
	TWDR = Data;
	TWCR = (1<<TWEN)|(1<<TWINT);
	while (!(TWCR & (1<<TWINT))); //Polling on interrupt flag until the flag is raised up
	
}
void I2C_SendMultiData( uint8* Data, uint8 Data_Size)
{
	
	uint8 i = 0;
	for (i = 0; i < Data_Size; i++)
	{
		I2C_SendData(Data[i]);
	}
	
}
void I2C_SendString(const uint8* Data)
{
	uint8 i = 0;
	while (Data[i] != '\0')
	{
		I2C_SendData(Data[i]);
		i++;
	}
	I2C_SendData('\0');

}

uint8 I2C_ReadData(void)
{
	TWCR = (1<<TWEN)|(1<<TWINT);
	while (!(TWCR & (1<<TWINT))); //Polling on interrupt flag until the flag is raised up
	
	return TWDR;
}
uint8 I2C_ReadMultiData(void)
{
	TWCR = (1<<TWEN)|(1<<TWEA)|(1<<TWINT);
	while (!(TWCR & (1<<TWINT))); //Polling on interrupt flag until the flag is raised up
	return TWDR;
}

uint8 I2C_ReadData_SendACK(void)
{
	TWCR = (1<<TWEN)|(1<<TWEA)|(1<<TWINT);
	while (!(TWCR & (1<<TWINT))); //Polling on interrupt flag until the flag is raised up
	return TWDR;
}

void I2C_SendStopCond(void)
{
	TWCR = (1<<TWSTO)|(1<<TWEN)|(1<<TWINT);
	
	//while (!(TWCR & (1<<TWINT))); //Polling on interrupt flag until the flag is raised up
}

