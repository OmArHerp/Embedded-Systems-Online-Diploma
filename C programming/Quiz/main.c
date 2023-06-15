/*
 * main.c
 *
 *  Created on: May 7, 2023
 *      Author: OmArHerp
 */

#include<stdio.h>
#include<string.h>

void Reverse_arr(int arr[],int);
int Pow_3(int );
int main()
{
	int arr[6] = {2,8,4,1,0,9}; int i;
	printf("Before Reversing: ");
	for(i=0; i<sizeof(arr)/4; i++)
	{
		printf("%d ",arr[i]);
	}

	printf("\n After Reversing: ");
	Reverse_arr(arr,6);

	for(i=0; i<sizeof(arr)/4; i++)
		{
			printf("%d ",arr[i]);
		}
	printf("\n Power of 3 program: ");
	printf("Power of 3, %d ======> %d",9,Pow_3(1));

	return 0;
}

void Reverse_arr(int arr[],int n)
{
	int i;
	int t=0;
	int l=n-1;
	for(i=0; i<n/2; i++)
		{
			t = arr[i];
			arr[i] = arr[l];
			arr[l] = t;
			l--;
		}
}

int Pow_3(int n)
{
     if(n%3 == 0 || n == 0)
     {
    	 return 0;
     }
     else
     {
    	 return 1;
     }


}

