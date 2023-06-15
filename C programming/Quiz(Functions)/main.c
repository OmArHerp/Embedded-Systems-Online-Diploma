/*
 * main.c
 *
 *  Created on: May 11, 2023
 *      Author: OmArHerp
 */

#include<stdio.h>
#include<string.h>


void Reverse_String(int [],int,int [],int);

int main()
{
	int arr1[100], arr2[100];
	int n1,n2,i;
	printf("Enter the size of the first array:");
	fflush(stdout);
	scanf("%d",&n1);
	printf("\nNow Enter the elements of the first array: ");
	for(i=0;i<n1;i++)
	{
		fflush(stdout);
		scanf("%d",&arr1[i]);

	}

	printf("\nEnter the size of the Second array:");
	fflush(stdout);
	scanf("%d",&n2);

	printf("\nNow Enter the elements of the Second array: ");
	for(i=0;i<n2;i++)
	{
		fflush(stdout);
		scanf("%d",&arr2[i]);
	}

	printf("Elements of first array\n\r"); //New Line
	for(i=0;i<n1;i++)
	{
		printf("%d ",arr1[i]);
	}

	printf("\nElements of Second array\n\r"); //New Line
	for(i=0;i<n2;i++)
	{
		printf("%d ",arr2[i]);
	}

	Reverse_String(arr1,n1,arr2,n2);
	printf("\n array 1 after swapping:\n");
	for(i=0;i<n2;i++)
		{
			printf("%d ",arr1[i]);
		}

	printf("\n array 2 after swapping:\n");
		for(i=0;i<n1;i++)
			{
				printf("%d ",arr2[i]);
			}
	return 0;
}

void Reverse_String(int arr1[],int n1,int arr2[],int n2)
{
	int temp = 0;
	int i;
	for(i=0;i<n1;i++)
		{
			temp = arr1[i];
			arr1[i] = arr2[i];
			arr2[i]	= temp;
		}
}
