#include "STD_Types.h"

#include "DIO.h"

#include "PUSH.h"
#include "PUSH_cfg.h"
#include "PUSH_priv.h"

void PUSH_voidinit(void)
{
	uint8 u8cntr_initLoc;
	
	for(u8cntr_initLoc = 0 ; u8cntr_initLoc < PUSH_MAX_NUM ; u8cntr_initLoc++  )
	{
		if(PUSH_astrPushPinMapping[u8cntr_initLoc].u8PushMode == PUSH_u8UP )
		{
			DIO_enuPullWrite(PUSH_astrPushPinMapping[u8cntr_initLoc].u8DioPinMap , DIO_u8HIGH);
		}
		else if (PUSH_astrPushPinMapping[u8cntr_initLoc].u8PushMode == PUSH_u8DOWN)
		{
			DIO_enuPullWrite(PUSH_astrPushPinMapping[u8cntr_initLoc].u8DioPinMap , DIO_u8LOW);
		}
	}
	
}

tenuErrorStatus PUSH_enuStatusbutton(uint8 u8ButtonNumCpy , uint8 * pu8PinValueCpy)
{
	tenuErrorStatus  enuReturnStatusLoc = E_OK ;
	
	uint8 u8bufferLoc = 0; 
	
	if (u8ButtonNumCpy != NULL_PTR)
	{
	switch(PUSH_astrPushPinMapping[u8ButtonNumCpy].u8PushMode)
	{
		case PUSH_u8UP:
			enuReturnStatusLoc = DIO_enuReadPin( u8ButtonNumCpy , &u8bufferLoc);
			if(u8bufferLoc == DIO_u8LOW)
			{
				*pu8PinValueCpy = DIO_u8HIGH;
			}
			else 
			{
				*pu8PinValueCpy = DIO_u8LOW ;
			}
		break;
		
		case PUSH_u8DOWN :
		enuReturnStatusLoc = DIO_enuReadPin(u8ButtonNumCpy ,pu8PinValueCpy);
		break;
	
	}
	}else
	{
		enuReturnStatusLoc = E_NOK_PARAM_NULL_POINTER ;
	}
	
	return enuReturnStatusLoc ;
	}