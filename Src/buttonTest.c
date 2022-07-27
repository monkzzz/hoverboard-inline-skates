#include "gd32f1x0.h"

#include "../Inc/it.h"
#include "../Inc/comms.h"
//#include "../Inc/commsSteering.h"

#include "../Inc/buttonTest.h"

#include "../Inc/setup.h"
#include "../Inc/config.h"
#include "../Inc/defines.h"
#include "../Inc/bldc.h"
#include "stdio.h"
#include "string.h"

// Only master has test button

//FlagStatus ButtonTestPressed;					//test button
FlagStatus ButtonTestPressed = SET;				//global variable. RESET when pressed.
//uint8_t  ButtonTestPressed = 0;

//Leds para test
FlagStatus LedGreen = RESET;
FlagStatus LedRed = RESET;

extern int32_t steer;
extern int32_t speed;

#ifdef MASTER

//----------------------------------------------------------------------------
// Button test
//----------------------------------------------------------------------------
void ButtonTest(void)
{
		//Button test
		
		ButtonTestPressed=gpio_input_bit_get(BUTTON_TEST_PORT, BUTTON_TEST_PIN);
	
		LedGreen=gpio_input_bit_get(LED_GREEN_PORT, LED_GREEN);
	
		LedRed=gpio_input_bit_get(LED_RED_PORT, LED_RED);

		//Button not pressed 
		//Red Led
		if(ButtonTestPressed==SET){
			/*
			gpio_bit_write(LED_RED_PORT, LED_RED, SET);
			gpio_bit_write(LED_GREEN_PORT, LED_GREEN, RESET);
			
			//Stop wheels
			steer = 0;
			speed = 0;
			*/
			
			// Reset the pwm timout to avoid stopping motors
			//ResetTimeout();
			
    }
		
		else{
			//Button pressed
			//Green led
			/*
			gpio_bit_write(LED_RED_PORT, LED_RED, RESET);
			gpio_bit_write(LED_GREEN_PORT, LED_GREEN, SET);

			//wheels rolling
			steer = 100;
			speed = 100;
			
			// Reset the pwm timout to avoid stopping motors
			ResetTimeout();
			*/
    }	
		
}	

#endif
