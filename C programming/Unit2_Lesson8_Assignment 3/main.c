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
	char str[80];
	gets(str);
	char* Px = str;
	while(*Px != 0)
	{
		Px++;
	}
	while(str != Px)
	{
		printf("%c",*Px);
		Px--;
	}
	printf("%c",*Px);


	return 0;
}


