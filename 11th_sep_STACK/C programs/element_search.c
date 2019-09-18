#include<stdio.h>
void search_element(int array[], int max, int no)
{
    int j;
    for (j=0; j<max; j++)
    {
        if(no == array[j])
        {
            printf("found\n");
            exit(0);
        }
    }
    printf("not found\n");
}

int main() {
    int array[1000];
    printf("enter the length of the array\n");
    int max;
    scanf("%d",&max);
    int i;
    printf("enter array elements\n");
    for (i=0; i<max; i++)
    {
       scanf("%d",&array[i]);
    }
    printf("enter the no to search\n");
    int no;
    scanf("%d",&no);
    search_element(array, max, no);
}
