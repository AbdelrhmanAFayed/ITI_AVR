#ifndef PWM_H
#define PWM_H

void PWM_voidInit(void);
void PWM_void_cfg(uint8 u8DutyValueCpy,float32 u8FreqValueCpy);
void Interrupt_Handler(void);
#endif
