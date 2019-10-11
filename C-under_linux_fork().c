//Implememtation of fork() system call to generate a child process for a parent process
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int main()
{
    // printf("Before fork() call this is parent\n");
    // // fork();
    
    // // //After this the instructions will be executed twice 
    // // //One by Child and other by Parent process
    
    // // printf("child process is created\n");   

    // int pid;
    // pid = fork();
    // if(pid == 0)
    // {
    //     printf("Inside Child Process\n");
    // }
    // else
    // {
    //     printf("Inside Parent Process\n");
    // }

    int pid ;
    pid = fork();

    if(pid == 0)
    {
        printf("Child: In child process\n");
        printf("Child: child process ID : %d\n",getppid());
        printf("Child: Parent process ID : %d\n",getpid());
    }
    else
    {
        printf("Parent: In Parent Process\n");
        printf("Parent: Parent process ID: %d\n",getpid());
        printf("Parent: Child process ID: %d\n",getppid());
    }
    
    
    return 0;
}