#include "STD_Types.h"

#include "DIO.h"

#include "DCM_cfg.h"
#include "DCM_priv.h"

tstrPinMappingCfg DCM_astrDCMPinMapping[DCM_MAX_NUM]={
	
	{DCM_NORM,{DIO_u8PIN_0,DIO_u8PIN_3}},
	{DCM_NORM,{DIO_u8PIN_1,DIO_u8PIN_4}},
	{DCM_NORM,{DIO_u8PIN_2,DIO_u8PIN_5}}
	
};
