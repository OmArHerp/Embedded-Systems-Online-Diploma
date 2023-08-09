/*
 * LIFO.h
 *
 *  Created on: Aug 5, 2023
 *      Author: OmArHerp
 */

#ifndef LIFO_H_
#define LIFO_H_

				/* Note :- This Driver only works for static memory allocation */

/*****************************************_Includes_*******************************************/
#include<stdint.h>
#include<stdio.h>


/**************************************_DataType_Config***************************************/
									/*choose the data type*/
#define DataType		uint32_t

/**************************************_Data_Definitions**************************************/
typedef struct {
	DataType  length;
	DataType  count;
	DataType* base;
	DataType* head;

}LIFO_Buf_t;

typedef enum {
	LIFO_No_Error,
	LIFO_Full,
	LIFO_Empty,
	LIFO_Null //No Array or the user is passing dynamic memory allocation (returned null)
}LIFO_status;

/******************************************_ADT_***********************************************/
LIFO_status LIFO_Init(LIFO_Buf_t* stack,DataType* buf, unsigned int length);
LIFO_status LIFO_Push(LIFO_Buf_t* stack,DataType  item);
LIFO_status LIFO_Pop (LIFO_Buf_t* stack,DataType* item);


#endif /* LIFO_H_ */
