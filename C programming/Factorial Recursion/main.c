/*
 * main.c
 *
 *  Created on: Apr 22, 2023
 *      Author: OmArHerp
 */
#include <stdio.h>
#include <stdlib.h>

int Factorial(int);

int main(void)
{
	int n=0;
	printf("Please Enter the number you want to know the factorial of: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);

	printf("\nFactorial of !%d is %d",n,Factorial(n));
	return 0;
}

int Factorial(int x)
{
	if(x == 1)
		return 1;
	return x * Factorial(x-1);

}


