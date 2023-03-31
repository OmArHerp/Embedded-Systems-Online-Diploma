/*
 * main.c
 *
 *  Created on: Mar 31, 2023
 *      Author: OmArHerp
 */

#include<stdio.h>

void main()
{
	int x;
	int i;
	int p;
	int element;
	int arr[25]={0};
	int temp;

	printf("Enter the size of the array: ");
	fflush(stdout);
	scanf("%d",&x);
	fflush(stdout);
	printf("\n array before inserting :\n");
	for(i=0; i<x ;i++)
	{
		arr[i]= i+1; // arr[100] = {1,2,3,...,x} at i = x - 1
		printf("%d",arr[i]);
	}

	printf("\n Enter the element you want to insert in the array & it's position: ");
	fflush(stdout);
	scanf("%d%d",&element,&p);


	for(i=x; i>p-1 ;i--)
	{
		arr[i+1] = arr[i];
	}
	arr[p] = arr[p-1];
	arr[p-1] = element;
	printf("\n array After inserting :\n");
	for(i=0; i<x+1 ;i++)
	{
		printf("%d",arr[i]);
	}

}

