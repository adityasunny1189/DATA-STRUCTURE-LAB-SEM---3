#include<stdio.h>
#include<sys/types.h>
int main()
{
    printf("Parent Process ID : %d",getpid());
    printf("\nChild Process ID : %d",getppid());
    printf("\n");
    return 0;
}