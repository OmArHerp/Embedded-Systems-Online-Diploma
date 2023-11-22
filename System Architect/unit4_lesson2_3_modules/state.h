/*
 * state.h
 *
 *  Created on: Nov 20, 2023
 *      Author: Dell
 */

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>
//Automatic STATE Function generated
#define STATE_define(_statFUN_)	void ST_##_statFUN_()
#define STATE(_statFUN_)	ST_##_statFUN_



//States Connection
void US_Set_distance (int d);
void DC_motor(int S);

#endif /* STATE_H_ */
