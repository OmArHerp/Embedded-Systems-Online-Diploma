/*
 * main.c
 *
 *  Created on: Apr 22, 2023
 *      Author: OmArHerp
 */

#include<stdio.h>

int Power_Function(int , int);

int main(void)
{
	int n,m;
	printf("Please Enter the base and the power: ");
	fflush(stdin);fflush(stdout);
	scanf("%d%d",&n,&m);

	printf("%d power of %d is %d",n,m,Power_Function(n,m));

	return 0;
}
int Power_Function(int x, int y)
{
	if(y == 1)
		return x;
	return x * Power_Function(x,y-1);
}
