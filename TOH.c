#include<stdio.h>
#include<stdlib.h>

int TOH(int n, int A, int B, int C)
{
    if(n>0)
    {
        TOH(n-1,A,C,B);
        printf("Transfer %d block from %d pole to %d pole\n",n,A,C);
        TOH(n-1,B,A,C);
    }
}

int main()
{
    int n;
    printf("Enter no of blocks: ");
    scanf("%d",&n);
    TOH(n,1,2,3);
    return 0;
}
