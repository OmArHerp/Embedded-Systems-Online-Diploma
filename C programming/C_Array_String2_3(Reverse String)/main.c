/*
 * main.c
 *
 *  Created on: Mar 31, 2023
 *      Author: OmArHerp
 */

#include<stdio.h>
#include<string.h>

int main()
{
	char string1[100];
	int i;

	printf("Enter the string : ");
	fflush(stdin);fflush(stdout);
	gets(string1);
	printf("\r\n");
	for(i=strlen(string1); i>=0 ;i--)
	{
		printf("%c",string1[i]);
	}




	return 0;
}

