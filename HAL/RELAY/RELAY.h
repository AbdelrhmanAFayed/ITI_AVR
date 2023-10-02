#ifndef RELAY_H
#define RELAY_H

#include "RELAY_cfg.h"

#define RELAY_u8OPEN 	   DIO_u8LOW
#define RELAY_u8CLOSE      DIO_u8HIGH

void RELAY_voidwrite(uint8 u8RelayNumCpy , uint8 u8RelayValueCpy);


#endif
