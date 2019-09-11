#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 10

struct stack
{
    int arr[MAX_SIZE];
    int top;
};

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

void postfix(char infix[])
{
    //char output[30];
    struct stack S1,S2;
    S1.top = -1;
    S2.top = -1;
   // S1.arr[++S1.top] = '#';
    int i = 0;
    while(infix[i] != '\0')
    {
        if(isdigit(infix[i]) || isalpha(infix[i]))
            S2.arr[++S2.top] = infix[i];
        else if(infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
            S1.arr[++S1.top] = infix[i];
        i++;
    }
    for(int j = S1.top ; j >= 0 ; j--)
    {
        S2.arr[++S2.top] = S1.arr[S1.top--];
    }
    printf("%s",S2.arr);
}

void prefix(char infix[])
{

}

void precedence(char ch)
{

}

int main()
{
    int choice;
    char cont;
    char infix[30];
    do {
        printf("Enter the Infix expression: ");
        scanf("%s",infix);
        printf("You want conversion in\n1.Prefix\n2.Postfix\n3.exit\nYour choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("The output prefix expression is: ");
                    prefix(infix);
                    printf("\n");
                    break;

            case 2: printf("The output postfix expression is: ");
                    postfix(infix);
                    printf("\n");
                    break;

            case 3: exit(0);

            default: printf("Invalid choice\n");
        }
        printf("Do you want to continue(y/n): ");
        scanf(" %c",&cont);
    }while(cont == 'y');
    return 0;
}
