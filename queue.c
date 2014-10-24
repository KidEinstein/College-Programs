#include<stdio.h>
#define max 5
typedef struct
{
    int n;
}element;
int rear=0, front=0;
element queue[max];
void addq(element item)
{
    if(rear==max-1)
    {
        printf("Queue Full");
    }
    else
    {
        queue[++rear]=item;
    }
}
element deleteq()
{
    element item;
    if(front==rear)
    {
        item.n=-1;
        return item;
    }
    return queue[++front];

}
void displayq()
{
    int i;
    for(i=front+1; i<=rear; i++)
        printf("%d\t",queue[i].n);
}

void main()
{
    int choice;
    element item;
    while(1)
    {
        printf("Enter \n1. Add\n2. Delete\n 3. Display");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter item to add");
            scanf("%d",&item.n);
            addq(item);
            break;
        case 2:
            item=deleteq();
            if(item.n==-1)
            {
                printf("Queue Empty");
            }
            else
                printf("Item deleted: %d", item.n);
            break;
        case 3:
            displayq();
        }
    }
}
