#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

void insertElementInLinkedList(struct Node **head , int ele , int pos)
{
  int k = 1;
  struct Node *p , *q , *newNode;
  newNode = (struct Node *)malloc(sizeof(struct Node));
  p = *head;
  newNode->data = ele;
  if(pos == 1)
  {
    newNode->next = p;
    *head = newNode;
    return;
  }
  else
  {
    while(k < pos)
    {
      k++;
      q = p;
      p = p->next;
    }
    q->next = newNode;
    newNode->next = p;
    return;
  }
  q = *head;
  while(q != NULL)
  {
    q = q->next;
  }
  q->next = newNode;
  newNode->next = NULL;
}

void displayLinkedList(struct Node *head)
{
  struct Node *i;
  i = head;
  while(i != NULL)
  {
    printf("%d",i.data);
    i = i->next;
  }
}

int main()
{
  struct Node *head;
  printf("SINGLY LINKED LIST IMPLEMENTATION\n");
  int choice;
  char cnt;
  do {
    printf("1.Insert\n2.Delete\n3.Display\n4.Exit\nChoice : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1:

      case 2:

      case 3:

      case 4: exit(0);

      default : printf("Invalid Choice!");
    }
    printf("Do you Want to continue(y/n): ");
    scanf("%c",&cnt);
  } while(cnt = 'y');
  return 0;
}
