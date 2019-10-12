#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10

struct stack
{
    int data[size];
    int top;
};
typedef struct stack ST;

//checkimg stack full condition
int isFullStack(struct stack *st)
{
    if(st->top == size - 1)
        return 1;
    else
        return 0;
}


//checking stack empty condition
int isEmptyStack(struct stack *st)
{
    if(st->top == -1)
        return 1;
    else
        return 0;
}


//pushing a element on top of stack
void push(struct stack *st , int ele)
{
    if(isFullStack(st))
    {
        printf("!Stack Overflow\n");
        exit(1);
    }
    st->data[++st->top] = ele;
}


//poping out or removing element from top of stack
int pop(struct stack *st)
{
    if(isEmptyStack(st))
    {
        printf("!Stack Underflow\n");
        exit(1);
    }
    int ele = st->data[st->top--];
    return ele;
}

int evaluation(int var1 , char ch , int var2)
{
    switch(ch)
    {
        case '+': return (var1 + var2);
        case '-': return (var1 - var2);
        case '*': return (var1 * var2);
        case '/': return (var1 / var2);
    }
}

int main()
{
    char postfix[30];
    printf("Enter a valid postfix statement: ");
    scanf("%s",postfix);
    int var1 , var2 , res , argument;
    ST st;
    st.top = -1;
    for(int i = 0 ; i < strlen(postfix) ; i++)
    {
        if(isalpha(postfix[i]))
        {
            printf("Enter value of %c : ",postfix[i]);
            scanf("%d",&argument);
            push(&st, argument);
        }
        else
        {
            var2 = pop(&st);
            var1 = pop(&st);
            res = evaluation(var1,postfix[i],var2);
            push(&st, res);
        }
    }
    printf("Ans is %d\n",st.data[st.top]);
}
