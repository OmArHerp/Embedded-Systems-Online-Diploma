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
	char string1[100]; int count=0, i;
	printf("Please enter the string:\n");
	fflush(stdin);fflush(stdout);
	gets(string1);
	for(i=0; string1[i]!=0 ;i++)
	{
		count++;
	}
	printf("\r\nThe lenth of the string is %d",count);
	return 0;
}

