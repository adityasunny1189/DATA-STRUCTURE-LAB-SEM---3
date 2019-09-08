#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

struct stack
{
    int arr[MAX_SIZE];
    int sp;
}S1;

void push(struct stack,int i);
int pop(struct stack);
void display(struct stack);

int main()
{
    S1.sp = -1;
    printf("STACK IMPLEMENTATION\n");
    printf("Enter your choice\n1.PUSH Element in stack\n2.POP Element\n3.DISPLAY stack\n");
    int choice,element;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("Enter element to push\n");
                scanf("%d",&element);
                push(S1,element);
                break;
        case 2:printf("poped element from stack is %d",pop(S1));
                break;
        case 3:printf("Stack elements are \n");
                display(S1);
                break;
        default:printf("INVALID CHOICE\n");
    }
    return 0;
}

