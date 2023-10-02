#ifndef TWI_PRIV_H_
#define TWI_PRIV_H_

#define TWBR (*((volatile uint8 *)0x20)) 
#define TWCR (*((volatile uint8 *)0x56)) 
#define TWSR (*((volatile uint8 *)0x21)) 
#define TWAR (*((volatile uint8 *)0x22)) 
#define TWDR (*((volatile uint8 *)0x23)) 

//TWCR_REG
#define TWINT 	 7 
#define TWEA	 6 
#define TWSTA 	 5 
#define TWSTO 	 4 
#define TWWC 	 3 
#define TWEN 	 2 
#define TWIE 	 0 

//TWSR_REG

#define TWPS1  1
#define TWPS0  0

// TWAR_REG
#define TWGCE 0

//Prescaller 

#define TWI_PRESCALLER_MASK (uint8) 0b11111100

#define TWI_PRESCALLER_1	(uint8) 0b11111100
#define TWI_PRESCALLER_4	(uint8) 0b11111101
#define TWI_PRESCALLER_16	(uint8) 0b11111110
#define TWI_PRESCALLER_64	(uint8) 0b11111111

//Interface Mode 

#define TWI_POLLING			0
#define TWI_INTERRUPT		1





#endif