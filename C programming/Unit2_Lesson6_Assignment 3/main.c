/*
 * main.c
 *
 *  Created on: Jun 12, 2023
 *      Author: OmArHerp
 */

#include<stdio.h>
#include<stdlib.h>

struct SComplex Complex(char name[]);
void Add(struct SComplex A, struct SComplex B);
struct SComplex
{
	double Real;
	double Imj;
};

int main()
{
	struct SComplex N1;
	struct SComplex N2;
	N1 = Complex("first");
	N2 = Complex("second");
	Add(N1,N2);


	return 0;
}

struct SComplex Complex(char name[])
{
	struct SComplex A;
	printf("Enter the %s complex number (real then imaginary) : ",name);
	fflush(stdin);fflush(stdout);
	scanf("%lf%lf",&A.Real,&A.Imj);
	return A;
}

void Add(struct SComplex A, struct SComplex B)
{
	struct SComplex Result;

	Result.Real = A.Real + B.Real;
	Result.Imj = A.Imj + B.Imj;

	printf("The Summation is %lf + %lfj",Result.Real,Result.Imj);

}
