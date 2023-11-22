/*
 * main.c
 *
 *  Created on: Nov 20, 2023
 *      Author: Herp
 */

#include "CA.h"

void setup()
{
	//init all the drivers
	//init IRQ....
	//init HAl US_Driver DC_Driver
	//Init Block
	//Set States pointers for each Block
	CA_state = STATE(CA_waiting);
}

void main()
{
	setup();

	while(1)
	{
		//call state for each block
		CA_state();
	}
}
