#ifndef COMMSBLUETOOTH_H
#define COMMSBLUETOOTH_H

#include "gd32f1x0.h"
#include "../Inc/config.h"

// Only slave communicates over bluetooth
#ifdef SLAVE

//----------------------------------------------------------------------------
// Update USART bluetooth input
//----------------------------------------------------------------------------
void UpdateUSARTBluetoothInput(void);

#endif

#endif
