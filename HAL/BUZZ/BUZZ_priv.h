#ifndef BUZZ_PRIV_H
#define BUZZ_PRIV_H

#define BUZZ_u8ONE_NORMAL    ((uint8) 0x00)
#define BUZZ_u8ONE_REV     ((uint8) 0x01)
#define BUZZ_u8BOTH   		((uint8) 0x02)

typedef struct{
	uint8 u8BUZZMode;
	uint8 u8DioPinMap[2];
}tstrPinMappingCfg ;

extern tstrPinMappingCfg BUZZ_astrBuzzPinMapping[BUZZ_MAX_NUM - BUZZ_NUM_TWOWAY];

#endif