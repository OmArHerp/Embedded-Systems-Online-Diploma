/*
 * Unit7_Lesson1(GPIO)_Section_Assignment1.c
 *
 * Created: 10/6/2023 1:19:18 AM
 * Author : Herp
 */ 

//#include <avr/io.h>
#include "Registers.h"
#include "Bit_Manipulation.h"


enum Status {
	Not_Pressed,
	Pressed,
	LED1,
	LED2,
	LED3
};

void GPIO_init();
void Delay(int);

int main(void)
{
	GPIO_init();
	enum Status led = LED1;
    /* Replace with your application code */
    while (1) 
    {
		if(GetBit(PIND,0) == Pressed)
		{
			Delay(1);
			while(GetBit(PIND,0) == Pressed);
			switch(led)
			{
				case LED1: ClrBit(PORTD,7);
						   SetBit(PORTD,5); ++led;	
						   break;
				case LED2: ClrBit(PORTD,5); 
						   SetBit(PORTD,6); ++led;		
						   break;
				case LED3: ClrBit(PORTD,6); 
						   SetBit(PORTD,7); 
						   led = LED1;
						   break;
				default: break;
				
			}
		}
		
	}
}

void GPIO_init()
{
	SetBit(DDRD,7);
	SetBit(DDRD,6);
	SetBit(DDRD,5);
	ClrBit(DDRD,0);
}

void Delay(int count)
{
	unsigned char i=0;
	while(count)
	{
		for(i=0 ; i<255 ; i++);
		--count;
	}
}