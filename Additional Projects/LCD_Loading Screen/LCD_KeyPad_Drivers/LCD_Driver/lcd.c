/*
 * lcd.c
 *
 * Created: 10/17/2023 9:46:17 AM
 *  Author: Herp
 */ 

#include "lcd.h"

void LCD_KICK()
{
	//turn on enable for 1ms
	LCD_CTRL |= (1<<ENABLE_SWITCH);
	_delay_ms(1);
	LCD_CTRL &= ~(1<<ENABLE_SWITCH);
}

void LCD_GOTO_XY(uint8_t line, uint8_t position)
{
	if(line == 1)
	{
		if(position >=0 && position < 16)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
		}
		
	}
	else if(line == 2)
	{
		if(position >=0 && position < 32)
		{
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW+ position);
		}
	}
	
}

void LCD_INIT(void)
{
	//Initialization Delay
	_delay_ms(20);
	//LCD_IsBusy();
	//Set the control pins as o/p
	DataDir_LCD_CTRL |= (1 << ENABLE_SWITCH) | (1 << RW_SWITCH) | (1 << RS_SWITCH);
	LCD_CTRL &= ~(1 << ENABLE_SWITCH) | (1 << RW_SWITCH) | (1 << RS_SWITCH);
	LCD_Clear_Screen();
	
	#if	   LCD_MODE ==  EIGHT_BIT_MODE
		   DataDir_LCD_PORT = 0xFF;
		   LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);
		   
	#elif  LCD_MODE ==  FOUR_BIT_MODE
		   DataDir_LCD_PORT |= 0xF0;
		   LCD_WRITE_COMMAND(0x02);
		   LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES_3);
		   LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES_2);
		   LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES_1);
		  
	#endif
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
	
}

void LCD_WRITE_COMMAND(uint8_t command)
{
	//LCD_IsBusy();
	#if	  LCD_MODE == EIGHT_BIT_MODE
		  
		  //Write Command on data pins
		  LCD_PORT = command;
		  //Reset RW & RS
		  LCD_CTRL &= ~(1<<RW_SWITCH);
		  LCD_CTRL &= ~(1<<RS_SWITCH);
		  //turn on enable for 1ms
		  LCD_KICK();
		  _delay_ms(2);
		
	#elif LCD_MODE == FOUR_BIT_MODE
		  //Reset RW & RS
		  LCD_CTRL &= ~(1<<RW_SWITCH);
		  LCD_CTRL &= ~(1<<RS_SWITCH);
		  //Write 4bits of Command on data pins
		  LCD_PORT = (LCD_PORT & 0x0F) | (command & 0xF0);
		  //turn on enable for 1ms
		  LCD_KICK();
		  _delay_ms(5);
		  //Write the other 4bits of Command
		  LCD_PORT = (LCD_PORT & 0x0F) | (command << 4);
		  //turn on enable for 1ms
		  LCD_KICK();
		  _delay_ms(2);
		
	#endif

	
}

void LCD_WRITE_CHAR(uint8_t data)
{
	//LCD_IsBusy();
	#if   LCD_MODE == EIGHT_BIT_MODE
		  //Reset RW
		  LCD_CTRL &= ~(1<<RW_SWITCH);
		  //Set RS (Data Register)
		  LCD_CTRL |= (1<<RS_SWITCH);
		  //Write data on data pins
		  LCD_PORT = data;
		  //turn on enable for 1ms
		  LCD_KICK();
	
	#elif LCD_MODE == FOUR_BIT_MODE
		  //Reset RW
		  LCD_CTRL &= ~(1<<RW_SWITCH);
		  //Set RS (Data Register)
		  LCD_CTRL |= (1<<RS_SWITCH);
		  //Write 4bit of data on pins
		  LCD_PORT = (LCD_PORT & 0x0F) | (data & 0xF0);
		  //turn on enable for 1ms
		  LCD_KICK();
		  _delay_ms(5);
		  //Write the other 4bit of data on pins
		  LCD_PORT = (LCD_PORT & 0x0F) | (data << 4);
		  //turn on enable for 1ms
		  LCD_KICK();
		  _delay_ms(5);
	#endif
	
}
void LCD_WRITE_STRING(uint8_t* data)
{
	uint32_t count = 0;
	while(*data != 0)
	{
		count++;
		LCD_WRITE_CHAR(*(data++));
		if (count == 16)
		{
			LCD_GOTO_XY(2,0);
		}
		else if (count == 32)
		{
			LCD_Clear_Screen();
			LCD_GOTO_XY(1,0);
			count = 0;
		}
	}
}
void LCD_Clear_Screen(void)
{
	LCD_WRITE_COMMAND(LCD_CLEAR_DISPLAY);
}
void LCD_IsBusy(void)
{
	//Set uC pins as input to read data pins of LCD
	#if	  LCD_MODE == EIGHT_BIT_MODE
		  DataDir_LCD_PORT = 0x00;
	#elif LCD_MODE == FOUR_BIT_MODE
	      DataDir_LCD_PORT &= ~(0xFF << DATA_SHIFT);
	#endif
	//DataDir_LCD_CTRL = 
	//RW = Read
	LCD_CTRL |= (1 << RW_SWITCH);
	//RS = Command Mode (off)
	LCD_CTRL &= ~(1 << RS_SWITCH);
	//Disable Enable for ms and enable it
	//To make sure nothing interrupts you
	LCD_KICK();
	//Set uC pins as output connected to data pins of LCD
	#if	  LCD_MODE == EIGHT_BIT_MODE
	DataDir_LCD_PORT = 0xFF;
	#elif LCD_MODE == FOUR_BIT_MODE
	DataDir_LCD_PORT |= 0xF0;
	#endif
	//RW = Write
	LCD_CTRL &= ~(1 << RW_SWITCH);
	
}

