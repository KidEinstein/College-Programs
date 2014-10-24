#include<stdio.h>
int isInvalid(int* x, int* y)
{
    if((*x==0||*x==1)&&(*y==0||*y==1))
        return 0;
    else return 1;
}
int log_and(int* m,int* n)
{
    return *m**n;
}
int log_or(int* m,int* n)
{
    return (*m+*n)>0?1:0;
}
int log_xor(int* m,int* n)
{
    return (*m+*n)==1?1:0;
}
int log_not(int* m)
{
    return *m==0?1:0;
}
void main()
{
    int a,b,*m,*n;
    m=&a;
    n=&b;
    printf("Enter boolean values to be stored: \n");
    scanf("%d%d",m,n);
    if(isInvalid(m,n))
    {
        printf("Inputs are invalid");
        exit(0);
    }
    printf("Result of AND operation: %d\n",log_and(m,n));
    printf("Result of OR operation: %d\n",log_or(m,n));
    printf("Result of XOR operation: %d\n",log_xor(m,n));
    printf("Result of NOT operation on the first operand: %d\n",log_not(m));
    printf("Result of NOT operation on the second operand: %d\n",log_not(n));
}








