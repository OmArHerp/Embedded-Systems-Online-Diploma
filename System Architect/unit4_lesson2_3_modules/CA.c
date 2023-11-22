/*
 * CA.c
 *
 *  Created on: Nov 20, 2023
 *      Author: Herp
 */

#include "CA.h"
//variables
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

//STATE Pointer to function
void (*CA_state)();



void US_Set_distance (int d)
{
	CA_distance = d ;
	(CA_distance <= CA_threshold) ? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving)) ;
	printf("US ------distance=%d--------> CA ",CA_distance);

}

STATE_define(CA_waiting)
{
	//state_Name
	CA_state_id = CA_waiting;
	printf("CA_Waiting State: distance =%d Speed=%d \n",CA_distance , CA_speed);

	//state_Action
	//DC_Motor
	CA_speed = 0;
	DC_motor(CA_speed);
}

STATE_define(CA_driving)
{
	//state_Name
	CA_state_id = CA_driving;
	printf("CA_Waiting State: distance =%d Speed=%d \n",CA_distance , CA_speed);


	//state_Action
	CA_speed = 30;
	DC_motor(CA_speed);
}

