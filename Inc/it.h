#ifndef IT_H
#define IT_H

#include "gd32f1x0.h"
#include "../Inc/config.h"

//----------------------------------------------------------------------------
// Resets the timeout to zero
//----------------------------------------------------------------------------
void ResetTimeout(void);

//----------------------------------------------------------------------------
// timer each 1000mseconds
//----------------------------------------------------------------------------
void TIMER_1000ms(void);

//----------------------------------------------------------------------------
// timer each 1000mseconds
//----------------------------------------------------------------------------
void TIMER_100ms(void);

//----------------------------------------------------------------------------
// timer each 20mseconds
//----------------------------------------------------------------------------
void TIMER_20ms(void);

//----------------------------------------------------------------------------
// Returns number of milliseconds since system start
//----------------------------------------------------------------------------
uint32_t millis( void );

//----------------------------------------------------------------------------
// Delays number of tick Systicks (happens every 10 ms)
//----------------------------------------------------------------------------
void Delay (uint32_t dlyTicks);

//----------------------------------------------------------------------------
// delay em ms
//----------------------------------------------------------------------------
void delay_1ms(uint32_t count);

#endif