/*
 * main.c
 *
 *  Created on: May 6, 2023
 *      Author: OmArHerp
 */

#include<stdio.h>
#include<string.h>

char Reverse(char arr[] , int);

int main()
{
	char str[100] =""; int Length = 0;
	printf("Enter the string you wanna reverse:");
	fflush(stdin);fflush(stdout);
	gets(str);
	Length = strlen(str);
	Reverse(str,Length);
	return 0;
}

char Reverse(char arr[], int i)
{
	if(i==-1)
	{
		return arr[i];
	}
	else
	{
		printf("%c", arr[i]);
		--i;
		return Reverse(arr, i);
	}
}
