/*
 * main.c
 *
 *  Created on: Mar 24, 2023
 *      Author: Dell
 */

#include<stdio.h>

void main()
{
	char x =0;
	printf("Please Enter the value you wanna see it's ASCII: ");
	fflush(stdin); fflush(stdout);
	scanf("%c",&x);
	printf("\nThe ASCII value of %c is %d",x,x);
}
