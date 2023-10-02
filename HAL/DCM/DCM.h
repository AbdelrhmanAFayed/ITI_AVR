#ifndef DCM_H
#define DCM_H

#include "DCM_cfg.h"

void DCM_init(void);

tenuErrorStatus DCM_enuGO(uint8 u8BDCMNumCpy , uint8 u8DCMValueCpy);

tenuErrorStatus DCM_enuSTOP(uint8 u8DCMNumCpy);


#endif
