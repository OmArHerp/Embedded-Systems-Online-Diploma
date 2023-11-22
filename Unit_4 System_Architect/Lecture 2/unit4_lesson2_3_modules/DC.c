/*
 * DC.c
 *
 *  Created on: Nov 20, 2023
 *      Author: Herp
 */

#include "DC.h"
//variables
int DC_speed = 0;


//STATE Pointer to function
void (*DC_state)();


void DC_init ()
{
	//init PWM
	printf("DC_init \n");
}

void DC_motor(int S)
{
	DC_speed = S;
	DC_state = STATE(DC_busy);
	printf("CA ------speed=%d--------> DC ",DC_speed);

}

STATE_define(DC_idle)
{
	//state_Name
	DC_state_id = DC_idle;

	//state_Action
	//CALL PWM to make speed = DC_speed

	printf("DC_idle State: Speed=%d \n", DC_speed);

}

STATE_define(DC_busy)
{
	//state_Name
	DC_state_id = DC_busy;

	//state_Action
	//DC_Motor

	DC_state = STATE(DC_idle);

	printf("DC_busy State: Speed=%d \n", DC_speed);

}
