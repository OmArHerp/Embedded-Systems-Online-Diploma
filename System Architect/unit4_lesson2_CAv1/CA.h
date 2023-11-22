/*
 * CA.h
 *
 *  Created on: Nov 20, 2023
 *      Author: Herp
 */

#ifndef CA_H_
#define CA_H_

#include "state.h"

enum {
	CA_waiting,
	CA_driving
}CA_state_id;

//declare states functions CA
STATE_define(CA_waiting);
STATE_define(CA_driving);


extern void (*CA_state)();

#endif /* CA_H_ */
