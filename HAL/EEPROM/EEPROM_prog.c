/*
 * CFile1.c
 *
 * Created: 11/19/2022 4:05:32 PM
 *  Author: DELL
 */ 

#include "EEPROM_interface.h"

void EEPROM_init(void)
{
	I2C_init();	
}

void   EEPROM_WriteByte(uint8 SLA_Page, uint8 Data_Add, uint8 Data)
{
	if(SLA_Page>7)	{SLA_Page=7;}
	else if(SLA_Page<0)	{SLA_Page=0;}
	
	uint8 SLA_Add = (0x50) | SLA_Page;
	
	I2C_SendStartCond();
	I2C_SendSlaveAdd_WriteOP(SLA_Add);
	I2C_SendData(Data_Add);
	I2C_SendData(Data);
	I2C_SendStopCond();
	_delay_ms(10);
	
}

uint8  EEPROM_ReadByte(uint8 SLA_Page, uint8 Data_Add)
{
	if(SLA_Page>7)	{SLA_Page=7;}
	else if(SLA_Page<0)	{SLA_Page=0;}
		
	uint8 SLA_Add = (0x50) | SLA_Page;	
	
	I2C_SendStartCond();
	
	I2C_SendSlaveAdd_WriteOP(SLA_Add);		//write operation to send location
	I2C_SendData(Data_Add);
	
	I2C_SendRepStartCond();					//repeat to read data
	I2C_SendSlaveAdd_ReadOP(SLA_Add);
	uint8 Data = I2C_ReadData();
	
	I2C_SendStopCond();	
	_delay_ms(10);
	
	return Data;
}
