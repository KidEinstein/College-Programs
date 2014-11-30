/*
 ============================================================================
 Name        : Multiple.c
 Author      : Anirudh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int key;
}element;
struct node
{
	element data;
	struct node* link;
};

typedef struct node* stackptr;

stackptr stack[10]={NULL};

void insert(element item, int index)
{
	stackptr temp;
	temp=(stackptr)malloc(sizeof(struct node));
	temp->data=item;
	temp->link=stack[index];
	stack[index]=temp;

}
element deletes(int index)
{
	element item;
	if(stack[index])
	{
		item=stack[index]->data;
		stack[index]=stack[index]->link;
	}
	else
	{
		printf("Stack empty");
		item.key=-1;
	}
	return item;


}
void display(int index)
{
	stackptr temp=stack[index];
	if(!temp)
	{
		printf("Stack empty");
		return;
	}
	for(;temp;temp=temp->link)
		printf("%d\t",temp->data.key);

}
int main()
{
	int index, choice;
	element item;
	while(1)
	{
		printf("Enter 1. Insert 2. Delete 3. Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("Enter stack index: ");
			scanf("%d",&index);
			printf("Enter element to be inserted");
			scanf("%d",&item.key);
			insert(item, index);
			break;
		case 2:
			printf("Enter stack index: ");
			scanf("%d",&index);
			item=deletes(index);
			if(item.key!=-1)
				printf("Element deleted %d", item.key);
			break;
		case 3:
			printf("Enter stack index: ");
			scanf("%d",&index);
			display(index);


		}
	}

}
