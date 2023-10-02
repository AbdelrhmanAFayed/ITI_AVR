#include "STD_Types.h"
#include "BIT_Math.h"

#include "DIO.h"

#include  "RELAY.h"
#include  "RELAY_cfg.h"
#include  "RELAY_priv.h"





void RELAY_voidwrite(uint8 u8RelayNumCpy , uint8 u8RelayValueCpy)
{
		
		if(RELAY_astrRELAYPinMapping[u8RelayNumCpy].u8RELAYMode == RELAY_u8ONE_HIGH)
		{
			DIO_enuWritePin(RELAY_astrRELAYPinMapping[u8RelayNumCpy].u8DioPinMap ,u8RelayValueCpy);
		}
		else if (RELAY_astrRELAYPinMapping[u8RelayNumCpy].u8RELAYMode == RELAY_u8ONE_LOW)
		{
			if(u8RelayValueCpy)
			{
				DIO_enuWritePin(RELAY_astrRELAYPinMapping[u8RelayNumCpy].u8DioPinMap,DIO_u8LOW);
			}
			else 
			{
				DIO_enuWritePin(RELAY_astrRELAYPinMapping[u8RelayNumCpy].u8DioPinMap,DIO_u8HIGH);
			}
			
			
		}
		else{}
	
}
