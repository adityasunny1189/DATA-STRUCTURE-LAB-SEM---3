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

int prec(char ch)
{
    switch(ch)
    {
        case '#': return 0;

        case '*':
        case '/': return 5;

        case '+':
        case '-': return 4;

        case '(': return 3;
    }
}

int isFullStack(ST *st)
{
    if(st->top == size - 1)
        return 1;
    else
        return 0;
}

void push(ST *st , char ch)
{
    if(isFullStack(st))
    {
        printf("!Stack Overflow\n");
        exit(1);
    }
    st->data[++st->top] = ch;
}

int isEmptyStack(ST *st)
{
    if(st->top == -1)
        return 1;
    else
        return 0;
}

int pop(ST *st)
{
    if(isEmptyStack(st))
    {
        printf("!Stack Underflow\n");
        exit(1);
    }
    char ele = st->data[st->top--];
    return ele;
}

int main()
{
    ST st;
    st.top = -1;
    printf("Postfix Conversion\n");
    char infix[30];
    char postfix[30];
    int j = 0;
    push(&st , '#');
    printf("Enter the Infix Expression: ");
    scanf("%s",infix);
    for(int i = 0 ; i < strlen(infix) ; i++)
    {
        if(isalpha(infix[i]) || isdigit(infix[i]))
        {
            postfix[j++] = infix[i];
        }
        else if(infix[i] == '(')
        {
            push(&st, infix[i]);
        }
        else if(infix[i] == ')')
        {
            while(st.data[st.top] != '(')
            {
                postfix[j++] = pop(&st);
            }
            st.top--;
        }
        else
        {
            if(prec(infix[i]) >= prec(st.data[st.top]))
            {
                push(&st, infix[i]);
            }
            else
            {
                postfix[j++] = pop(&st);
                push(&st, infix[i]);
            }
        }
    }
    while(st.data[st.top] != '#')
    {
        postfix[j++] = pop(&st);
    }
    printf("Infix : %s has Postfix : %s\n",infix,postfix);
}
