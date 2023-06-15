/*
 * main.c
 *
 *  Created on: May 11, 2023
 *      Author: OmArHerp
 */

#include<stdio.h>
#include<string.h>

int main()
{
	int x,_4thBit;
	printf("Enter the number:");
	fflush(stdout);
	scanf("%d",&x);
	_4thBit = ((x>>3) & 1);
	printf("\nThe 4th bit = %d",_4thBit);


	return 0;
}

