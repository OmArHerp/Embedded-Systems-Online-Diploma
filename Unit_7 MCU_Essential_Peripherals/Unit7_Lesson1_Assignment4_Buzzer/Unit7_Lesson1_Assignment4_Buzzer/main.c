/*
 * Unit7_Lesson1_Assignment4_Buzzer.c
 *
 * Created: 10/12/2023 2:57:19 AM
 * Author : Dell
 */ 

#include "Reg.h"
#include "util/delay.h"
#define SetBit(Reg,Bit)		(Reg |= (1<<Bit))
#define ClrBit(Reg,Bit)		(Reg &= ~(1<<Bit))
#define GetBit(Reg,Bit)		((Reg >> Bit) & 1)
#define PD0			0
#define PD1			1
#define PD2			2
#define PD3			3
#define PD4			4
#define Pressed		1

void GPIO_init();

int main(void)
{
	GPIO_init();
    /* Replace with your application code */
    while (1) 
    {
		_delay_ms(20);
		if(GetBit(PIND,PD0) == Pressed)
		{
			while(GetBit(PIND,PD0) == Pressed);
			SetBit(PORTD,PD4);
			_delay_ms(1000);
			ClrBit(PORTD,PD4);
		}
	}
}

void GPIO_init()
{
	//preparing PushButton (Pull Down)
	ClrBit(DDRD,PD0);
	//Preparing Relay connected with buzzer
	SetBit(DDRD,PD4);
}