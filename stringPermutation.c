#include<stdio.h>
#include<string.h>
void swap(char* a, char* b)
{
    char temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
void permute(char a[], int beg, int n)
{
    int j;
    if(beg==n)
        printf("%s\n",a);
    for(j=beg;j<n;j++)
    {
        swap(a+beg, a+j);
        permute(a, beg+1, n);
        swap(a+beg, a+j);

    }
}
void main()
{
    char a[10];

    printf("Enter a string");
    gets(a);
    printf("All permutations of %s are\n", a);
    permute(a, 0, strlen(a));


}
