/*
 * main.c
 *
 *  Created on: Mar 24, 2023
 *      Author: Dell
 */

#include<stdio.h>

void main()
{
	char x = 0;
	printf("Enter the Character to check whether it's an alphabet or not\n");
	fflush(stdout);
	scanf("%c",&x);
	if((x>=65 && x<=90) || (x>=97 && x<=122))
		{
			printf("\nAlphabet indeed.");
		}
		else
		{
			printf("Not an alphabet");
		}
}

