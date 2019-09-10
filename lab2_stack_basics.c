#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10

struct stack
{
    int top;
    int arr[MAX_SIZE];
}S1;

int isFull(struct stack *S1)
{
    if(S1->top == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

int isEmpty(struct stack *S1)
{
    if(S1->top == -1)
        return 1;
    else
        return 0;
}

void push(struct stack *S1, int ele)
{
    if(isFull(S1))
        printf("STACK OVERFLOW\n");
    else
        S1->arr[++S1->top] = ele;
}

int pop(struct stack *S1)
{
    if(isEmpty(S1))
        printf("STACK UNDERFLOW\n");
    else
        return (S1->arr[S1->top--]);
}

void display(struct stack *S1)
{
    for(int i = 0 ; i <= S1->top ; i++)
        printf("%d\t",S1->arr[i]);
    printf("\n");
}

int main()
{
    S1.top = -1;
    char adi = 'y';
    printf("STACK IMPLEMENTATION\n");
    while(adi == 'y')
    {
        printf("Enter your choice\n1.PUSH Element in stack\n2.POP Element\n3.DISPLAY stack\n");
        int choice,element;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:printf("Enter element to push\n");
                    scanf("%d",&element);
                    push(&S1,element);
                    break;
            case 2:printf("poped element from stack is %d",pop(&S1));
                   break;
            case 3:printf("Stack elements are \n");
                    display(&S1);
                    break;
            default:printf("INVALID CHOICE\n");
        }
        printf("\nDo you want to continue: ");
        scanf(" %c",&adi);
    }
    return 0;
}       


        
        
        
                                                 // #include<stdio.h>
                                                // #include<stdlib.h>

                                                // #define MAX_SIZE 10

                                                // struct stack
                                                // {
                                                //     int arr[MAX_SIZE];
                                                //     int sp;
                                                // }S1;

                                                // int isFullStack(struct stack *S1)
                                                // {
                                                //     if(S1->sp == MAX_SIZE - 1)
                                                //         return 1;
                                                //     else
                                                //         return 0;
                                                // }

                                                // int isEmptyStack(struct stack *S1)
                                                // {
                                                //     if(S1->sp == -1)
                                                //         return 1;
                                                //     else
                                                //         return 0;
                                                // }

                                                // void push(struct stack *S1,int i)
                                                // {
                                                //     if(isFullStack(S1))
                                                //         printf("OVERFLOW\n");
                                                //     else
                                                //         S1->arr[++S1->sp] == i;
                                                // }

                                                // int pop(struct stack *S1)
                                                // {
                                                //     if(isEmptyStack(S1))
                                                //         printf("UNDERFLOW\n");
                                                //     else
                                                //         return (S1->arr[S1->sp--]);
                                                // }

                                                // void display(struct stack *S1)
                                                // {
                                                //     for(int i = 0; i <= S1->sp ; i++)
                                                //         printf("%d\t",S1->arr[i]);
                                                // }

                                                // int main()
                                                // {
                                                //     S1.sp = -1;
                                                //     char adi = 'y';
                                                //     printf("STACK IMPLEMENTATION\n");
                                                //     while(adi == 'y')
                                                //     {
                                                //         printf("Enter your choice\n1.PUSH Element in stack\n2.POP Element\n3.DISPLAY stack\n");
                                                //         int choice,element;
                                                //         scanf("%d",&choice);
                                                //         switch(choice)
                                                //         {
                                                //             case 1:printf("Enter element to push\n");
                                                //                     scanf("%d",&element);
                                                //                     push(&S1,element);
                                                //                     break;
                                                //             case 2:printf("poped element from stack is %d",pop(&S1));
                                                //                    break;
                                                //             case 3:printf("Stack elements are \n");
                                                //                     display(&S1);
                                                //                     break;
                                                //             default:printf("INVALID CHOICE\n");
                                                //         }
                                                //         printf("\nDo you want to continue: ");
                                                //         scanf(" %c",&adi);
                                                //     }
                                                //     return 0;
                                                // }




