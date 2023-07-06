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
	char *Pa = 0;
	char Alpha[26];
	int startup = 65;
	int i;
	for(i=0; i<26 ;i++,startup++)
	{
		Alpha[i] = startup;
	}

	Pa = Alpha;
	for(i=0; i<26 ;i++)
		{
			printf("%c ",*Pa);
			Pa++;
		}





	return 0;
}


