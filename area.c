#include<stdio.h>
typedef union
{
    struct rectangle
    {
        int l,b;


    }rec;
    struct triangle
    {
        int b,h;

    }tri;
}geometry;

void area(geometry g, int choice)
{
    if(choice==1)
    {

        printf("Area of triangle: %f", 0.5*g.tri.b*g.tri.h);
    }
    else if(choice==2)
    {

        printf("Area of rectangle: %d", g.rec.l*g.rec.b);
    }

}
void main()
{
    int choice;
    geometry g;
    printf("Menu: \n\t1. Triangle\n\t2. Rectangle\n");
    printf("Enter the option: ");
    scanf("%d",&choice);
    if(choice==1)
    {
        printf("Enter base and height of triangle: ");
        scanf("%d%d",&g.tri.b,&g.tri.h);
    }
    else if(choice ==2)
    {
        printf("Enter length and breadth of rectangle: ");
        scanf("%d%d",&g.rec.l,&g.rec.b);
    }
    else
    {
        printf("Invalid choice");
        exit(0);
    }
    area(g, choice);
}
