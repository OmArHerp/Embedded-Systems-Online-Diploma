/*
 * main.c
 *
 *  Created on: Mar 31, 2023
 *      Author: OmArHerp
 */

#include<stdio.h>

void main()
{
	int matrix1[10][10], matrix2[10][10];
	int n,m,i,j;
	printf("Please Enter size of rows/columns: ");
	fflush(stdout);
	scanf("%d%d",&n,&m);

	printf("\r\n");
	for(i=0; i<n ;i++)
	{
		for(j=0; j<m ;j++)
		{
			printf("\nEnter [%d][%d]",i,j);
			fflush(stdout);
			scanf("%d",&matrix1[i][j]);
		}
	}

	printf("\nEntered Matrix:\n");
	for(i=0; i<n ;i++)
	{
		for(j=0; j<m ;j++)
		{
			printf("%d\t",matrix1[i][j]);
		}
		printf("\n");
	}

	for(i=0; i<n ;i++)
	{
		for(j=0; j<m ;j++)
		{
			matrix2[j][i] = matrix1[i][j];
		}
	}

	fflush(stdout);
	printf("\r\nTranspose Matrix:\n");
	for(i=0; i<m ;i++)
	{
		for(j=0; j<n ;j++)
		{
			printf("%d\t",matrix2[i][j]);
		}
		printf("\n");
	}

}

