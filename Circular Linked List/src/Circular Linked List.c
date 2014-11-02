/*
 ============================================================================
 Name        : Circular.c
 Author      : Anirudh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node* link;
};
typedef struct node* listptr;

void insert(listptr* last)
{

	listptr temp;
	temp=(listptr)malloc(sizeof(struct node));
	printf("Enter the data to be inserted");
	scanf("%d",&temp->data);
	if(*last==NULL)
	{
		*last=temp;
		(*last)->link=*last;
	}
	else
	{
		temp->link=(*last)->link;
		(*last)->link=temp;
	}
}
void display(listptr last)
{
	listptr temp;
	temp=last->link;
	printf("%d\t",temp->data);
	temp=temp->link;
	for(;temp!=last->link;temp=temp->link)
	{
		printf("%d\t",temp->data);
	}
}
int main(void) {
	int choice;
	int item;
	listptr last;
	listptr first;
	first=NULL;

	last=NULL;
	while(1)
	{
		printf("Enter\n 1. Insert\n 2.Display");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			insert(&last);
			break;
		case 2:
			display(last);
		}
	}
}
