
#ifndef EXTINT_H
#define EXTINT_H


void EXTINT0_voidInit(void);
void EXTINT1_voidInit(void);
void EXTINT2_voidInit(void);

void EXTINT0_voidEnable(void);
void EXTINT1_voidEnable(void);
void EXTINT2_voidEnable(void);

void EXTINT0_voidDisable(void);
void EXTINT1_voidDisable(void);
void EXTINT2_voidDisable(void);

void EXTINT0_voidSetCallBack(pf pfCallbackCpy);
void EXTINT1_voidSetCallBack(pf pfCallbackCpy);
void EXTINT2_voidSetCallBack(pf pfCallbackCpy);



#endif

