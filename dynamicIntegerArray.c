#include<stdio.h>
#define MALLOC(x,n,type)(x=(type*)malloc(n*sizeof(type)))
int sum_arr(int* arr, int size)
{
    int sum=0, *ptr;
    ptr = arr;
    while(ptr<=&arr[size-1])
    {
        sum+=*(ptr++);

    }
    return sum;

}
void main()
{
    int size, *arr, i;
    printf("Enter total number of elements in array: ");
    scanf("%d",&size);
    MALLOC(arr, size, int);
    printf("Enter %d elements of array: ",size);
    for(i=0; i<size; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Sum of array elements: %d", sum_arr(arr, size));


}
