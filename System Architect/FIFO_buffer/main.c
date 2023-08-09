/*
 * main.c
 *
 *  Created on: Aug 5, 2023
 *      Author: OmArHerp
 */

#include "FIFO.h"

DataType uart_buffer[5];
int main()
{

	FIFO_Buf_t FIFO_UART;
	int i, temp;
	if (FIFO_Init(&FIFO_UART  , uart_buffer , 5) == FIFO_No_Error)
		printf("Fifo init -------Done \n");

	for(i=0 ; i<7 ; i++)
	{
		printf("FIFO Enqueue (%x) \n",i);
		if (FIFO_Enqueue(&FIFO_UART  ,i) == FIFO_No_Error)
			printf("\t Fifo enqueue -------Done \n");
		else
			printf("\t Fifo dequeue -------Failed \n");
	}

	FIFO_Print(&FIFO_UART);
	//Dequeue 2 times
	if (FIFO_Dequeue(&FIFO_UART  ,&temp) == FIFO_No_Error)
				printf("Fifo dequeue %x -------Done \n",temp);
	if (FIFO_Dequeue(&FIFO_UART  ,&temp) == FIFO_No_Error)
					printf("Fifo dequeue %x -------Done \n",temp);
	FIFO_Print(&FIFO_UART);


	return 0;

}


