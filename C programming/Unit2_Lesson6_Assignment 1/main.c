/*
 * main.c
 *
 *  Created on: Jun 12, 2023
 *      Author: OmArHerp
 */

#include<stdio.h>
#include<stdlib.h>


struct SCredits {
	char name[50];
	int roll;
	int marks;
};
int main()
{
	struct SCredits student;

	printf("Enter your name,roll and marks respectively : ");
	fflush(stdin);fflush(stdout);
	gets(student.name);
	scanf("%d%d",&student.roll,&student.marks);

	printf("Displaying Information\n %s \n %d \n %d",student.name,student.roll,student.marks);
	return 0;
}


