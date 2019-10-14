#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 10

struct stack
{
    float data[size];
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
void push(struct stack *st , float ele)
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
    float ele = st->data[st->top--];
    return ele;
}

int evaluation(float var1 , char ch , float var2)
{
    switch(ch)
    {
        case '+': return (var1 + var2);
        case '-': return (var1 - var2);
        case '*': return (var1 * var2);
        case '/': return (var1 / var2);
        default : printf("Invalid Command\n");
                  exit(1);
    }
}

int validationPostfix(char string[])
{
    int operand = 0, operator = 0;
    for(int i = 0 ; i < strlen(string) ; i++)
    {
        if(isalpha(string[i]))
        {
            operand++;
        }
        else
        {
            operator++;
        }
    }
    if(operator + 1 == operand)
    {
        return 1;
    }
    return 0;
}

int main()
{
    char postfix[30];
    printf("Enter a valid postfix statement: ");
    scanf("%s",postfix);
    if(!validationPostfix(postfix))
    {
        printf("invalid Postfix Expression\n");
        exit(1);
    }
    float var1 , var2 , res , argument;
    ST st;
    st.top = -1;
    for(int i = 0 ; i < strlen(postfix) ; i++)
    {
        if(isalpha(postfix[i]))
        {
            printf("Enter value of %c : ",postfix[i]);
            scanf("%f",&argument);
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
    printf("Ans is %.2f\n",st.data[st.top]);
}
