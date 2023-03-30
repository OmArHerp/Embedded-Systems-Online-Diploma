/*
 * main.c
 *
 *  Created on: Mar 30, 2023
 *      Author: Omar Alaa
 */

#include <stdio.h>

void main()
{
	float matrix1 [2][2], matrix2 [2][2];
	int i,j;

	printf("Please enter the values of the first matrix\n");
	for(i=0; i<2 ; i++)
	{
		for(j=0; j<2 ;j++)
		{
			printf("Enter [%d][%d]",i,j);
			fflush(stdin); fflush(stdout);
			scanf("%f", &matrix1[i][j]);
		}
	}

	printf("Please enter the values of the second matrix\n");
	for(i=0; i<2 ; i++)
	{
		for(j=0; j<2 ;j++)
		{
			printf("Enter [%d][%d]",i,j);
			fflush(stdin); fflush(stdout);
			scanf("%f", &matrix2[i][j]);
		}
	}

	printf("matrix1 + matrix2 : \n");
	for(i=0; i<2 ; i++)
	{
		for(j=0; j<2 ;j++)
		{
			printf("%f\t",matrix1[i][j] + matrix2[i][j]);
		}
		printf("\r\n");
	}
}
