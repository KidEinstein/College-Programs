#include<stdio.h>
#include<stdlib.h>
int top=-1, size;

typedef struct
{
    int n;
}stack;
stack *s;
stack pop()
{
    stack item;
    if(top==-1)
    {
        printf("Stack underflow");
        item.n=-1;
        return item;
    }
}
void push(stack item)
{
    if(top==size-1)
    {
        size*=2;
        s=(stack*)realloc(s, sizeof(stack)*size);
    }
    s[++top]=item;
}
void display()
{
    int i;
    for(i=0; i<=top; i++)
    {
        printf("%d\t",s[i].n);
    }
}

void main()
{
    int choice;
    stack item;
    printf("Enter stack size");
    scanf("%d",&size);
    s=(stack*)malloc(sizeof(stack)*size);
    while(1)
    {
        printf("Enter \n1. Push \n2. Pop \n 3. Display 4. Exit");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            printf("Enter item to be inserted");
            scanf("%d",&item.n);
            push(item);
            break;
        case 2:

            item=pop();
            if(item.n!=-1)
            {
                printf("Element popped: %d",item.n);
            }
            break;
        case 3:
            display();
        case 4:
            exit(0);

        }
    }
}
