//Implememtation of fork() system call to generate a child process for a parent process
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    printf("Before fork() call this is parent\n");
    // fork();
    
    // //After this the instructions will be executed twice 
    // //One by Child and other by Parent process
    
    // printf("child process is created\n");   

    int pid;
    pid = fork();
    if(pid == 0)
    {
        printf("Inside Child Process\n");
    }
    else
    {
        printf("Inside Parent Process\n");
    }
    
    return 0;
}