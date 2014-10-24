#include<stdio.h>
struct matrix
{
    int row, column, value;
};
typedef struct matrix matrix;
struct polynomial
{
    int exp, coeff;
};
typedef struct polynomial polynomial;
void readm(matrix *m)
{
    int i;
    for(i=1; i<=m[0].value; i++)
    {
        printf("Enter row, column number and element %d\n",i);
        scanf("%d%d%d",&m[i].row, &m[i].column, &m[i].value);
    }
}
void readp(polynomial *p, int terms)
{
    int i=0;
    for(i=0; i<terms; i++)
    {
        printf("Enter term %d coeff & exp: ", i+1);
        scanf("%d%d",&p[i].coeff, &p[i].exp);
    }
}
void printm(matrix m[])
{
    int i;
    printf("Sparse matrix:\n");
    printf("Array\t Row\t Column\t Value\n");
    for(i=0; i<=m[0].value; i++)
        printf("A[%d]\t %d\t %d\t %d\n", i, m[i].row, m[i].column, m[i].value);
}
void printp(polynomial p[], int terms)
{
    int i;
    for(i=0; i<terms-1; i++)
    {
        printf(" %d x ^ %d ",p[i].coeff, p[i].exp);
        if(p[i+1].coeff>0)
            printf("+");
    }
    printf(" %d x ^ %d",p[i].coeff, p[i].exp);
}
int main()
{
    int row, column, value, option, terms;
    printf("Menu: \n1. Sparse Matrix\n2. Spare Polynomial Eqn\n");
    printf("Enter option: ");
    scanf("%d",&option);
    switch(option)
    {
    case 1:

{
        printf("Enter total number of rows: ");
        scanf("%d",&row);
        printf("Enter total number of columns: ");
        scanf("%d",&column);
        printf("Enter total number of non zero elements: ");
        scanf("%d",&value);
        matrix m[value+1];
        m[0].row=row;
        m[0].column=column;
        m[0].value=value;
        readm(m);
        printm(m);
        break;
}

    case 2:
        {
        printf("Enter number of terms: ");
        scanf("%d",&terms);
        polynomial p[terms];
        readp(p, terms);
        printp(p, terms);
        break;
        }

    }


}
