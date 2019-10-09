#include<stdio.h>
#include<stdlib.h>  //Dynamic memory allocation function are included in this header file
int main()
{
    int n,i,*ptr;
    printf("Enter the no of elements: ");
    scanf("%d",&n);
    ptr = (int *)malloc(n * sizeof(int));
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d",&ptr[i]);
    }
    for(int j = 0 ; j < n ; j++)
        printf("%d\t",ptr[j]);
    free(ptr);  //Now ptr becomes a dangling pointer(pointer pointing to de-allocated memory address)
    printf("\nMemory De-allocated properly\n");
    ptr = NULL; //Setting the value of ptr to NULL from dangling pointer
}