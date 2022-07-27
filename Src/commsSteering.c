
#include "gd32f1x0.h"
#include "../Inc/it.h"
#include "../Inc/comms.h"
#include "../Inc/commsSteering.h"
#include "../Inc/setup.h"
#include "../Inc/config.h"
#include "../Inc/defines.h"
#include "../Inc/bldc.h"
#include "stdio.h"
#include "string.h"

// Only master communicates with steerin device
#ifdef MASTER
#define USART_STEER_TX_BYTES 2   // Transmit byte count including start '/' and stop character '\n'
#define USART_STEER_RX_BYTES 8   // Receive byte count including start '/' and stop character '\n'

// / , \n

extern uint8_t usartSteer_COM_rx_buf[USART_STEER_COM_RX_BUFFERSIZE];
static uint8_t sSteerRecord = 0;
static uint8_t sUSARTSteerRecordBuffer[USART_STEER_RX_BYTES];
static uint8_t sUSARTSteerRecordBufferCounter = 0;

void CheckUSARTSteerInput(uint8_t u8USARTBuffer[]);

extern int32_t steer;
extern int32_t speed;

extern float batteryVoltage; 							// global variable for battery voltage
extern int16_t batteryState; 									// global variable for battery state to send to steer



//testes
int32_t testes1 = 0;
int32_t testes2 = 0;
int32_t testes3 = 0;
int32_t testes4 = 0;
int32_t testes5 = 0;
int32_t testes6 = 0;

int32_t testeslinha = 0;

int32_t testesspeed = 0;
int32_t testessteer = 0;

uint8_t byte0 = 0;
uint8_t byte1 = 0;
uint8_t byte2 = 0;
uint8_t byte3 = 0;
uint8_t byte4 = 0;

uint8_t sendbytez = 0;
uint8_t bytecrc = 0;
uint8_t bytecrc2 = 0;

//----------------------------------------------------------------------------
// Send frame to steer device
//----------------------------------------------------------------------------
void SendSteerDevice(void)
{
	int index = 0;
	uint8_t buffer[USART_STEER_TX_BYTES];
	
	// Ask for steer input
	//buffer[index++] = '/';
	
	char batteryState2[2];
	//int16_t batteryState2;
	
	//int16_t batteryState3;
	//batteryState3 = batteryVoltage;
	
	//sprintf(batteryState2, "%02d", batteryState3);
	sprintf(batteryState2, "%2f", batteryVoltage);
	
	
	buffer[index++] = batteryState2[0];
	buffer[index++] = batteryState2[1]; //just needs the second number because the first one is always 3
	
	//buffer[index++] = '\n';
	
	SendBuffer(USART_STEER_COM, buffer, index);
}

//----------------------------------------------------------------------------
// Update USART steer input
//----------------------------------------------------------------------------
void UpdateUSARTSteerInput(void)
{
	uint8_t character = usartSteer_COM_rx_buf[0];
		
	// Start character is captured, start record
	if (character == '/')
	{
		//test purposes
			testes1 =	1;
			testes2 = 0;
			testes3 = 0;
			testes4 = 0;
			testes5 = 0;
			testes6 = 0;
		
			testesspeed = 0;
			testessteer = 0;
		
		sUSARTSteerRecordBufferCounter = 0;
		sSteerRecord = 1;
		
	}

	if (sSteerRecord)
	{
		sUSARTSteerRecordBuffer[sUSARTSteerRecordBufferCounter] = character;
		sUSARTSteerRecordBufferCounter++;
		
		//test purposes

			testes2 = 1;

		
		if (sUSARTSteerRecordBufferCounter >= USART_STEER_RX_BYTES)
		{
			//if sUSARTSteerRecordBufferCounter bigger or equal than 8bytes
			//stop recording
			
			
			sUSARTSteerRecordBufferCounter = 0;
			sSteerRecord = 0;
			
			////test purposes

			testes3 = 1;

			
			// Check input
			CheckUSARTSteerInput (sUSARTSteerRecordBuffer);
		}
	}
}

//----------------------------------------------------------------------------
// Check USART steer input
//----------------------------------------------------------------------------
void CheckUSARTSteerInput(uint8_t USARTBuffer[])
{
	
	// Auxiliary variables
	uint16_t crc;
	
	// Check start and stop character
	
	////test purposes
	byte0 = USARTBuffer[0];
	byte1 = USARTBuffer[1];
	byte2 = USARTBuffer[2];
	byte3 = USARTBuffer[3];
	byte4 = USARTBuffer[4];
	
	sendbytez = USARTBuffer[5];
	
	bytecrc = USARTBuffer[6];
	bytecrc2 = USARTBuffer[7];
	
	
	//----------------------------------------------------------------------------------------------
	
	if ( USARTBuffer[0] != '/' ||
		USARTBuffer[USART_STEER_RX_BYTES - 1] != '\n')
	
	//If USARTBuffer[0] different than / 
	
	//or
	
	//USARTBuffer[8 BYTES - 1] different then \n
	
	{

			////test purposes

			testes4 = 1;

		return;
	}
	//------------------------------------------------------------------------------------------------------------------
	
			////test purposes

			testes5 = 1;

	
	/*
	// Calculate CRC (first bytes except crc and stop byte)
	crc = CalcCRC(USARTBuffer, USART_STEER_RX_BYTES - 3);
	
	// Check CRC	

	if ( USARTBuffer[USART_STEER_RX_BYTES - 3] != ((crc >> 8) & 0xFF) ||
		USARTBuffer[USART_STEER_RX_BYTES - 2] != (crc & 0xFF))

	
	//se USARTBuffer[8 BYTES - 3] diferente de (crc >> 8) & 0xFF 
	//ou 
	//USARTBuffer[8 - 2] diferente de (crc & 0xFF)
	
	{

			//testes

			testes6 = 1;

		return;
	}
	*/
	
	// Calculate result speed value -1000 to 1000
	speed = (int16_t)((USARTBuffer[1] << 8) | USARTBuffer[2]);
	//testesspeed = (int16_t)((USARTBuffer[1] << 8) | USARTBuffer[2]);
	
	
	// Calculate result steering value -1000 to 1000
	steer = (int16_t)((USARTBuffer[3] << 8) | USARTBuffer[4]);
	//testessteer = (int16_t)((USARTBuffer[3] << 8) | USARTBuffer[4]);

	
	//Teste Sendbyte
	//If 7 turn on a led
	if (USARTBuffer[5] == 7)
	{
		//gpio_bit_write(LED_RED_PORT, LED_RED, SET);
		//gpio_bit_write(UPPER_LED_PORT, UPPER_LED_PIN, SET);
		//gpio_bit_write(LOWER_LED_PORT, LOWER_LED_PIN, RESET);
		//gpio_bit_write(MOSFET_OUT_PORT, MOSFET_OUT_PIN, SET);
		
	}
	
	// Reset the pwm timout to avoid stopping motors
	ResetTimeout();
}
#endif
