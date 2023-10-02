#include "STD_Types.h"
#include "BIT_Math.h"

#include "DIO.h"

#include  "BUZZ.h"
#include  "BUZZ_cfg.h"
#include  "BUZZ_priv.h"

tenuErrorStatus BUZZ_enuwrite(uint8 u8BuzzNumCpy , uint8 u8BuzzValueCpy)
{
	tenuErrorStatus  enuReturnStatusLoc = E_OK ;
	
		if(BUZZ_astrBuzzPinMapping[u8BuzzNumCpy].u8BUZZMode == BUZZ_u8ONE_NORMAL)
		{
			DIO_enuWritePin(BUZZ_astrBuzzPinMapping[u8BuzzNumCpy].u8DioPinMap[0] ,u8BuzzValueCpy);
		}
		else if (BUZZ_astrBuzzPinMapping[u8BuzzNumCpy].u8BUZZMode == BUZZ_u8ONE_REV)
		{
			if(u8BuzzValueCpy)
			{
				DIO_enuWritePin(BUZZ_astrBuzzPinMapping[u8BuzzNumCpy].u8DioPinMap[0],DIO_u8LOW);	
			}
			else 
			{
				DIO_enuWritePin(BUZZ_astrBuzzPinMapping[u8BuzzNumCpy].u8DioPinMap[0] ,DIO_u8HIGH);
			}
			
			
		}
		else if (BUZZ_astrBuzzPinMapping[u8BuzzNumCpy].u8BUZZMode == BUZZ_u8BOTH)
		{
			DIO_enuWritePin(BUZZ_astrBuzzPinMapping[u8BuzzNumCpy].u8DioPinMap[0] ,DIO_u8HIGH);
			DIO_enuWritePin(BUZZ_astrBuzzPinMapping[u8BuzzNumCpy].u8DioPinMap[1] ,DIO_u8LOW);
		}
		else{}
	}
	return enuReturnStatusLoc ;
	}
}