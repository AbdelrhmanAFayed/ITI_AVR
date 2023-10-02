#include "STD_Types.h"
#include "BIT_Math.h"



#include "DIO.h"
#include "TIM.h"
#include "PWM_priv.h"
#include "PWM_config.h"
#include "PWM.h"
uint32 u32Duty_Inter = 0 ;
uint32 u32Time_Inter = 0 ;

//Assume Prescaler = 8 , Clock = 8MHz 

void PWM_voidInit(void)
{
	TIM2_voidInit();
	TIM2_voidEnableCTCIntterrupt();

	TIM2_voidSetOutputCompareValue(PIXEL);
	TIM2_voidSetCtcCallback(&Interrupt_Handler);
	
}
void PWM_void_cfg(uint8 u8DutyValueCpy,float32 u8FreqValueCpy)
{
	
	/*u32Time_Inter = u8FreqValueCpy;
	u32Duty_Inter = u8DutyValueCpy ;*/

	u32Time_Inter =  ((1000/PIXEL) / u8FreqValueCpy)   ;

	u32Duty_Inter = ((float32)u8DutyValueCpy/100) * u32Time_Inter;
	

}
void Interrupt_Handler(void)
{
	static uint32 u32cntrinterrupt = 0 ;

	if ((u32cntrinterrupt >= 0 )&&( u32cntrinterrupt <= u32Duty_Inter) )
	{
		DIO_enuWritePin(PWM_DIO_PIN,DIO_u8HIGH);
		u32cntrinterrupt++ ;
	}
	else if ((u32cntrinterrupt >= u32Duty_Inter) && (u32cntrinterrupt <u32Time_Inter))
	{
		DIO_enuWritePin(PWM_DIO_PIN,DIO_u8LOW);
		u32cntrinterrupt++;
		
	}
	else 
	{
		u32cntrinterrupt = 0 ;
		DIO_enuWritePin(PWM_DIO_PIN,DIO_u8HIGH);
		u32cntrinterrupt++ ;
	}

	
}
