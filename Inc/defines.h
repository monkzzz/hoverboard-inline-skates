#ifndef DEFINES_H
#define DEFINES_H

#include "gd32f1x0.h"
#include "../Inc/config.h"

// LED defines
// 2/3 LEDS for the pedals
#define LED_GREEN GPIO_PIN_15
#define LED_GREEN_PORT GPIOA
#define LED_ORANGE GPIO_PIN_12
#define LED_ORANGE_PORT GPIOA
#define LED_RED GPIO_PIN_3
#define LED_RED_PORT GPIOB

// LEDS for moving backwards
#define UPPER_LED_PIN GPIO_PIN_1
#define UPPER_LED_PORT GPIOA
#define LOWER_LED_PIN GPIO_PIN_0
#define LOWER_LED_PORT GPIOA

//Acelerometer
#define I2C_IMU_ADDRESS 0xD0 //( 0x68 + one bit)
#define I2C_OWN_ADDRESS 0x72

// Mosfet output
// Led'strips
#define MOSFET_OUT_PIN GPIO_PIN_13
#define MOSFET_OUT_PORT GPIOC

// Brushless Control DC (BLDC) defines
// Channel G
#define RCU_TIMER_BLDC RCU_TIMER0
#define TIMER_BLDC TIMER0
#define TIMER_BLDC_CHANNEL_G TIMER_CH_2
#define TIMER_BLDC_GH_PIN GPIO_PIN_10
#define TIMER_BLDC_GH_PORT GPIOA
#define TIMER_BLDC_GL_PIN GPIO_PIN_15
#define TIMER_BLDC_GL_PORT GPIOB
// Channel B
#define TIMER_BLDC_CHANNEL_B TIMER_CH_1
#define TIMER_BLDC_BH_PIN GPIO_PIN_9
#define TIMER_BLDC_BH_PORT GPIOA
#define TIMER_BLDC_BL_PIN GPIO_PIN_14
#define TIMER_BLDC_BL_PORT GPIOB
// Channel Y
#define TIMER_BLDC_CHANNEL_Y TIMER_CH_0
#define TIMER_BLDC_YH_PIN GPIO_PIN_8
#define TIMER_BLDC_YH_PORT GPIOA
#define TIMER_BLDC_YL_PIN GPIO_PIN_13
#define TIMER_BLDC_YL_PORT GPIOB

// Timer BLDC short circuit emergency shutoff define
#define TIMER_BLDC_EMERGENCY_SHUTDOWN_PIN GPIO_PIN_12
#define TIMER_BLDC_EMERGENCY_SHUTDOWN_PORT GPIOB

// Hall sensor defines
#define HALL_A_PIN GPIO_PIN_11
#define HALL_A_PORT GPIOB
#define HALL_B_PIN GPIO_PIN_1
#define HALL_B_PORT GPIOF
#define HALL_C_PIN GPIO_PIN_14
#define HALL_C_PORT GPIOC

// Usart master slave defines
#define USART_MASTERSLAVE USART1
#define USART_MASTERSLAVE_TX_PIN GPIO_PIN_2
#define USART_MASTERSLAVE_TX_PORT GPIOA
#define USART_MASTERSLAVE_RX_PIN GPIO_PIN_3
#define USART_MASTERSLAVE_RX_PORT GPIOA

// ADC defines
#define VBATT_PIN	GPIO_PIN_4
#define VBATT_PORT GPIOA
#define VBATT_CHANNEL ADC_CHANNEL_4
#define CURRENT_DC_PIN	GPIO_PIN_6
#define CURRENT_DC_PORT GPIOA
#define CURRENT_DC_CHANNEL ADC_CHANNEL_6

// Self hold defines
// Wheel blocking pin?
#define SELF_HOLD_PIN GPIO_PIN_2
#define SELF_HOLD_PORT GPIOB

// Button defines
// ON/OFF
#define BUTTON_PIN GPIO_PIN_15
#define BUTTON_PORT GPIOC

// Usart steer defines
// Conector Remote
#define USART_STEER_COM USART0
//TX
#define USART_STEER_COM_TX_PIN GPIO_PIN_6
#define USART_STEER_COM_TX_PORT GPIOB
//RX
#define USART_STEER_COM_RX_PIN GPIO_PIN_7
#define USART_STEER_COM_RX_PORT GPIOB

#ifdef MASTER
// Buzzer defines
#define BUZZER_PIN GPIO_PIN_10
//#define BUZZER_PIN GPIO_PIN_4 //for it not to beep
#define BUZZER_PORT GPIOB

//test button
#define BUTTON_TEST_PIN GPIO_PIN_7 //replaced optical L1 of the MASTER for a button
#define BUTTON_TEST_PORT GPIOA

// Charge state defines
// Charge state
#define CHARGE_STATE_PIN GPIO_PIN_0
#define CHARGE_STATE_PORT GPIOF
#endif

// Debug pin defines
#define DEBUG_PIN GPIO_PIN_4
#define DEBUG_PORT GPIOB

// ADC value conversion defines
#define MOTOR_AMP_CONV_DC_AMP 0.201465201465  // 3,3V * 1/3 - 0,004Ohm * IL(ampere) = (ADC-Data/4095) *3,3V
#define ADC_BATTERY_VOLT      0.024169921875 	// V_Batt to V_BattMeasure = factor 30: ( (ADC-Data/4095) *3,3V *30 )

// Useful math function defines
#define ABS(a) (((a) < 0.0) ? -(a) : (a))
#define CLAMP(x, low, high) (((x) > (high)) ? (high) : (((x) < (low)) ? (low) : (x)))
#define MAX(x, high) (((x) > (high)) ? (high) : (x))
#define MAP(x, xMin, xMax, yMin, yMax) ((x - xMin) * (yMax - yMin) / (xMax - xMin) + yMin)

// ADC buffer struct
typedef struct
{
  uint16_t v_batt;
	uint16_t current_dc;
} adc_buf_t;

#endif
