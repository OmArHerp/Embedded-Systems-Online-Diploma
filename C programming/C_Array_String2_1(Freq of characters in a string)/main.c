/*
 * main.c
 *
 *  Created on: Mar 31, 2023
 *      Author: Dell
 */

#include<stdio.h>
#include<string.h>

int main()
{
	char string1[100]; char c; int i=0; int count=0;
	printf("please enter the string first:\n");
	fflush(stdout);fflush(stdin);
	gets(string1);
	strlwr(string1);
	printf("\r\n");
	printf("Now enter the character you want to know it's frequency: ");
	fflush(stdout);fflush(stdin);
	scanf("%c",&c);


	if(c>=65 && c<=90)
		c = c+32;

	while(string1[i] != '\0')
	{
		if(string1[i] == c)
			count++;
		i++;
	}
	printf("\r\n");
	printf("Frequency of %c = %d",c ,count);
	return 0;
}

