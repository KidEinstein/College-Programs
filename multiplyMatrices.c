#include<stdio.h>
#define MALLOC(x,n,type)(x=((type*)malloc(n*sizeof(type))))
int** createMatrix(int* row, int* col);
int** createMatrixInp(int* row, int* col)
{

    int **x;
    printf("Enter number of rows and columns\n");
    scanf("%d%d",row,col);
    x = createMatrix(row, col);
    return x;
}
int** createMatrix(int* row, int* col)
{
    int i,j,**x;
    x=(int**)malloc(sizeof(int)**row);
    for(i=0; i<*row; i++)
    {
        x[i]=(int*)malloc(sizeof(int)**col);
    }

    return x;
}
void readMatrix(int** x, int row, int col)
{
    int i,j;
    printf("Enter the elements in order\n");
    for(i=0; i<row; i++)
        for(j=0; j<col; j++)
        {
            scanf("%d",&x[i][j]);
        }




}
void multiMatrix(int** x, int** y, int** z, int row1, int col1, int row2, int col2)
{
    int i,j,k;
    if(!(col2==row1))
    {
        printf("Multiplication not possible\n");
        exit(0);
    }
    else
    {
        for(i=0; i<row1; i++)
        {

            for(j=0; j<col1; j++)
            {
                z[i][j]=0;
                for(k=0; k<row1; k++)
                {
                z[i][j]+=x[i][k]*y[k][j];
                }
            }
        }


    }
}
void printMatrix(int** x, int row, int col)
{
    int i,j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            printf("%d\t",x[i][j]);
        }
        printf("\n");
    }
}
void main()
{
    int row1, row2, col1, col2, **x, **y, **z;
    printf("Enter matrix A\n");
    x=createMatrixInp(&row1, &col1);
    readMatrix(x, row1, col1);
    printf("Enter matrix B\n");
    y=createMatrixInp(&row2, &col2);
    readMatrix(y, row2, col2);
    z=createMatrix(&row1, &col1);
    multiMatrix(x, y, z, row1, col1, row2, col2);
    printf("Matrix A*B is\n");
    printMatrix(z, row1, col1);
}
