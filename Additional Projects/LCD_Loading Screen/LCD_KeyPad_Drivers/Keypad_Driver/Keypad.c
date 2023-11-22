/*
 * Keypad.c
 *
 * Created: 10/19/2023 4:14:25 AM
 *  Author: Herp
 */ 

#include "Keypad.h"

uint8_t Keypad_R[] = {R0, R1, R2, R3};
uint8_t Keypad_C[] = {C0, C1, C2, C3};

void KEYPAD_Init()
{
	//Rows as input
	DataDir_KEYPAD_PORT &= ~(1<<R0);
	DataDir_KEYPAD_PORT &= ~(1<<R1);
	DataDir_KEYPAD_PORT &= ~(1<<R2);
	DataDir_KEYPAD_PORT &= ~(1<<R3);
	//Columns  as output
	DataDir_KEYPAD_PORT |= ((1<<C0) | (1<<C1) | (1<<C2) | (1<<C3));
	//Pull Up Resistors On & Vcc on output pins
	KEYPAD_PORT = 0xFF;
}

uint8_t KEYPAD_GETCHAR()
{
	uint8_t i,j;
	for(i=0 ; i < 4 ; i++)
	{
		KEYPAD_PORT |= ((1 << Keypad_C[0]) | (1 << Keypad_C[1]) | (1 << Keypad_C[2]) | (1 << Keypad_C[3]));
		KEYPAD_PORT &= ~(1<<Keypad_C[i]); //Send a low to a particular row of the keypad
		
		for(j=0 ; j < 4 ; j++)
		{
			if(!(KEYPAD_PIN & (1<<Keypad_R[j])))//check if key is pressed 
			{
				while(!(KEYPAD_PIN & (1<<Keypad_R[j]))); //Single Press
				switch(i)
				{
					case(0):
						if(j==0) return '7';
						else if(j == 1) return '4';
						else if(j == 2) return '1';
						else if(j == 3) return '!';
						break;
						
					case(1):
						if(j==0) return '8';
						else if(j == 1) return '5';
						else if(j == 2) return '2';
						else if(j == 3) return '0';
						break;
					
					case(2):
						if(j==0) return '9';
						else if(j == 1) return '6';
						else if(j == 2) return '3';
						else if(j == 3) return '0';
						break;
					
					case(3):
						if(j==0) return '/';
						else if(j == 1) return '*';
						else if(j == 2) return '-';
						else if(j == 3) return '+';
						break;
					
					
				}
			}
		}
	}
	return 'N';
}