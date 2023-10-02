
#include "STD_Types.h"
#include "BIT_Math.h"

#include "EXTINT.h"
#include "EXTINT_cfg.h"
#include "EXTINT_priv.h"


pf EXTINT0_pfCallback ;
pf EXTINT1_pfCallback ;
pf EXTINT2_pfCallback ;

void EXTINT0_voidInit(void)
{

#if EXTINT0_SENSE_MODE == LOW_LEVEL
	CLR_BIT(MCUCR , 0) ;
	CLR_BIT(MCUCR , 1) ;
	
#elif EXTINT0_SENSE_MODE ==IOC 
	SET_BIT(MCUCR , 0) ;
	CLR_BIT(MCUCR , 1) ;
#elif EXTINT0_SENSE_MODE == FALLING_EDGE
	CLR_BIT(MCUCR , 0) ;
	SET_BIT(MCUCR , 1) ;
#else
	SET_BIT(MCUCR , 0) ;
	SET_BIT(MCUCR , 1) ;
#endif 

	CLR_BIT(GICR,6); // Disable External interrupt 0
	SET_BIT(GIFR,6); //Clear External interrupt 0 Flag 

}
void EXTINT1_voidInit(void)
{

#if EXTINT1_SENSE_MODE == LOW_LEVEL
	CLR_BIT(MCUCR , 2) ;
	CLR_BIT(MCUCR , 3) ;
	
#elif EXTINT1_SENSE_MODE ==IOC 
	SET_BIT(MCUCR , 2) ;
	CLR_BIT(MCUCR , 3) ;
#elif EXTINT1_SENSE_MODE == FALLING_EDGE
	CLR_BIT(MCUCR , 2) ;
	SET_BIT(MCUCR , 3) ;
#else
	SET_BIT(MCUCR , 2) ;
	SET_BIT(MCUCR , 3) ;
#endif 

	CLR_BIT(GICR,7); 
	SET_BIT(GIFR,7); 

}
void EXTINT2_voidInit(void)
{
#if EXTINT2_SENSE_MODE == FALLING_EDGE
	CLR_BIT(MCUCSR , 6) ;
#else
	SET_BIT(MCUCSR , 6) ;
#endif

	CLR_BIT(GICR,5);
	SET_BIT(GIFR,5);

}

void EXTINT0_voidEnable(void)
{
	SET_BIT(GICR,6);
}

void EXTINT1_voidEnable(void)
{
	SET_BIT(GICR,7);
}
void EXTINT2_voidEnable(void)
{
	SET_BIT(GICR,5);
}

void EXTINT0_voidDisable(void)
{
	CLR_BIT(GICR,6);
}
void EXTINT1_voidDisable(void)
{
	CLR_BIT(GICR,7);
}
void EXTINT2_voidDisable(void)
{
	CLR_BIT(GICR,5);
}

void EXTINT0_voidSetCallBack(pf pfCallbackCpy)
{
	EXTINT0_pfCallback = pfCallbackCpy ;
}
void EXTINT1_voidSetCallBack(pf pfCallbackCpy)
{
	EXTINT1_pfCallback = pfCallbackCpy ;
}
void EXTINT2_voidSetCallBack(pf pfCallbackCpy)
{
	EXTINT2_pfCallback = pfCallbackCpy ;
}

void __vector_1(void) __attribute__((signal,used));
void __vector_1(void)
{
	EXTINT0_pfCallback();
}
void __vector_2(void) __attribute__((signal,used));
void __vector_2(void)
{
	EXTINT1_pfCallback();
}
void __vector_3(void) __attribute__((signal,used));
void __vector_3(void)
{
	EXTINT2_pfCallback();
}


