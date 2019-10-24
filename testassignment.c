#include<stdio.h>
#include<stdlib.h>

struct stack
{
  int data[20];
  int top;
};

int isEmpty(struct stack *s)
{
  if(s->top == -1)
    return 1;
  else
    return 0;
}

int isFull(struct stack *s)
{
  if(s->top == 19)
    return 1;
  else
    return 0;
}

void push(struct stack *s,int ele)
{
  if(isFull(s))
  {
    printf("\nno space left\n");
    return;
  }
  s->data[++s->top] = ele;
}

int pop(struct stack *s)
{
  if(isEmpty(s))
  {
    printf("\nempty list\n");
    exit(1);
  }
  return s->data[s->top--];
}

void insert(struct stack *s)
{
  int ele;
  printf("\nEnter no to insert: ");
  scanf("%d",&ele);
  push(s,ele);
}

void delete(struct stack *s , struct stack *s2)
{
  if(s2->top == -1)
  {
    while(s->top != -1)
    {
        push(s2,pop(s));
    }
  }
  printf("\nDeleted element is: %d\n",pop(s2));
}

int main()
{
  struct stack s1,s2;
  s1.top = s2.top = -1;
  int choice;
  char ch;
  do {
    printf("\n1.insert\n2.delete\nchoice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: insert(&s1);break;
      case 2: delete(&s1,&s2);break;
      case 3: display(s2);break;
      default: printf("\nInvalid\n");
    }
    printf("\ncontinue: ");
    scanf(" %c",&ch);
  } while(ch == 'y');
  return 0;
}
