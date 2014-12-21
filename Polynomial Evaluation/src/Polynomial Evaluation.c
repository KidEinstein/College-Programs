/*
 ============================================================================
 Name        : Polynomial.c
 Author      : Anirudh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct
{
	int coeff;
	int expo;
}poly;

void readPoly(poly* p, int* terms)
{
	int i;
	printf("Enter number of terms");
	scanf("%d",terms);
	for(i=0;i<*terms;i++)
	{
		printf("Enter coeff and expo");
		scanf("%d%d",&p[i].coeff,&p[i].expo);
	}

}
void displayPoly(poly* p, int terms)
{
	int i;
	for(i=0;i<terms-1;i++)
		printf("%d x ^ %d +", p[i].coeff, p[i].expo);
	printf("%d x ^ %d", p[i].coeff, p[i].expo);
	printf("\n");

}
int evalPoly(poly*p, int terms)
{
	int r=0,i,val;
	printf("Enter value of x");
	scanf("%d",&val);

	for(i=0; i<terms; i++)
		r+=p[i].coeff*pow(val,p[i].expo);
	return r;
}
int main()
{
	int terms;
	poly a[10];
	readPoly(a, &terms);
	displayPoly(a, terms);
	printf("%d",evalPoly(a, terms));

}

