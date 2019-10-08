#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n;
    printf("Enter the length of array\n");
    scanf("%d",&n);
    int *ptr = (int *)malloc(n * sizeof(int));
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&ptr[i]);
    }
    printf("Array is :-");
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d\t",ptr[i]);
    }
    return 0;
}