



#include "STD_Types.h"
#include "BIT_Math.h"

#include "TWI_priv.h"
#include "TWI_config.h"
#include "TWI_int.h"



void TWI_voidMasterInit(void)
{
	/*Set BITRATE*/
	TWBR = 0x02;
	/*Enable TWI*/
	TWCR = (1<<TWEN);
	/*Set PRESCALLER*/
	TWSR = 0x00;
	
	
	
	
	
}

void TWI_voidSendStart(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTA)|(1<<TWEN);
	while(!(GET_BIT(TWCR,TWINT)));		
}



void TWI_u8Write(uint8 u8datacpy)
{
	TWDR = u8datacpy;
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(!(GET_BIT(TWCR,TWINT)));
	
	
	
}


uint8 u8TWI_voidReadAck(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN)|(1<<TWEA);
	while(!(GET_BIT(TWCR,TWINT)));
	return TWDR;
}
uint8 u8TWI_voidReadNAck(void)
{
	TWCR = (1<<TWINT)|(1<<TWEN);
	while(!(GET_BIT(TWCR,TWINT)));
	return TWDR;
}

void TWI_voidStop(void)
{
	TWCR = (1<<TWINT)|(1<<TWSTO)|(1<<TWEN);
	
}

void TWI_u8SlaveInit(uint8 u8Slave_address)
{
	TWAR = u8Slave_address;
	
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWEA);
	SET_BIT(TWCR,TWINT);
}

void TWI_SlaveListen(void)
{
	while(1)
     {
		 uint8 u8TWI_Status ;
		 while(!(TWCR&(1<<TWINT)));
		 u8TWI_Status = TWSR&0xF8;
		 if(u8TWI_Status == 0x60||u8TWI_Status == 0x68)	/
			break ;
	 }
}
void TWI_SlaveTransmit(uint8 u8datacpy)
{
	uint8 u8TWI_Status ;
	TWDR = u8datacpy;	
	
	SET_BIT(TWCR,TWEA);
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWINT);
	
	while(!(TWCR&(1<<TWINT)));
	
	u8TWI_Status = TWSR&0xF8;
	if(( u8TWI_Status == 0xA0 ) ||(u8TWI_Status == 0xC0) )		
     {
	SET_BIT(TWCR,TWINT);
    }
}

uint8 TWI_SlaveReceive(void)
{
	uint8 u8TWI_Status ;
	
	SET_BIT(TWCR,TWEA);
	SET_BIT(TWCR,TWEN);
	SET_BIT(TWCR,TWINT);
	
	while(!(TWCR&(1<<TWINT)));
	
	u8TWI_Status = TWSR&0xF8;
	
	if(u8TWI_Status==0x80||u8TWI_Status==0x90||u8TWI_Status==0x88||u8TWI_Status==0x98)
	{
    return TWDR;
	}
	if(u8TWI_Status==0xA0)		
     {
	SET_BIT(TWCR,TWINT);	
     }
}



void __vector_19 (void) __attribute__((signal ,used));
void __vector_19 (void)
{
	
}













