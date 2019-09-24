#include<stdio.h>
#include<stdlib.h>

struct stack
{
    int arr[10];
    int top;
}S1;

int isFull() {
    if(S1.top == 9)
        return 1;
    else
        return 0;
}

int isEmpty() {
    if(S1.top == -1)
        return 1;
    else
        return 0;
}

void push(int no) {
    if(isFull())
    {
        printf("Stack Overflow\n");
        exit(1);
    }
    S1.arr[++S1.top] = no;
}

int pop() {
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(2);
    }
    return S1.arr[S1.top--];
}

void display() {
    for(int i = 0 ; i <= S1.top ; i++)
    {
        printf("%d\t",S1.arr[i]);
    }
}

int main() {
    S1.top = -1;
    char ch;
    printf("Stack Implementation\n");
    do{
        printf("Enter your choice\n1.push\n2.pop\n3.display\n4.exit\nchoice: ");
        int choice;
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter no to push: ");
                    int no;
                    scanf("%d",&no);
                    push(no);
                    break;
            
            case 2: printf("poped up no is %d\n",pop());
                    break;

            case 3: printf("the stack content is: ");
                    display();
                    break;

            case 4: exit(3);

            default: printf("Invalid choice\n");
        }
        printf("Do you want to continue(y/n): ");
        scanf(" %c",&ch);
    }while(ch == 'y');
    return 0;    
}