#ifndef COMMSSTEERING_H
#define COMMSSTEERING_H

#include "gd32f1x0.h"
#include "../Inc/config.h"

// Only master communicates with steering device
#ifdef MASTER
//----------------------------------------------------------------------------
// Update USART steer input
//----------------------------------------------------------------------------
void UpdateUSARTSteerInput(void);

//----------------------------------------------------------------------------
// Send frame to steer device
//----------------------------------------------------------------------------
void SendSteerDevice(void);
#endif

#endif
