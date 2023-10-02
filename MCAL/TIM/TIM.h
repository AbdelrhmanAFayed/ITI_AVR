#ifndef TIM_H
#define TIM_H

void TIM0_voidInit(void);
void TIM0_voidSetPreloadValue (uint8 u8PreloadValueCpy);
void TIM0_voidSetOutputCompareValue (uint8 u8LoadValueCpy);
void TIM0_voidEnableOVFIntterrupt(void);
void TIM0_voidDisableOVFIntterrupt(void);
void TIM0_voidEnableCTCIntterrupt(void);
void TIM0_voidDisableCTCIntterrupt(void);
void TIM0_voidSetOvfCallback(pf pfOvfCallbackCpy);
void TIM0_voidSetCtcCallback(pf pfCtcCallbackCpy);
uint32 TIM0_voidCounter(void);
void TIM0_voidDelayMs(uint16 u16DelayTimeCpy);
uint16 TIM0_u16GetCntrValue(void );

void TIM2_voidInit(void);
void TIM2_voidSetPreloadValue (uint8 u8PreloadValueCpy);
void TIM2_voidSetOutputCompareValue (uint8 u8LoadValueCpy);
void TIM2_voidEnableOVFIntterrupt(void);
void TIM2_voidDisableOVFIntterrupt(void);
void TIM2_voidEnableCTCIntterrupt(void);
void TIM2_voidDisableCTCIntterrupt(void);
void TIM2_voidSetOvfCallback(pf pfOvfCallbackCpy);
void TIM2_voidSetCtcCallback(pf pfCtcCallbackCpy);
uint32 TIM2_voidCounter(void);
void TIM2_voidDelayMs(uint16 u16DelayTimeCpy);
uint16 TIM2_u16GetCntrValue(void );
#endif