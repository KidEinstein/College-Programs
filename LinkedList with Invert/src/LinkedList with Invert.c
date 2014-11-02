/*
 ============================================================================
 Name        : LinkedList.c
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
void insert(listptr *first, listptr x)
{
	listptr temp;
	temp=(listptr)malloc(sizeof(listptr));
	printf("Enter the data: ");
	scanf("%d",&temp->data);
	if(*first)
	{
		temp->link=x->link;
		x->link=temp;
	}
	else
	{
		temp->link=NULL;
		*first=temp;
	}
}
void delete(listptr *first, listptr trail, listptr x)
{
	if(trail)
		trail->link=x->link;
	else
		*first=(*first)->link;
	free(x);
}
void display(listptr first)
{
	for(;first;first=first->link)
		printf("%d\t",first->data);
	printf("\n");
}
void search(listptr first, listptr* x, listptr* trail, int val)
{
	*trail=NULL;
	while(first)
	{
		if(first->data==val)
		{
			*x=first;
			return;
		}
		*trail=first;
		first=first->link;

	}
	*x=NULL;
}
listptr invert(listptr lead)
{
	listptr middle,trail;
	middle=NULL;

	while(lead)
	{
		trail=middle;
		middle=lead;
		lead=lead->link;
		middle->link=trail;
	}

	return middle;
}

int main(void) {
	int val,choice;
	listptr x=NULL, first=NULL, trail=NULL;
	while(1)
	{
		printf("Enter\n 1. Insert\n 2. Delete\n 3. Display\n 4. Invert\n 5. Exit");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			if(first==NULL)
				insert(&first,x);
			else
			{
				printf("Enter the data of the node after which it has to be inserted: ");
				scanf("%d",&val);
				search(first, &x, &trail, val);
				if(x==NULL)
				{
					printf("Node does not exist");
				}
				else
					insert(&first, x);
			}
			break;
		case 2:
			printf("Enter the data of the node to be deleted: ");
			scanf("%d",&val);
			search(first, &x, &trail, val);
			if(x==NULL)
				printf("Node does not exist");
			else
				delete(&first, trail, x);
			break;
		case 3:
			display(first);
			break;
		case 4:
			first=invert(first);
		}
	}
}
