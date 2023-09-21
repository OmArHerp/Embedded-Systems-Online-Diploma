/*
 * main.c
 *
 *  Created on: Jun 15, 2023
 *      Author: HERP
 */

#include<stdio.h>
#include<stdlib.h>

struct SData
{
	float Inch;
	int Feet;
};

int main()
{
	struct SData Information2;
	struct SData Information1;
	struct SData Result;
	printf("Enter the 1st distance\n");
	printf("Feet : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&Information1.Feet);
	printf("Inch:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&Information1.Inch);
	printf("\n");
	printf("Enter the 2nd distance\n");
	printf("Feet : ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&Information2.Feet);
	printf("Inch:");
	fflush(stdin);fflush(stdout);
	scanf("%f",&Information2.Inch);

	Result.Feet = Information1.Feet + Information2.Feet;
	Result.Inch = Information1.Inch + Information2.Inch;

	while(Result.Inch >= 12)
	{
		Result.Inch = Result.Inch - 12;
		++Result.Feet;
	}

	printf("\nSum of distances = %d' -%.1f\"",Result.Feet,Result.Inch);


	return 0;
}


