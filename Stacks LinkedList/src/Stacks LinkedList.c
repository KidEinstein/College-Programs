/*
 ============================================================================
 Name        : Stacks.c
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
struct stack
{
	element data;
	struct stack* link;
};
typedef struct stack* stackptr;
stackptr top;
void push(element item)
{
	stackptr temp;
	temp=(stackptr)malloc(sizeof(struct stack));
	temp->data=item;
	temp->link=top;
	top=temp;
}
element pop()
{
	stackptr temp;
	temp=top;
	element item;
	if(!top)
	{
		item.key=-1;
		return item;
	}
	item=top->data;
	top=top->link;
	free(temp);
	return item;

}
void display()
{
	stackptr temp;
	temp=top;
	for(;temp;temp=temp->link)
		printf("%d\t",temp->data.key);
	printf("\n");
}
int main(void) {
	int choice;
	element item;
	top=NULL;
	while(1)
	{
		printf("Enter\n 1. Push\n 2. Pop\n 3.Display");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("Enter data to be inserted: ");
			scanf("%d",&item.key);
			push(item);
			break;
		case 2:
			item=pop();
			if(item.key==-1)
				printf("Stack empty");
			else
				printf("Element deleted: %d",item.key);
			break;
		case 3:
			display();
		}
	}
}
