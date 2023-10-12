/*
 * Unit7_Lesson1_Assignment3_7SegmentMultiplixing.c
 *
 * Created: 10/8/2023 4:56:53 PM
 * Author : Herp
 */ 

//#include <avr/io.h>
#include <util/delay.h>

#include "Reg.h"
#define SetBit(Reg,Bit)		(Reg |= (1<<Bit))
#define ClrBit(Reg,Bit)		(Reg &= ~(1<<Bit))
#define	PD0					0
#define PD1					1
#define SevSegment1_EN		PD0
#define SevSegment2_EN		PD1

void GPIO_init();
void delay(unsigned int );
void Seven_Segment_Enable1();
void Seven_Segment_Enable2();
void Seven_Segment_Disable1();
void Seven_Segment_Disable2();

int main(void)
{
	GPIO_init();
	unsigned char i,j,count;
    /* Replace with your application code */
    while (1) 
    {	
		for(i=0; i<10 ; i++)
		{
			for(j=0; j<10 ; j++)
			{
				for(count =0; count < 20 ; count++)
				{
					Seven_Segment_Enable1();
					Seven_Segment_Disable2();
					PORTC = 0b0000 | i;
					_delay_ms(25);
					Seven_Segment_Disable1();
					Seven_Segment_Enable2();
					PORTC = 0b0000 | j;
					_delay_ms(25);
				}
			}
			
		}
		
    }
}

void GPIO_init()
{
	DDRC = 0x0f;
	DDRD = 0x03;
	
}

void delay(unsigned int x)
{
	unsigned char i;
	while(x)
	{
		for(i=0 ; i<255 ; i++);
		--x;
	}
	
}
void Seven_Segment_Enable1()
{
	ClrBit(PORTD,SevSegment1_EN);
}
void Seven_Segment_Enable2()
{
	ClrBit(PORTD,SevSegment2_EN);
}
void Seven_Segment_Disable1()
{
	SetBit(PORTD,SevSegment1_EN);
}
void Seven_Segment_Disable2()
{
	SetBit(PORTD,SevSegment2_EN);
}