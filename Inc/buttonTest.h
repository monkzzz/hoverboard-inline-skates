#ifndef BUTTONTEST_H
#define BUTTONTEST_H

#include "gd32f1x0.h"
#include "../Inc/config.h"

// Only master communicates with Test Button
#ifdef MASTER
//----------------------------------------------------------------------------
// Button test
//----------------------------------------------------------------------------
void ButtonTest(void);					//test button

#endif

#endif
