#ifndef DCM_PRIV_H
#define DCM_PRIV_H

#define DCM_NORM 	((uint8) 0x00)
#define DCM_REV		((uint8) 0x01)

typedef struct{
	uint8 u8DCMMode;
	uint8 u8DioPinMap[2];
}tstrPinMappingCfg ;

extern tstrPinMappingCfg DCM_astrDCMPinMapping[DCM_MAX_NUM];

#endif