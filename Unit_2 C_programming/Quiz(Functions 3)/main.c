/*
 * main.c
 *
 *  Created on: May 11, 2023
 *      Author: OmArHerp
 */

#include<stdio.h>
#include<string.h>

void ClearBit(int *x, int);

int main()
{
	int x; int bit;
	printf("Enter the number: ");
	fflush(stdout);
	scanf("%d",&x);
	printf("\nWhat nth bit you wanna clear:");
	fflush(stdout);
	scanf("%d",&bit);
	ClearBit(&x,bit);
	printf("Result = %d",x);
	return 0;
}

void ClearBit(int *x,int bit)
{
	*x &= ~(1<<bit);

}
