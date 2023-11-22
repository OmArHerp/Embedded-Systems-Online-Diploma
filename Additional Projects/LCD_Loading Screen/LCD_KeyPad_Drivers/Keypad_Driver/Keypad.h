/*
 * Keypad.h
 *
 * Created: 10/19/2023 4:14:48 AM
 *  Author: Herp
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_


/*******************************_INCLUDES_*******************************/
#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>


/*******************************_KEYPAD_DEFINITIONS_*******************************/

#define KEYPAD_PORT				PORTD
#define DataDir_KEYPAD_PORT		DDRD
#define KEYPAD_PIN				PIND

#define R0						0
#define R1						1
#define R2						2
#define R3						3
#define C0						4
#define C1						5
#define C2						6
#define C3						7

void KEYPAD_Init();
uint8_t KEYPAD_GETCHAR();






#endif /* KEYPAD_H_ */