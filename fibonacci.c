#include<stdio.h>
#include<stdlib.h>

int fib(int n)
{
    if(n == 0 || n == 1)
        return 1;
    else
        return fib(n-1) + fib(n-2);
}

int main(void)
{
    int n;
    printf("Enter the element no in fibonacci series: ");
    scanf("%d",&n);
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d\t",fib(i));
    }
    printf("\n");
    return 0;
}