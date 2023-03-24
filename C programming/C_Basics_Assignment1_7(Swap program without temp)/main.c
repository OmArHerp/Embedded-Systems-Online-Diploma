/*
 * main.c
 *
 *  Created on: Mar 24, 2023
 *      Author: Dell
 */

#include<stdio.h>

void main ()
{
	int x,y;

	printf("Enter the two number you wanna swap: ");
	fflush(stdout);
	scanf("%d%d",&x,&y);
	printf("X is %d, Y is %d Before swapping",x,y);

	x = x+y;
	y = x-y;
	x = x-y;


	printf("\nX is %d, Y is %d After swapping",x,y);
}
