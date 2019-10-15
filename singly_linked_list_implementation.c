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
  if(!newNode)
  {
    printf("Memory Allocation Error\n");
    return ;
  }
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

void displayLinkedList(struct Node **head)
{
  struct Node *i;
  i = *head;
  while(i != NULL)
  {
    printf("%d",i->data);
    i = i->next;
  }
}

int deleteElementInLinkedList(struct Node **head, int pos)
{
  int k = 1, ele;
  struct Node *p, *q;
  p = *head;
  if(pos == 1)
  {
    ele = p->data;
    *head = p->next;
    free(p);
  }
  else
  {
    while(k < pos)
    {
      k++;
      q = p ;
      p = p->next;
    }
    if(p == NULL)
    {
      printf("Position not found\n");
      exit(1);
    }
    else
    {
      ele = p->data;
      q->next = p->next;
      free(p);
    }
  }
  return ele;
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
      case 1: printf("Choice to Insert no in Linked List\n");
              printf("Enter no to Insert: ");
              int ele, pos;
              scanf("%d",&ele);
              printf("Enter the position: ");
              scanf("%d",&pos);
              insertElementInLinkedList(&head, ele, pos);
              break;

      case 2: printf("Choice to delete the node\n");
              printf("Enter the position of node to delete: ");
              int position;
              scanf("%d",&position);
              printf("Deleted Node Element is: %d",deleteElementInLinkedList(&head, position));
              break;

      case 3: printf("Linked List is: ");
              displayLinkedList(&head);
              break;

      case 4: exit(0);

      default : printf("Invalid Choice!");
    }
    printf("Do you Want to continue(y/n): ");
    scanf("%c",&cnt);
  } while(cnt = 'y');
  return 0;
}
