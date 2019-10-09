#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n , i , *ptr;
    printf("Enter the length of array: ");
    scanf("%d",&n);
    ptr = (int *)calloc(n , sizeof(int));
    for(i = 0 ; i < n ; i++)
        scanf("%d",&ptr[i]);
    printf("Enter the new size of array: ");
    scanf("%d",&n);
    ptr = realloc(ptr, n * sizeof(int));
    printf("Memory reallocated\n");
    while(i < n)
    {
        scanf("%d",&ptr[i]);
        i++;
    }
    printf("Elements in the array are : ");
    for(int j = 0 ; j < n ; j++)
        printf("%d\t",ptr[j]);
    printf("\n");
    return 0;
}