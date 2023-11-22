/*
 * US.c
 *
 *  Created on: Nov 20, 2023
 *      Author: Herp
 */

#include "US.h"

//variables
int US_distance = 0;

int US_Get_distance_random(int l, int r, int count);
//STATE Pointer to function
void (*US_state)();


void US_init()
{
	//init US Driver
	printf("US_init \n");
}
STATE_define(US_busy)
{
	//state_Name
	US_state_id = US_busy;

	//state_Action
	US_distance = US_Get_distance_random(45, 55 , 1) ;
	printf("US_Waiting State: distance =%d \n",US_distance);
	US_Set_distance(US_distance);
	US_state = STATE(US_busy);
}


int US_Get_distance_random(int l, int r, int count)
{
	//Generates random number from range l ~ r
	int i;
	for(i=0; i < count ; i++)
	{
		int rand_num = (rand() % (r -1 + 1)) + 1;
		return rand_num;
	}

}
