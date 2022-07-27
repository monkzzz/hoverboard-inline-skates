#ifndef COMMS_H
#define COMMS_H

#include "gd32f1x0.h"
#include "../Inc/config.h"

//----------------------------------------------------------------------------
// Send buffer via USART
//----------------------------------------------------------------------------
void SendBuffer(uint32_t usart_periph, uint8_t buffer[], uint8_t length);

//----------------------------------------------------------------------------
// Calculate CRC
//----------------------------------------------------------------------------
uint16_t CalcCRC(uint8_t *ptr, int count);

#endif
