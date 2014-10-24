#include<stdio.h>
#define max 100
#define COMPARE(x,y)((x==y?0:(x>y)?1:-1))
typedef struct
{
    int expo;
    float coeff;
}poly;
int avail=0;
void attach(float coeff, int expo, poly p[])
{
    p[avail].coeff=coeff;
    p[avail].expo=expo;
    avail++;
}
void addPoly(poly p[], int sa, int ea, int sb, int eb, int*sc, int *ec)
{
    *sc=avail;
    float coeff;
    while(sa<=ea&&sb<=eb)
    {
        switch(COMPARE(p[sa].expo,p[sb].expo))
               {
               case -1:
                    attach(p[sb].coeff, p[sb].expo, p);
                    sb++;
                    break;
               case 1:
                    attach(p[sa].coeff, p[sa].expo, p);
                    sa++;
                    break;
               case 0:
                    coeff=p[sa].coeff+p[sb].coeff;
                    if(coeff!=0)
                    {
                        attach(coeff, p[sa].expo, p);
                    }
                    sa++;
                    sb++;
                    break;
               }


    }
    while(sa<=ea)
    {
        attach(p[sa].coeff, p[sa].expo, p);
        sa++;

    }
    while(sb<=eb)
    {
        attach(p[sb].coeff, p[sb].expo, p);
        sb++;

    }
    *ec=avail-1;
    }
poly readPoly(poly p[], int* start, int* end)
{
    *start=avail;
    do
    {
        printf("Enter coeff and exponent");
        scanf("%f%d",&p[avail].coeff,&p[avail].expo);
        avail++;
    }while(p[avail-1].expo!=0);
    *end=avail-1;
}
void print(poly p[], int start, int end)
{
    int i=start;
    while(i<end)
    {
        printf("%.2f x ^ %d", p[i].coeff, p[i].expo);
        i++;
        if(p[i].coeff>0)
            printf("+ ");
    }
    printf("%.2f x ^ %d ", p[i].coeff, p[i].expo);
}
void main()
{
    poly p[max];
    int startA,startB,startC;
    int endA,endB,endC;
    printf("Enter the first polynomial\n");
    readPoly(p,&startA, &endA);
    print(p,startA, endA);
    printf("Enter the second polynomial\n");
    readPoly(p,&startB, &endB);
    print(p,startB, endB);
    addPoly(p, startA, endA, startB, endB, &startC, &endC);
    print(p,startC, endC);
}



