#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

struct STACK
{
    int arr[MAX_SIZE];
    int sp;
}S1;

void push(struct STACK *S1,int ele)
{
    if(S1->sp == MAX_SIZE - 1)
    {
        printf("OVERFLOW STACK can't push element\n");
        exit(1);
    }
    S1->sp++;
    S1->arr[(S1->sp)] = ele;
}

int pop(struct STACK *S1)
{
    if((S1->sp) == -1)
    {
        printf("UNDERFLOW can't pop values from empty stack\n");
        exit(2);
    }
    int m = S1->arr[S1->sp];
    S1->sp--;
    return m;
}

void display(struct STACK *S1)
{
   if((S1->sp) == -1)
    {
        printf("UNDERFLOW can't pop values from empty stack\n");
        exit(3);
    }
    for(int i = 0; i < MAX_SIZE; i++)
    {
        printf("%d\n",S1->arr[i]);
    }
}

int main()
{
    S1.sp = -1;
    int ele;
    char ch;
    do{
    printf("Enter your choice\n1.PUSH\n2.POP\n3.DISPLAY\n");
    int choice;
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("Enter no to push\n");
                scanf("%d",&ele);
                push(&S1,ele);
                break;
        case 2:printf("popped element is %d\n",pop(&S1));
                break;
        case 3:printf("The stack elements are\n");
                display(&S1);
                break;
        default:printf("INVALID CHOICE\n");
    }
    printf("Do you want to continue\n");
    scanf(" %c",&ch);
    }while(ch == 'Y');
return 0;
}
