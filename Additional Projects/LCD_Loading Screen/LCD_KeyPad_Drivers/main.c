/*
 * LCD_KeyPad_Drivers.c
 *
 * Created: 10/17/2023 9:42:50 AM
 * Author : Herp
 */ 


#include "lcd.h"
#include "Keypad.h"



int main(void)
{
	LCD_INIT();
	KEYPAD_Init();
	LCD_STORE_Custom_CHARACTER();
	LCD_WRITE_COMMAND(LCD_DISP_ON);
	LCD_GOTO_XY(1,5);
	LCD_WRITE_STRING("Loading");
	_delay_ms(2);
	LCD_GOTO_XY(2,5);
	LCD_WRITE_STRING("Please Wait");
	_delay_ms(2);
	
	//LCD_Display_Custom_CHARACTER(0);
	uint8_t row = 1 ;
	uint8_t col = 0;
	uint8_t Prev_col = -1;
	uint8_t position = 0;
    /* Replace with your application code */
    while (1) 
    {
		row = 1;
		for(col =0, position=0, Prev_col = -1 ; col < 4 ; col++, Prev_col++ , position++)
		{
			LCD_GOTO_XY(row, col);
			LCD_Display_Custom_CHARACTER(position);
			_delay_ms(500);
			LCD_GOTO_XY(row, Prev_col);
			LCD_WRITE_CHAR(0x20);
			_delay_ms(500);
		}
		
		LCD_GOTO_XY(row, Prev_col);
		LCD_WRITE_CHAR(0x20);
		_delay_ms(500);
		row = 2;
		col--;
		
		for(; col > 0 ; col--, Prev_col-- , position++)
		{
			LCD_GOTO_XY(row, col);
			LCD_Display_Custom_CHARACTER(position);
			_delay_ms(500);
			if(col == 3)
			{
				Prev_col = 4;
				continue;
			}
			LCD_GOTO_XY(row, Prev_col);
			LCD_WRITE_CHAR(0x20);
			_delay_ms(500);
		}
		LCD_GOTO_XY(row,Prev_col);
		LCD_WRITE_CHAR(0x20);
		_delay_ms(500);
		LCD_GOTO_XY(row,col);
		LCD_WRITE_CHAR(position);
		_delay_ms(500);
		LCD_GOTO_XY(row,col);
		LCD_WRITE_CHAR(0x20);
		_delay_ms(500);
		row =1; col =0;
		LCD_GOTO_XY(row,0);
		
		
    }
}

