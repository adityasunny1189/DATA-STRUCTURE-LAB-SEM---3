#include<stdio.h>
#define MAX_SIZE 10

struct stack
{
    int arr[MAX_SIZE];
    int top;
}S1;

int isFull(struct stack *S1)
{
    if(S1->top == MAX_SIZE - 1)
        return 1;
    else
        return 0;
}

void push(struct stack *S1,int i)
{
    int no;
    if(isFull(&S1))
        printf("STACK OVERFLOW\n");
    else
    {
        S1->arr[++S1->top] = i;
    }
}

void isPalindrom(struct stack *S1)
{
    int p = 0;
    for(int i = 0; i < S1->top / 2; i++)
    {
        if(S1->arr[i] == S1->arr[S1->top - i])
            p++;
        else
            p--;
    }
    if(p == S1->top / 2)
        printf("PALINDROME\n");
    else
        printf("NOT PALINDROME\n");
}

void checkPalindrom(int no)
{
    S1.top = -1;
    int rem;
    while(no <= 0)
    {
        rem = no % 10;
        no = no / 10;
        push(&S1,rem); 
    } 
    isPalindrom(&S1);
}

int main()
{
    int no;
    printf("To check a no is palindrom or not\n");
    scanf("%d",&no);
    checkPalindrom(no);
    return 0;
}