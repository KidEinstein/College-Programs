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
#define COMPARE(x,y)(x>y?1:(x<y?-1:0))
struct node
{
	int coeff;
	int expo;
	struct node* link;
};
typedef struct node* polyptr;
polyptr a,b;

void attach(int coefficient, int exponent, polyptr *ptr)
{
	polyptr temp;
	temp=(polyptr)malloc(sizeof(struct node));
	temp->coeff=coefficient;
	temp->expo=exponent;
	(*ptr)->link=temp;
	*ptr=temp;
	(*ptr)->link=NULL;

}
polyptr add(polyptr a, polyptr b)
{
	polyptr c,rear,temp;
	int sum;
	rear=(polyptr)malloc(sizeof(struct node));
	c=rear;
	while(a&&b)
	{
		//printf("a: %d, b: %d",a->expo,b->expo);
		switch(COMPARE(a->expo,b->expo))
		{

		case -1:
			attach(b->coeff,b->expo,&rear);
			b=b->link;
			break;
		case 0:
			//printf("Equal\n");
			sum=a->coeff+b->coeff;
			if(sum)
				attach(sum,a->expo,&rear);

			a=a->link;
			b=b->link;
			break;
		case 1:
			attach(a->coeff,a->expo,&rear);
			a=a->link;
			break;
		}
	}
		for(;a;a=a->link)
			attach(a->coeff,a->expo,&rear);
		for(;b;b=b->link)
			attach(b->coeff,b->expo,&rear);



	rear->link=NULL;
	temp=c;
	c=c->link;
	free(temp);
	return c;
}
void printPoly(polyptr a)
{
	while(a->link)
	{
		printf("%d x ^ %d + ",a->coeff,a->expo);
		a=a->link;
	}
	printf("%d x ^ %d",a->coeff,a->expo);
	printf("\n");
}
void readPoly(polyptr *a)
{
	*a=(polyptr)malloc(sizeof(struct node));
	polyptr temp;
	temp=*a;
	int expo;
	int coeff;
	int i=0;
	do{
		printf("Enter coeff and exponent %d",++i);
		scanf("%d%d",&coeff,&expo);
		attach(coeff, expo, &temp);
	}while(expo!=0);
	*a=(*a)->link;
}
void readPoly2(polyptr *a)
{
	*a=(polyptr)malloc(sizeof(struct node));
	polyptr temp;
	temp=*a;
	int expo;
	int n;
	int coeff;
	int i=0;
	printf("Enter number of terms: ");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("Enter coeff and exponent %d",i);
		scanf("%d%d",&coeff,&expo);
		attach(coeff, expo, &temp);
	}
	*a=(*a)->link;
}
int main(void) {
	polyptr a,b,c;
	readPoly2(&a);
	printPoly(a);
	readPoly2(&b);
	printPoly(b);
	c=add(a,b);
	printPoly(c);

}
