#include "STD_Types.h"
#include "BIT_Math.h"

#include "TIM.h"
#include "TIM_cfg.h"
#include "TIM_priv.h"

pf TIM0_pfCtcCallback ;
pf TIM0_pfOvfCallback ;

pf TIM2_pfCtcCallback ;
pf TIM2_pfOvfCallback ;

uint32 u32GlobalCntr = 0 ;
/*TIM0*/
void TIM0_voidInit(void)
{
	#if   TIM0_MODE == TIM0_NORMAL_MODE 
		CLR_BIT(TCCR0 , 6);
		CLR_BIT(TCCR0 , 3);
	#elif TIM0_MODE == TIM0_PWM_PHASE_CORRECT_MODE
		SET_BIT(TCCR0 , 6);
		CLR_BIT(TCCR0 , 3);
    #elif TIM0_MODE == TIM0_CTC_MODE 
		CLR_BIT(TCCR0 , 6);
		SET_BIT(TCCR0 , 3);
    #else
		SET_BIT(TCCR0 , 6);
		SET_BIT(TCCR0 , 3);
    #endif
  
  TCCR0 &= (0xF8);/* clear reg 0b1111 1000 */
  TCCR0 |=((0x03)& TIM0_PRESCALLER) ; /* write in reg */

 TCNT0 = 0;
 OCR0  = 0;
 /* Disable Interrupt  OVF CM */
 CLR_BIT(TIMSK , 0) ;
 CLR_BIT(TIMSK , 1) ;
 /* Clear IF flags OVF CM */
 SET_BIT(TIFR  , 0) ;
 SET_BIT(TIFR  , 1) ;

}

