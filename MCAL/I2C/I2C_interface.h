/*
 * I2C_interface.h
 *
 * Created: 11/19/2022 3:54:10 PM
 *  Author: DELL
 */ 


#ifndef I2C_INTERFACE_H_
#define I2C_INTERFACE_H_

//#define F_CPU 16000000
#include <util/delay.h>
#include "avr/io.h"
#include "../../MyTypes.h"
#include "../../BitMath.h"


#define I2C_MASTER_CLOCK          400


void I2C_init(void);
void I2C_SendStartCond(void);
void I2C_SendRepStartCond(void);
void I2C_SendSlaveAdd_WriteOP(uint8 SLA_Add);
void I2C_SendSlaveAdd_ReadOP(uint8 SLA_Add);

void I2C_SendData(uint8 Data);
void I2C_SendMultiData( uint8* Data, uint8 Data_Size);
void I2C_SendString(const uint8* Data);

uint8 I2C_ReadData(void);
uint8 I2C_ReadMultiData(void);

void I2C_SendStopCond(void);



#endif /* I2C_INTERFACE_H_ */