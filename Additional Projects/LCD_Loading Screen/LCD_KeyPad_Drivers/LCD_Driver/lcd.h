/*
 * lcd.h
 *
 * Created: 10/17/2023 9:46:00 AM
 *  Author: Herp
 */ 


#ifndef LCD_H_
#define LCD_H_


/*******************************_INCLUDES_*******************************/
#define F_CPU	1000000UL
#include <stdint.h>
#include <stdlib.h>
#include <avr/io.h>
#include "util/delay.h"

/*******************************_LCD_MODE_*******************************/

//-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Choose LCD_MODE : EIGHT_BIT_MODE OR FOUR_BIT_MODE
//-*-*-*--*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

#define LCD_MODE			FOUR_BIT_MODE

/*******************************_LCD_MACROS_*******************************/

#define LCD_PORT			PORTA
#define DataDir_LCD_PORT	DDRA
#define LCD_CTRL			PORTB
#define DataDir_LCD_CTRL	DDRB
 
#define RS_SWITCH			1
#define RW_SWITCH			2
#define ENABLE_SWITCH		3
#define DATA_SHIFT			4

#define EIGHT_BIT_MODE		9
#define FOUR_BIT_MODE		10

/*******************************_LCD_COMMANDS_*******************************/

#define LCD_FUNCTION_8BIT_2LINES	(0x38)
#define LCD_FUNCTION_4BIT_2LINES_1	(0x28)
#define LCD_FUNCTION_4BIT_2LINES_2	(0x32)
#define LCD_FUNCTION_4BIT_2LINES_3	(0x33)
#define LCD_MOVE_DISP_RIGHT			(0x1C)
#define LCD_MOVE_DISP_LEFT			(0x18)
#define LCD_MOVE_CURSOR_RIGHT		(0x14)
#define LCD_MOVE_CURSOR_LEFT		(0x10)
#define LCD_DISP_OFF				(0x08)
#define LCD_DISP_ON_CURSOR			(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK	(0x0F)
#define LCD_DISP_ON_BLINK			(0x0D)
#define LCD_DISP_ON					(0x0C)
#define LCD_ENTRY_DEC				(0x04)
#define LCD_ENTRY_DEC_SHIFT			(0x05)
#define LCD_ENTRY_MODE				(0x06)
#define LCD_ENTRY_INC_SHIFT			(0x07)
#define LCD_BEGIN_AT_FIRST_ROW		(0x80)
#define LCD_BEGIN_AT_SECOND_ROW		(0xC0)
#define LCD_CLEAR_DISPLAY			(0x01)

//=======================================================================================================
//=======================================================================================================

/*
 *======================================================================================
 * 											APIs 
 *======================================================================================
 */

void LCD_INIT(void);
void LCD_WRITE_COMMAND(uint8_t command);
void LCD_WRITE_CHAR(uint8_t data);
void LCD_WRITE_STRING(uint8_t* data);
void LCD_IsBusy(void);
void LCD_Clear_Screen(void);
void LCD_STORE_Custom_CHARACTER();
void LCD_Display_Custom_CHARACTER(uint8_t CGRAM_Index);
void LCD_GOTO_XY(uint8_t line, uint8_t position);



#endif /* LCD_H_ */