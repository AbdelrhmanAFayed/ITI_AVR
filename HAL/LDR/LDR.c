#include "STD_Types.h"
#include "BIT_MAth.h"


#include "ADC.h"

#include "LDR.h"
#include "LDR_cfg.h"
#include "LDR_priv.h"







uint8 LDR_u16StatusASync(void)
{

	uint16 u16level = ADC_u16ReadASync();
	
	#if ADC_ADJUSTMENT_MODE  == ADC_LEFT
	
	uint16 u16cmpr = 255 ;
	
	#else 
		
	uint16 u16cmpr = 1024 ;
	
	#endif
	
	if(LDR_SENSITIVITY >= 10)
		{
			if(u16level > 0)
			{
				return 1 ;
			}
		}
		else
		{
			if(u16level > u16cmpr/LDR_SENSITIVITY)
			{
				return 1 ;
			}
		}

		return 0 ;
}

uint8 LDR_u16StatusSync(void)
{
	uint16 u16level = ADC_u16ReadSync() ;
	
	#if ADC_ADJUSTMENT_MODE  == ADC_LEFT
	
	uint16 u16cmpr = 255 ;
	
	#else 
		
	uint16 u16cmpr = 1024 ;
	
	#endif
	
	if(LDR_SENSITIVITY >= 10)
	{
		if(u16level > 0)
		{
			return 1 ;
		}
	}
	else
	{
		if(u16level > u16cmpr/LDR_SENSITIVITY)
		{
			return 1 ;
		}
	}
	
	return 0 ;
	
}


