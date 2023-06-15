/*
 * main.c
 *
 *  Created on: Apr 22, 2023
 *      Author: OmArHerp
 */

#include<stdio.h>
void Prime_Number(int , int);

int main()
{
	int a,b;
	printf("Please Enter two numbers \"The Interval\" :\n\r");
	fflush(stdin);fflush(stdout);
	scanf("%d%d",&a,&b);

	Prime_Number(a,b);

	return 0;
}

void Prime_Number(int x, int y)
{
	int j;
	int Prime = 1;
	for(; x<=y ; x++)
	{
		for(j=2 ; j<x ; j++)
		{
			if(x%j == 0)
			{
				Prime = 0; //Not Prime
			}
		}
		if(Prime == 1)
			printf("%d ",x);
		else
			Prime = 1;
	}
}

