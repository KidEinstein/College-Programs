/*
 ============================================================================
 Name        : Queues.c
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

struct queue
{
	element data;
	struct queue* link;
};
typedef struct queue* queueptr;
queueptr front,rear;
void insert(element item)
{
	queueptr temp;
	temp=(queueptr)malloc(sizeof(struct queue));
	temp->data=item;
	if(front)
	{
		rear->link=temp;
	}
	else
		front=temp;
	rear=temp;
	rear->link=NULL;
}

element delete()
{
	queueptr temp;
	temp=front;
	element item;
	if(front)
	{
		item=front->data;
		front=front->link;
	}
	else
	{
		item.key=-1;
	}
	free(temp);
	return item;
}

void display()
{
	queueptr temp;
	temp=front;
	for(;temp;temp=temp->link)
		printf("%d\t",temp->data.key);
	printf("\n");
}

int main(void) {
	int choice;
	element item;
	while(1)
	{
		printf("Enter\n 1. Insert\n 2. Delete\n 3.Display");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:
			printf("Enter data to be inserted: ");
			scanf("%d",&item.key);
			insert(item);
			break;
		case 2:
			item=delete();
			if(item.key==-1)
				printf("Queue empty");
			else
				printf("Element deleted: %d",item.key);
			break;
		case 3:
			display();
		}
	}
}
