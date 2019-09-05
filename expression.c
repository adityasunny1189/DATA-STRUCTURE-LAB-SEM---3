#include<stdio.h>
int main()
{
    int i,j,m,n,temp,arr[1000];
    printf("Enter the no of elements in the array: ");
    scanf("%d",&m);
    printf("Enter the no of left shift: ");
    scanf("%d",&n);
    printf("Enter the array elements\n");
    for(i=0;i<m;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Printed array is\n");
    for(i=0;i<m;i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("Applying left shift algorithm\n");
    for(j=0;j<n;j++)
    {
        temp = arr[0];
        for(i=1;i<m;i++)
        {
            arr[i-1] = arr[i];
        }
        arr[m-1] = temp;
    }
    printf("Shifted array is\n");
    for(i=0;i<m;i++)
    {
        printf("%d\t",arr[i]);
    }
}