void LCD_STORE_Custom_CHARACTER()
{
	LCD_WRITE_COMMAND(64); //0x40
	
	//Loading 1
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00011);
	LCD_WRITE_CHAR(0b00110);
	LCD_WRITE_CHAR(0b01000);
	LCD_WRITE_CHAR(0b11000);
	LCD_WRITE_CHAR(0b10000);
	LCD_WRITE_CHAR(0b10000);
	LCD_WRITE_CHAR(0b10000);
	
	//Loading 2
	LCD_WRITE_CHAR(0b00111);
	LCD_WRITE_CHAR(0b11000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);		
	 
	//Loading 3
	LCD_WRITE_CHAR(0b11100);
	LCD_WRITE_CHAR(0b00011);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	
	//Loading 4
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b10000);
	LCD_WRITE_CHAR(0b11000);
	LCD_WRITE_CHAR(0b00110);
	LCD_WRITE_CHAR(0b00011);
	LCD_WRITE_CHAR(0b00001);
	LCD_WRITE_CHAR(0b00001);
	LCD_WRITE_CHAR(0b00001);
	
	//Loading 5
	LCD_WRITE_CHAR(0b00001);
	LCD_WRITE_CHAR(0b00001);
	LCD_WRITE_CHAR(0b00011);
	LCD_WRITE_CHAR(0b00010);
	LCD_WRITE_CHAR(0b00100);
	LCD_WRITE_CHAR(0b11000);
	LCD_WRITE_CHAR(0b10000);
	LCD_WRITE_CHAR(0b00000);
	
	//Loading 6
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00111);
	LCD_WRITE_CHAR(0b11100);
	
	//Loading 7
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b00000);
	LCD_WRITE_CHAR(0b11000);
	LCD_WRITE_CHAR(0b00111);
	
	//Loading 8
	LCD_WRITE_CHAR(0b10000);
	LCD_WRITE_CHAR(0b10000);
	LCD_WRITE_CHAR(0b11000);
	LCD_WRITE_CHAR(0b01000);
	LCD_WRITE_CHAR(0b00100);
	LCD_WRITE_CHAR(0b00011);
	LCD_WRITE_CHAR(0b00001);
	LCD_WRITE_CHAR(0b00000);
	
	
	/*
	uint8_t Address;
	uint8_t index;
	//8 Locations in CGRAM every location contains 8 bits Add =  (0x00, 0x08, 0x 16 , ...)
	//															 (8*0, 8*1, 8*2, ...)
	if(CGRAM_Index < 8)
	{
		Address = CGRAM_Index * 8 ;
		//Set AC(Add. counter) into CGRAM ADDRESS
		Address |= (1 << 6);
		LCD_WRITE_COMMAND(Address);
		for(index = 0 ; index < 8 ; index++)
		{
			LCD_WRITE_CHAR(pattern[index]);
		}
	}
	//Return Home
	LCD_WRITE_COMMAND(0x02);*/
	
}
void LCD_Display_Custom_CHARACTER(uint8_t CGRAM_Index)
{
	LCD_WRITE_CHAR(CGRAM_Index);
}