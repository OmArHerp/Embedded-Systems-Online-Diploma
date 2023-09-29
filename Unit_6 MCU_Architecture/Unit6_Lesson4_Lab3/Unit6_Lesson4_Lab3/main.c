/*
 * Unit6_Lesson4_Lab3.c
 *
 * Created: 9/28/2023 6:41:34 PM
 * Author : Dell
 */ 

# define F_CPU 1600000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>



void GPIO_Init()
{
	DDRD |= (0b111 << 5);
	DDRD &= ~(1 << 2);
	DDRD &= ~(1 << 3);
	DDRB &= ~(1 << 2);
}
void Interrupt_init()
{
	//EXT0 Logical Change
	MCUCR |= 0b01;
	//EXT1 Rising Edge
	MCUCR |= (0b11 << 2);
	//EXT2 Falling Edge
	MCUCSR &= ~(1 << 6);
	//Enable EXT0,1,2
	GICR |= (0b111 << 5);
	//Enable GIE
	SREG |= (1 << 7);
	
}

int main(void)
{
	GPIO_Init();
	Interrupt_init();
    /* Replace with your application code */
    while (1) 
    {
		PORTD &= ~(1 << 5);
		PORTD &= ~(1 << 6);
		PORTD &= ~(1 << 7);
    }
}

ISR(INT0_vect)
{
	PORTD |= (1 << 5);
	_delay_ms(1000);
	
}
ISR(INT1_vect)
{
	PORTD |= (1 << 6);
	_delay_ms(1000);
	
}
ISR(INT2_vect)
{
	PORTD |= (1 << 7);
	_delay_ms(1000);
}

