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

int main()
{
        treeptr root;
        root = (treeptr)malloc(sizeof(struct node));
        printf("Enter the value of root node");
        scanf("%d",&root->data);
        root->llink=root->rlink=NULL;
        int choice;
        int data;
        char side;
        boolean added;

        treeptr temp;
        temp=root;
        while(1)
        {

                printf("1. Add node\n 2. Display Inorder\n");
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
                        printf("Tree is\n");
                        inOrder(root);
                        break;
                }
        }
}
