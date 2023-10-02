#ifndef TIM_PRIV_H
#define TIM_PRIV_H

#define  TIM0_NORMAL_MODE                0 
#define  TIM0_PWM_PHASE_CORRECT_MODE     1
#define  TIM0_CTC_MODE                   2
#define  TIM0_FAST_PWM_MODE              3

#define TIM0_NO_CLK_SRC                  0
#define TIM0_NO_PRESCALLER               1
#define TIM0_PRESCALLER_8                2
#define TIM0_PRESCALLER_64               3
#define TIM0_PRESCALLER_256              4
#define TIM0_PRESCALLER_1024             5
#define TIM0_EXT_CLK_SRC_FALLING_EDGE    6
#define TIM0_EXT_CLK_SRC_RISING_EDGE     7

#define TIM1_NORMAL_MODE                0 
#define TIM1_PWM_PHASE_CORRECT_MODE     1
#define TIM1_CTC_MODE                   2
#define TIM1_FAST_PWM_MODE              3
           
#define TIM1_NO_CLK_SRC                  0
#define TIM1_NO_PRESCALLER               1
#define TIM1_PRESCALLER_8                2
#define TIM1_PRESCALLER_64               3
#define TIM1_PRESCALLER_256              4
#define TIM1_PRESCALLER_1024             5
#define TIM1_EXT_CLK_SRC_FALLING_EDGE    6
#define TIM1_EXT_CLK_SRC_RISING_EDGE     7

#define  TIM2_NORMAL_MODE                0 
#define  TIM2_PWM_PHASE_CORRECT_MODE     1
#define  TIM2_CTC_MODE                   2
#define  TIM2_FAST_PWM_MODE              3

#define TIM2_NO_CLK_SRC                  0
#define TIM2_NO_PRESCALLER               1
#define TIM2_PRESCALLER_8                2
#define TIM2_PRESCALLER_64               3
#define TIM2_PRESCALLER_256              4
#define TIM2_PRESCALLER_1024             5
#define TIM2_EXT_CLK_SRC_FALLING_EDGE    6
#define TIM2_EXT_CLK_SRC_RISING_EDGE     7


#define TCNT0   *((volatile uint8 *) 0x52 )
#define OCR0    *((volatile uint8 *) 0x5C )
#define TCCR0   *((volatile uint8 *) 0x53 )
                
#define TCCR1A	*((volatile uint8 *) 0x4F )
#define TCCR1B	*((volatile uint8 *) 0x4E )
#define TCNT1H	*((volatile uint8 *) 0x4D )
#define TCNT1L	*((volatile uint8 *) 0x4C )
#define OCR1AH	*((volatile uint8 *) 0x4B )
#define OCR1AL	*((volatile uint8 *) 0x4A )
#define OCR1BH	*((volatile uint8 *) 0x49 )
#define OCR1BL	*((volatile uint8 *) 0x48 )
#define ICR1H	*((volatile uint8 *) 0x47 )
#define ICR1L	*((volatile uint8 *) 0x46 )
                
#define TCNT2   *((volatile uint8 *) 0x44 )
#define OCR2    *((volatile uint8 *) 0x43 )
#define TCCR2   *((volatile uint8 *) 0x45 )
                
#define TIMSK   *((volatile uint8 *) 0x59 )
#define TIFR    *((volatile uint8 *) 0x58 )

#endif 