void TIM0_voidSetPreloadValue (uint8 u8PreloadValueCpy)
{
	TCNT0 = u8PreloadValueCpy;
}
void TIM0_voidSetOutputCompareValue (uint8 u8LoadValueCpy)
{
	OCR0 = u8LoadValueCpy; 
}
void TIM0_voidEnableOVFIntterrupt(void)
{
	SET_BIT(TIMSK , 0) ;
}
void TIM0_voidDisableOVFIntterrupt(void)
{
	CLR_BIT(TIMSK , 0) ;
}
void TIM0_voidEnableCTCIntterrupt(void)
{
		SET_BIT(TIMSK , 1) ;
}
void TIM0_voidDisableCTCIntterrupt(void)
{

	CLR_BIT(TIMSK , 1) ;
}
void TIM0_voidSetOvfCallback(pf pfOvfCallbackCpy)
{
	TIM0_pfOvfCallback = pfOvfCallbackCpy ;
}
uint32 TIM0_voidCounter(void)
{
	return (u32GlobalCntr*(256/1000);
}
/*OVF ISR*/
void __vector_11 (void) __attribute__((signal ,used));
void __vector_11 (void)
{
	TIM0_pfOvfCallback();
}
/*CM ISR*/
void __vector_10 (void) __attribute__((signal ,used));
void __vector_10 (void)
{
   TIM0_pfCtcCallback();
}
void TIM0_voidDelayMs(uint16 u16DalayTimeCpy)
{
	uint32 starttime = TIM0_voidCounter() ;
	while((TIM0_voidCounter() - starttime )< u16DalayTimeCpy);
	
}
uint16 TIM0_u16GetCntrValue(void )
{
	return TCNT0
}
/*TIM1*/
//void TIM1_voidInit(void)
//{
//	 TCCR1B &= (0xF8);/* clear reg 0b1111 1000 */
//	 
//	#if   TIM1_MODE == TIM0_NORMAL_MODE 
//		CLR_BIT(TCCR1A,0);
//		CLR_BIT(TCCR1A,1);
//		CLR_BIT(TCCR1B,3);
//		CLR_BIT(TCCR1B,4);
//	/*#elif TIM1_MODE == TIM0_PWM_PHASE_CORRECT_MODE
//		SET_BIT(TCCR0 , 6);
//		CLR_BIT(TCCR0 , 3);
//    #elif TIM1_MODE == TIM0_CTC_MODE 
//		CLR_BIT(TCCR0 , 6);
//		SET_BIT(TCCR0 , 3);
//    #else
//		SET_BIT(TCCR0 , 6);
//		SET_BIT(TCCR0 , 3);
//    #endif*/
//	
// 
//  TCCR1B |=((0x03)& TIM1_PRESCALLER) ; /* write in reg */
//
// TCNT0 = 0;
// OCR0  = 0;
// /* Disable Interrupt  OVF CM */
// CLR_BIT(TIMSK , 0) ;
// CLR_BIT(TIMSK , 1) ;
// /* Clear IF flags OVF CM */
// SET_BIT(TIFR  , 0) ;
// SET_BIT(TIFR  , 1) ;
//
//}*/
///*TIM2*/
void TIM2_voidInit(void)
{
	#if   TIM0_MODE == TIM0_NORMAL_MODE 
		CLR_BIT(TCCR2 , 6);
		CLR_BIT(TCCR2 , 3);
	#elif TIM0_MODE == TIM0_PWM_PHASE_CORRECT_MODE
		SET_BIT(TCCR2 , 6);
		CLR_BIT(TCCR2 , 3);
    #elif TIM0_MODE == TIM0_CTC_MODE 
		CLR_BIT(TCCR2 , 6);
		SET_BIT(TCCR2 , 3);
    #else
		SET_BIT(TCCR2 , 6);
		SET_BIT(TCCR2 , 3);
    #endif
  
  TCCR2 &= (0xF8);/* clear reg 0b1111 1000 */
  TCCR2 |=((0x03)& TIM0_PRESCALLER) ; /* write in reg */

 TCNT2 = 0;
 OCR2  = 0;
 /* Disable Interrupt  OVF CM */
 CLR_BIT(TIMSK , 6) ;
 CLR_BIT(TIMSK , 7) ;
 /* Clear IF flags OVF CM */
 SET_BIT(TIFR  , 6) ;
 SET_BIT(TIFR  , 7) ;

}
void TIM2_voidSetPreloadValue (uint8 u8PreloadValueCpy)
{
	TCNT2 = u8PreloadValueCpy;
}
void TIM2_voidSetOutputCompareValue (uint8 u8LoadValueCpy)
{
	OCR2 = u8LoadValueCpy; 
}
void TIM2_voidEnableOVFIntterrupt(void)
{
	SET_BIT(TIMSK , 6) ;
}
void TIM2_voidDisableOVFIntterrupt(void)
{
	CLR_BIT(TIMSK , 6) ;
}
void TIM2_voidEnableCTCIntterrupt(void)
{
		SET_BIT(TIMSK , 7) ;
}
void TIM2_voidDisableCTCIntterrupt(void)
{

	CLR_BIT(TIMSK , 7) ;
}
void TIM2_voidSetOvfCallback(pf pfOvfCallbackCpy)
{
	TIM2_pfOvfCallback = pfOvfCallbackCpy ;
}
void TIM2_voidSetCtcCallback(pf pfCtcCallbackCpy)
{
	TIM2_pfCtcCallback = pfCtcCallbackCpy;
}
void __vector_5 (void) __attribute__((signal ,used));
void __vector_5 (void)
{
	TIM2_pfOvfCallback();
}
/*CM ISR*/
void __vector_4 (void) __attribute__((signal ,used));
void __vector_4 (void)
{
   TIM2_pfCtcCallback();
}
uint32 TIM2_voidCounter(void)
{
	return (u32GlobalCntr*(256/1000);
}
void TIM2_voidDelayMs(uint16 u16DelayTimeCpy)
{
	uint32 starttime = TIM2_voidCounter() ;
	while((TIM2_voidCounter() - starttime )< u16DelayTimeCpy);
	
}
uint16 TIM2_u16GetCntrValue(void )
{
	return TCNT2
}
