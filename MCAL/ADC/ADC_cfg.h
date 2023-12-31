#ifndef ADC_CFG_H
#define ADC_CFG_H

#define ADC_VOLTAGE_REFERENCE   AVCC

#define ADC_ADJUSTMENT_MODE     ADC_LEFT

#define ADC_CHANNEL_NUM         ADC_CHANNEL_DIF_0_0_10X

#define ADC_AUTO_TRIGGIR_MODE   AUTO_TRIGGIR_ENABLE

#if ADC_AUTO_TRIGGIR_MODE == AUTO_TRIGGIR_ENABLE

#define ADC_AUTO_TRIGGIR_SOURCE FREE_RUNNING_MODE

#endif 

#define ADC_PRESCALLER        DIVISION_ON_128

#endif