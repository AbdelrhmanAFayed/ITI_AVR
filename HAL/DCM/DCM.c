#include "STD_Types.h"
#include "BIT_Math.h"

#include "DIO.h"

#include  "DCM.h"
#include  "DCM_cfg.h"
#include  "DCM_priv.h"


void DCM_init(void)
{
	uint8 u8CntrlLoc ;
	for (u8CntrlLoc = 0 ; u8CntrlLoc < DCM_MAX_NUM ; u8CntrlLoc++ )
	{
	DCM_enuSTOP(u8CntrlLoc);
	}
}
tenuErrorStatus DCM_enuSTOP(uint8 u8DCMNumCpy)
{
	tenuErrorStatus  enuReturnStatusLoc = E_OK ;
	if(u8DCMNumCpy < DCM_MAX_NUM )
	{
	DIO_enuWritePin(DCM_astrDCMPinMapping[u8DCMNumCpy].u8DioPinMap[0] ,DIO_u8LOW);
	DIO_enuWritePin(DCM_astrDCMPinMapping[u8DCMNumCpy].u8DioPinMap[1] ,DIO_u8LOW);
	}
	else
	{
		enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
	}

	return enuReturnStatusLoc ;
	
}
tenuErrorStatus DCM_enuGO(uint8 u8DCMNumCpy , uint8 u8DCMValueCpy)
{
	tenuErrorStatus  enuReturnStatusLoc = E_OK ;
	if(u8DCMNumCpy < DCM_MAX_NUM )
		{
	if (DCM_astrDCMPinMapping[u8DCMNumCpy].u8DCMMode == DCM_NORM)
	{
		if (u8DCMValueCpy == 0)
		{
		DIO_enuWritePin(DCM_astrDCMPinMapping[u8DCMNumCpy].u8DioPinMap[0] ,DIO_u8HIGH);
		DIO_enuWritePin(DCM_astrDCMPinMapping[u8DCMNumCpy].u8DioPinMap[1] ,DIO_u8LOW);
		}
		else if (u8DCMValueCpy == 1)
		{
			DIO_enuWritePin(DCM_astrDCMPinMapping[u8DCMNumCpy].u8DioPinMap[0] ,DIO_u8LOW);
			DIO_enuWritePin(DCM_astrDCMPinMapping[u8DCMNumCpy].u8DioPinMap[1] ,DIO_u8HIGH);

		}
	}
	else if (DCM_astrDCMPinMapping[u8DCMNumCpy].u8DCMMode == DCM_REV)
	{
		if (u8DCMValueCpy == 0)
				{
					DIO_enuWritePin(DCM_astrDCMPinMapping[u8DCMNumCpy].u8DioPinMap[1] ,DIO_u8HIGH);
					DIO_enuWritePin(DCM_astrDCMPinMapping[u8DCMNumCpy].u8DioPinMap[0] ,DIO_u8LOW);
				}
				else if (u8DCMValueCpy == 1)
				{
					DIO_enuWritePin(DCM_astrDCMPinMapping[u8DCMNumCpy].u8DioPinMap[0] ,DIO_u8HIGH);
					DIO_enuWritePin(DCM_astrDCMPinMapping[u8DCMNumCpy].u8DioPinMap[1] ,DIO_u8LOW);
				}

		
	}
	else
	{
		enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
	}
	}
	else
	{
		enuReturnStatusLoc = E_NOK_PARAM_OUT_OF_RANGE ;
	}
	return enuReturnStatusLoc ;
}
