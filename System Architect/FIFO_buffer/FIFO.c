/*
 * FIFO.c
 *
 *  Created on: Aug 5, 2023
 *      Author: OmArHerp
 */

#include "FIFO.h"

FIFO_status FIFO_Init(FIFO_Buf_t* queue , DataType* buf, uint32_t length)
{
	if (buf == NULL)
		return FIFO_Null ;
	queue->base = buf;
	queue->head = buf;
	queue->tail = buf;
	queue->length = length;
	queue->count = 0;

	return FIFO_No_Error ;

}
FIFO_status FIFO_Enqueue(FIFO_Buf_t* queue , DataType  item)
{
	if(!queue->base || !queue->head || !queue ->tail)
		return FIFO_Null ;

	//If Queue is full
	if (FIFO_Is_Full(queue) == FIFO_Full)
		return FIFO_Full ;

	*(queue->head) = item;
	queue->count++;
	//Circular Queue
	if(queue->head >= queue->base + ( queue->length * sizeof(DataType) ) )
		queue->head = queue->base;
	else
		queue->head++ ;

	return FIFO_No_Error ;

}
FIFO_status FIFO_Dequeue (FIFO_Buf_t* queue , DataType* item)
{
	if(!queue->base || !queue->head || !queue ->tail)
		return FIFO_Null ;
	if(FIFO_Is_Empty(queue) == FIFO_Empty)
		return FIFO_Empty ;

	*item = *(queue->tail);
	queue->count--;
	//Circular
	if(queue->tail >= queue->base + ( queue->length * sizeof(DataType) ) )
		queue->tail = queue->base;
	else
		queue->tail++ ;

	return FIFO_No_Error ;

}
FIFO_status FIFO_Is_Full (FIFO_Buf_t* queue)
{
	if(!queue->base || !queue->head || !queue ->tail)
		return FIFO_Null ;
	if(queue->count == queue->length)
		return FIFO_Full ;
	return FIFO_No_Error ;

}
FIFO_status FIFO_Is_Empty (FIFO_Buf_t* queue)
{
	if(!queue->base || !queue->head || !queue ->tail)
		return FIFO_Null ;
	if(queue->count == 0)
		return FIFO_Empty ;
	return FIFO_No_Error ;

}
void FIFO_Print (FIFO_Buf_t* queue)
{
	DataType* temp;
	int i;
	if(queue->count ==0)
	{
		printf("Queue is Empty \n");
	}
	else
	{
		temp = queue->tail ;
		printf("\n =======fifo_print======\n");
		for(i=0 ; i< queue->count ; i++)
		{
			printf("\t %X \n", *temp);
			temp++;
		}
		printf("=========\n");

	}
}
