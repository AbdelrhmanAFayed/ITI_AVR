#ifndef RELAY_PRIV_H
#define RELAY_PRIV_H

#include "RELAY_cfg.h"


#define RELAY_u8ONE_HIGH    ((uint8) 0x00)
#define RELAY_u8ONE_LOW     ((uint8) 0x01)





typedef struct{
	uint8 u8RELAYMode;
	uint8 u8DioPinMap;
}tstrRELAYPinMappingCfg ;

extern tstrRELAYPinMappingCfg RELAY_astrRELAYPinMapping[RELAY_MAX_NUM];



#endif
