#ifndef PUSH_PRIV_H
#define PUSH_PRIV_H

#define PUSH_u8UP    ((uint8) 0x00)
#define PUSH_u8DOWN   ((uint8) 0x01)

typedef struct{
	uint8 u8DioPinMap;
	uint8 u8PushMode;
}tstrPinMappingCfg ;

extern tstrPinMappingCfg PUSH_astrPushPinMapping[PUSH_MAX_NUM];

#endif