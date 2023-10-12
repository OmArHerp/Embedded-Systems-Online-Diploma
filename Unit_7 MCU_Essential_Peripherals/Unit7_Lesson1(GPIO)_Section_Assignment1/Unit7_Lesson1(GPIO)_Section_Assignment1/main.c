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
	LED1 = 5,
	LED2,
	LED3
	};

enum Status led = LED1;
void GPIO_init();
void Delay(int);

int main(void)
{
	GPIO_init();
    /* Replace with your application code */
    while (1) 
    {
		if(GetBit(PIND,0) == Pressed && (led < 8))
		{
			while(GetBit(PIND,0) == Pressed);
			Delay(1);
			SetBit(PORTD,led);
			led++;
		}
		else if ((GetBit(PIND,0) == Pressed) && (led >= 8))
		{
			while(GetBit(PIND,0) == Pressed);
			Delay(1);
			switch(led)
			{
				case 8: ClrBit(PORTD,LED3); led ++; break;
				case 9: ClrBit(PORTD,LED2); led ++; break;
				case 10:ClrBit(PORTD,LED1); led = LED1;  break;
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