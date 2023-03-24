/*
 * main.c
 *
 *  Created on: Mar 24, 2023
 *      Author: Dell
 */

#include<stdio.h>

void main()
{
	int i = 0; int j = 0;

	for(i=0; i<=9 ; i++)
	{
		j=i;
		for(j; j<=9 ; j++)
		{
		   printf("%d ",j);
		}
		printf("\r\n");

	}
}
