#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

struct stack
{
    char arr[30];
    int top;
};

int prec(char ch)
{
    switch(ch)
    {
        case '#':
        case '(':return 0;break;
        case '+':
        case '-':return 1;break;
        case '*':
        case '/':return 2;break;
        case '^':return 3;break;
    }
}

int main()
{
    int i = 0,j = 0,choice;
    char ch;
    struct stack S1;
    S1.top = -1;
    char infix[30],postfix[30];
    S1.arr[++S1.top] = '#';
    printf("Enter valid infix expression: ");
    scanf("%s",infix);
    printf("Conversion in\n1.Postfix\n2.Prefix\nChoice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:while(infix[i] != '\0')
                {
                    ch = infix[i];
                    if(isdigit(ch) || isalpha(ch))
                    {
                        postfix[j] = ch;
                        j++;
                    }
                    else if(ch == '(')
                    {
                        S1.arr[++S1.top] = ch;
                    }
                    else if(ch == ')')
                    {
                        while((ch = S1.arr[S1.top]) != '(')
                        {
                            postfix[j++] = S1.arr[S1.top];
                            S1.top--;
                        }
                        S1.top--;
                    }
                    else
                    {
                        if(prec(ch) < prec(S1.arr[S1.top]))
                        {
                            postfix[j++] = S1.arr[S1.top--];
                        }
                        else if(prec(ch) == prec(S1.arr[S1.top]))
                        {
                            postfix[j++] = S1.arr[S1.top--];
                            S1.arr[++S1.top] = ch;
                        }
                        else
                            S1.arr[++S1.top] = ch;
                    }
                    i++;
            }
                while((ch=S1.arr[S1.top]) != '#')
                {
                    postfix[j++] = S1.arr[S1.top];
                    S1.top--;
                }
                postfix[j] = '\0';
                printf("%s",postfix);
                break;

        case 2: strrev(infix);
                while(infix[i] != '\0')
                {
                    ch = infix[i];
                    if(isdigit(ch) || isalpha(ch))
                    {
                        postfix[j] = ch;
                        j++;
                    }
                    else if(ch == ')')
                    {
                        S1.arr[++S1.top] = ch;
                    }
                    else if(ch == '(')
                    {
                        while((ch = S1.arr[S1.top]) != ')')
                        {
                            postfix[j++] = S1.arr[S1.top];
                            S1.top--;
                        }
                        S1.top--;
                    }
                    else
                    {
                        if(prec(ch) < prec(S1.arr[S1.top]))
                        {
                            postfix[j++] = S1.arr[S1.top--];
                        }
                        else if(prec(ch) == prec(S1.arr[S1.top]))
                        {
                            postfix[j++] = S1.arr[S1.top--];
                            S1.arr[++S1.top] = ch;
                        }
                        else
                            S1.arr[++S1.top] = ch;
                    }
                    i++;
                }
                while((ch=S1.arr[S1.top]) != '#')
                {
                    postfix[j++] = S1.arr[S1.top];
                    S1.top--;
                }
                postfix[j] = '\0';
                strrev(postfix);
                printf("%s",postfix);
                break;

        default:printf("Invalid Command\n");
    }

}
