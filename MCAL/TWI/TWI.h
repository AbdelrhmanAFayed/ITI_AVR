#ifndef TWI_H_
#define TWI_H_

void TWI_voidMasterInit(void);
void TWI_voidSendStart(void);
void TWI_u8Write(uint8 u8datacpy);
uint8 u8TWI_voidReadAck(void);
uint8 u8TWI_voidReadNAck(void);
void TWI_voidStop(void);
void TWI_u8SlaveInit(uint8 u8Slave_address);
void TWI_SlaveListen(void);
void TWI_SlaveTransmit(uint8 u8datacpy);
uint8 TWI_SlaveReceive(void);


#endif