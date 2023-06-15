/*
 * main.c
 *
 *  Created on: Jun 13, 2023
 *      Author: OmArHerp
 */

#include<stdio.h>
#include<stdlib.h>

#define Pi			3.14
#define Area(r)		r*r*Pi

int main()
{
	float Radius; float Area;
	printf("Enter the radius : ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&Radius);

	Area = Area(Radius);

	printf("\nArea = %f",Area);



	return 0;

}

