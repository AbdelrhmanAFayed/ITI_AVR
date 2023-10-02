#include "STD_Types.h"

#include "DIO.h"

#include "BUZZ_cfg.h"
#include "BUZZ_priv.h"

tstrPinMappingCfg BUZZ_astrBuzzPinMapping[BUZZ_MAX_NUM - BUZZ_NUM_TWOWAY]={
	
	{ BUZZ_u8ONE_HIGH,{DIO_u8PIN_0,} },
	{BUZZ_u8ONE_LOW,{DIO_u8PIN_1,}},
	{BUZZ_u8BOTH,{DIO_u8PIN_2,DIO_u8PIN_3}}
	
};
