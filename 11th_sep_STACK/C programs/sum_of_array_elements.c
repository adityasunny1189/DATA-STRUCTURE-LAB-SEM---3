#include<stdio.h>
int sum_of_array_elements(int array[],int len)
{
    int result = 0;
    for(int j=0; j<len; j++)
    {
        result = result +array[j];
    }
    return result;
}
int main()
{
    int array[1000],sum;
    printf("enter the length of the array: ");
    int len;
    scanf("%d",&len);
    printf("enter the array elements\n");
    for(int i=0; i<len; i++)
    {
        scanf("%d",&array[i]);
    }
    printf("entered array elements are \n");
    for(int i=0; i<len; i++)
    {
        printf("%d\n",array[i]);
    }
    sum = sum_of_array_elements(array, len);
    printf("sum of array elements are %d",sum);
}
