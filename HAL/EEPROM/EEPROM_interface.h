/*
 * EEPROM_interface.h
 *
 * Created: 11/19/2022 4:05:15 PM
 *  Author: DELL
 */ 


#ifndef EEPROM_INTERFACE_H_
#define EEPROM_INTERFACE_H_

#include "../../MCAL/I2C/I2C_interface.h"

//static uint8 PTS[100];

void EEPROM_init(void);
void   EEPROM_WriteByte(uint8 Device_Page, uint8 Data_Add, uint8 Data);
uint8  EEPROM_ReadByte(uint8 Device_Page, uint8 Data_Add);


void   EEPROM_WriteMultiBytes(uint8 Device_Page, uint8 Data_Add,  uint8* Data, uint8 Data_Size);
void   EEPROM_WriteString(uint8 Device_Page, uint8 Data_Add,const uint8* Data);

void   EEPROM_ReadMultiByte(uint8 Device_Page, uint8 Data_Add, uint8* Rec_Loc, uint8 Data_Size);
uint8* EEPROM_ReadString(uint8 Device_Page, uint8 Data_Add);




#endif /* EEPROM_INTERFACE_H_ */