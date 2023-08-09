/*
 * main.c
 *
 *  Created on: Aug 5, 2023
 *      Author: OmArHerp
 */
#include <stdio.h>
#include <stdlib.h>
#include "LIFO.h"

unsigned int buffer1[5];




int main()
{
	int i, temp = 0;
	LIFO_Buf_t uart_lifo , I2C_lifo ;
	//static allocation
	LIFO_Init(&uart_lifo ,buffer1, 5);
	//dynamic allocation
	uint32_t* buffer2 =(uint32_t*) malloc(5 * sizeof(uint32_t));
	LIFO_Init(&I2C_lifo ,buffer2, 5);

	//pushing uart
	for(i=0; i<5 ; i++)
	{
		if (	LIFO_Push(&uart_lifo, i) == LIFO_No_Error )
			printf("UART_LIFO add : %d \n",i);
	}

	//poping uart
	for(i=0; i<5 ; i++)
	{
		if (	LIFO_Pop(&uart_lifo, &temp) == LIFO_No_Error )
			printf("UART_LIFO Remove : %d \n",temp);
	}



	return 0;
}
