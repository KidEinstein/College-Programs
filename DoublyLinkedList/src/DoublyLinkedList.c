/*
 ============================================================================
 Name        : DoublyLinkedList.c
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
        struct node* rlink;
        struct node* llink;
};
typedef struct node* nodeptr;
void search(nodeptr item, nodeptr node, nodeptr* pos)
{
    *pos=NULL;
        while(node!=NULL&&node->data<item->data)
        {
                *pos=node;
                node=node->rlink;
        }

        return;
}
void insert(nodeptr item, nodeptr pos, nodeptr* head)
{

        if(!pos)
        {
                item->rlink=*head;
                (*head)->llink=item;
                *head=item;
                return;
        }
        item->rlink=pos->rlink;
        if(pos->rlink)
                pos->rlink->llink=item;
        pos->rlink=item;
        item->llink=pos;
}
void delete(nodeptr* head, int key)
{
        nodeptr node=*head;
        for(;node;node=node->rlink)
        {
                if(node->data==key)
                {
                        if(node->llink)
                                node->llink->rlink=node->rlink;
                        else
                                *head=node->rlink;
                        if(node->rlink)
                                node->rlink->llink=node->llink;
                        free(node);
                }
        }
}
void display(nodeptr node)
{
        for(;node;node=node->rlink)
        {
                printf("%d\t",node->data);
        }
        printf("\n");
}
int main()
{
        nodeptr head,item,pos;
        int choice,key;
        head=(nodeptr)malloc(sizeof(struct node));
        printf("Enter value of first node");
        scanf("%d",&(head->data));
        head->rlink=NULL;
        head->llink=NULL;
        while(1)
        {
                printf("Enter 1. Insert 2. Delete 3. Display");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:
                                item=(nodeptr)malloc(sizeof(struct node));
                                printf("Enter data to be inserted");

                                scanf("%d",&(item->data));
                                search(item, head, &pos);
                                insert(item, pos, &head);
                                break;
                        case 2:
                                printf("Enter item to be deleted");
                                scanf("%d",&key);
                                delete(&head, key);
                                break;
                        case 3:
                                display(head);
                                break;
                }
        }
}

