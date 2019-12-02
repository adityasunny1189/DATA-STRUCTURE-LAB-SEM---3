#include<stdio.h>
#include<stdlib.h>

#define size 5

struct stack {
  int data[size];
  int top;
};

int isFull(struct stack *S) {
  if(S->top == size - 1)
    return 1;
  return 0;
}

int isEmpty(struct stack *S) {
  if(S->top == -1)
    return 1;
  return 0;
}

void push(struct stack *S, int ele) {
  if(isFull(S)) {
    printf("Can't push element in full stack\n");
    return;
  }
  S->data[++S->top] = ele;
}

int pop(struct stack *S) {
  if(isEmpty(S)) {
    printf("Can't delete from empty stack\n");
    return;
  }
  return S->data[S->top--];
}

void display(struct stack S) {
  for(int i = 0; i <= S.top; i++) {
    printf("%d ",S.data[i]);
  }
  printf("\n");
}

int main() {
  char ch;
  struct stack S;
  int choice,ele;
  S.top = -1;
  do {
    printf("1.Push\n2.Pop\n3.Display\nChoice: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: printf("Enter No to push: ");
              scanf("%d",&ele);
              push(&S,ele);
              break;

      case 2: printf("Poped element is: %d\n",pop(&S));break;

      case 3: display(S);break;

      default: printf("Invalid Choice\n");
    }
    printf("Do you want to continue: ");
    scanf(" %c",&ch);
  }while(ch == 'y');
  return 0;
}
