/*
 * main.c
 *
 *  Created on: May 11, 2023
 *      Author: OmArHerp
 */

#include<stdio.h>
#include<string.h>


int Last_Occ(int,int arr1[]);

int main()
{
	int arr[10]= {1,1,6,8,9,4,2,2,6,7};
	int x = 0;
	printf("Enter the number you want to know its last occurrence: ");
	fflush(stdout);
	scanf("%d",&x);


	int Ret = Last_Occ(x, arr);
	if(Ret == -1)
		printf("\nNo such Number");
	else
		printf("\nThe Last Occurrence of %d is %d",x,Ret);

	return 0;
}

int Last_Occ(int a, int arr1[])
{
	int i;
	for(i=10-1; i>=0; i--)
	{
		if(arr1[i] == a)
			return i;
	}

	return -1;
}
