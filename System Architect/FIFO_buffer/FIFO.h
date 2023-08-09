/*
 * FIFO.h
 *
 *  Created on: Aug 5, 2023
 *      Author: OmArHerp
 */

#ifndef FIFO_H_
#define FIFO_H_

				/* Note :- This Driver only works for static memory allocation */

/*****************************************_Includes_*******************************************/
#include<stdint.h>
#include<stdio.h>


/**************************************_DataType_Config***************************************/
									/*choose the data type*/
#define DataType		uint8_t

//creating a buffer
#define width 5
DataType buff[width];

/**************************************_Data_Definitions**************************************/
typedef struct {
	DataType  length;
	DataType  count;
	DataType* base;
	DataType* head;
	DataType* tail;

}FIFO_Buf_t;

typedef enum {
	FIFO_No_Error,
	FIFO_Full,
	FIFO_Empty,
	FIFO_Null //No Array or the user is passing dynamic memory allocation (returned null)
}FIFO_status;

/******************************************_ADT_***********************************************/
FIFO_status FIFO_Init(FIFO_Buf_t* queue , DataType* buf, uint32_t length);
FIFO_status FIFO_Enqueue(FIFO_Buf_t* queue , DataType  item);
FIFO_status FIFO_Dequeue (FIFO_Buf_t* queue , DataType* item);
FIFO_status FIFO_Is_Full (FIFO_Buf_t* queue);
FIFO_status FIFO_Is_Empty (FIFO_Buf_t* queue);
void FIFO_Print (FIFO_Buf_t* queue);






#endif /* FIFO_H_ */
