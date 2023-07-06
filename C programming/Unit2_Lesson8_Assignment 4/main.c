/*
 * main.c
 *
 *  Created on: Jul 3, 2023
 *      Author: OmArHerp
 */

#include<stdio.h>
#include<string.h>


int main()
{
	int arr[15]; int n; int i;
	printf("Enter the number of elements you want (max 15) : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&n);
	for(i=0 ; i<n ; i++)
	{
		printf("\nEnter element number %d : ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",arr+i);
	}
	int *p = arr;
	p+=(n-1);
	while(p != arr)
	{
		printf("%d  ",*p);
		--p;
	}
	printf("%d  ",*p);

	return 0;
}

