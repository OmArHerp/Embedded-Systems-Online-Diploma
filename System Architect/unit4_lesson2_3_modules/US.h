/*
 * US.h
 *
 *  Created on: Nov 20, 2023
 *      Author: Herp
 */

#ifndef US_H_
#define US_H_

#include "state.h"

enum {
	US_busy,
}US_state_id;

//declare states functions US
STATE_define(US_busy);


void US_init();

//STATE Pointer to function
extern void (*US_state)();

#endif /* US_H_ */
