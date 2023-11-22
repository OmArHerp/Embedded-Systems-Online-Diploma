/*
 * Include.h
 *
 * Created: 10/23/2023 10:40:39 AM
 *  Author: Herp
 */ 


#ifndef INCLUDE_H_
#define INCLUDE_H_

/**********************************_INCLUDES_**********************************/
#define F_CPU	1000000
#include <avr/io.h>
#include "util/delay.h"

/**********************************_MACROS_**********************************/
#define PASSWORD				49
#define Seven_Seg_Direction		DDRD
#define Seven_Seg_PORT			PORTD

#define LED_BUZZER_Direction	DDRA
#define LED_BUZZER_PORT			PORTA

#define Push_Button_Direction	DDRC
#define Push_Button_PIN			PINC

#define LED_GREEN				0
#define LED_YELLOW				1
#define LED_RED					2
#define BUZZER					3

#define TENS_button				0
#define UNITS_button			1
#define ENTER_buttton			2
#define RESET_buttton			3

#define	SEG1_EN					4
#define	SEG2_EN					5

#define PRESSED					0
#define NOT_PRESSED				1



#endif /* INCLUDE_H_ */