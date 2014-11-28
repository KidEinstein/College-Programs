/*
 ============================================================================
 Name        : Binary.c
 Author      : Anirudh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include<stdio.h>
#include<stdlib.h>
struct node
{
        int data;
        struct node* llink;
        struct node* rlink;
};
typedef struct node* treeptr;
typedef enum{false,true} boolean;
void inOrder(treeptr ptr)
{
        if(ptr)
        {
                inOrder(ptr->llink);
                printf("%d\t",ptr->data);
                inOrder(ptr->rlink);
        }
}

boolean add(treeptr* ele)
{
        treeptr temp;

        if(*ele==NULL)
        {
        		temp=(treeptr)malloc(sizeof(struct node));
        		printf("Enter value: ");
                scanf("%d",&temp->data);
                temp->llink=temp->rlink=NULL;
                *ele=temp;
                return true;
        }
        else
                return false;
}
treeptr queue[10];
int front,rear;
void addq(treeptr ptr)
{
	queue[rear++]=ptr;
}
treeptr deleteq()
{
	if(front!=rear)
		return queue[front++];
	return NULL;
}
treeptr stack[10];
int top;
void push(treeptr node)
{
	stack[++top]=node;

}
treeptr pop()
{
	if(top==-1)
		return NULL;
	return stack[top--];
}
void iterInorder(treeptr node)
{
	top=-1;
	for(;;)
	{
		for(;node;node=node->llink)
			push(node);

		node=pop();
		if(!node)
			break;
		printf("%d\t",node->data);
		node=node->rlink;
	}

}
void levelOrder(treeptr ptr)
{
	front=rear=0;

	if(!ptr)
		return;
	addq(ptr);
	for(;;)
	{
		ptr=deleteq();
		if(ptr)
		{
			printf("%d\t",ptr->data);
			if(ptr->llink)
				addq(ptr->llink);
			if(ptr->rlink)
				addq(ptr->rlink);

		}
		else
			break;
	}

}
int main()
{
        treeptr root;
        root = (treeptr)malloc(sizeof(struct node));
        printf("Enter the value of root node");
        scanf("%d",&root->data);
        root->llink=root->rlink=NULL;
        int choice;
        char side;
        boolean added;

        treeptr temp;
        temp=root;
        while(1)
        {

                printf("1. Add node\n 2. Display InOrder\n 3. Display LevelOrder 4. Display Iterative Inorder");
                scanf("%d",&choice);
                switch(choice)
                {
                case 1:
                        temp=root;
                        for(;;)
                        {
                                printf("Enter whether to add to the left or right of %d",temp->data);
                                scanf("%*c%c",&side);
                                if(side=='l')
                                {
                                        added=add(&(temp->llink));
                                        if(added==false)
                                        {
                                                temp=temp->llink;
                                                continue;
                                        }
                                        else
                                                break;
                                }


                                else if(side=='r')
                                {
                                        added=add(&(temp->rlink));
                                        if(added==false)
                                        {
                                                temp=temp->rlink;
                                                continue;
                                        }
                                        else
                                                break;
                                }

                        }
                        break;

                case 2:
                        inOrder(root);
                        printf("\n");
                        break;
                case 3:
                		levelOrder(root);
                		printf("\n");
                		break;
                case 4:
                		iterInorder(root);
                		break;
                }
        }
}
