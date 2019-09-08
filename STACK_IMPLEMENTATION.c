#include<stdio.h>
#include<stdlib.h>

#define MAX_SIZE 10
int Arr[MAX_SIZE];
int top = -1;

void Push(int x) 
{
  if(top == MAX_SIZE -1) { // overflow case. 
		printf("Error: stack overflow\n");
		return;
	}
	Arr[++top] = x;
}

void Pop() 
{
	if(top == -1) { // If stack is empty, pop should throw error. 
		printf("Error: No element to pop\n");
		return;
	}
	top--;
}

void display()
{
    for(int i = 0 ; i <= top ; i++)
    {
        printf("%d\t",Arr[i]);
    }
    printf("\n");
}

int main()
{
    char ch = 'y';
    int choice;
    printf("Basic Stack Implementation\n");
    do
    {
        printf("Enter your choice\n1.PUSH\n2.POP\n3.DISPLAY\nYour Choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("Enter element to push\n");
                int ele;
                scanf("%d",&ele);
                Push(ele);
            break;
        case 2:Pop();
            break;
        case 3:printf("Array is\n");
                display();
            break;
        default:printf("Invalid Choice\n");
            break;
        }
        printf("Do you want to continue\n");
        scanf(" %c",&ch);
    } while (ch == 'y');
    
}