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

int main()
{
  printf("SINGLY LINKED LIST IMPLEMENTATION\n");
  return 0;
}
