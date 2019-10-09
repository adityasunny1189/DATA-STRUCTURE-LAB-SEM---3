#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,i,sum = 0;
    int *ptr;
    printf("Enter the total no of values: ");
    scanf("%d",&n);
    ptr = (int *)calloc(n,sizeof(int));
    printf("Enter the values: \n");
    for(i = 0 ; i < n ; i++)
    {
        scanf("%d",&ptr[i]);
        sum = sum + ptr[i];
    }
    printf("The given input is : ");
    for(i = 0 ; i < n ; i++)
        printf("%d\t",ptr[i]);
    printf("\nSum of array elements is : %d\n",sum);
    return 0;
}