#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node NODE;

void insert(NODE **head , int ele , int pos)
{
  NODE *p , *q , *newNode;
  int k = 1;
  newNode = (NODE *)malloc(sizeof(NODE));
  if(!newNode)
  {
    printf("Memory Allocation Error\n");
    exit(1);
  }
  newNode->data = ele;
  p = *head;
  if(pos == 1)
  {
    newNode->next = p;
    *head = newNode;
  }
  else
  {
    while((p != NULL) && (k < pos))
    {
      k++;
      q = p;
      p = p->next;
    }
    q->next = newNode;
    newNode->next = p;
  }
}

int delete(NODE **head , int pos)
{
  NODE *p , *q ;
  int k = 1;
  int ele;
  p = *head;
  if(p == NULL)
  {
    printf("Can't Delete from empty list\n");
    exit(1);
  }
  if(pos == 1)
  {
    *head = (*head)->next;
    ele = p->data;
    free(p);
  }
  else
  {
    while((p != NULL) && (k < pos))
    {
      k++;
      q = p;
      p = p->next;
    }
    if(p == NULL)
    {
      printf("Position Not Found\n");
      exit(1);
    }
    else
    {
      q->next = p->next;
      ele = p->data;
      free(p);
    }
  }
  return ele;
}

void Display(NODE *head)
{
  NODE *p;
  p = head;
  if(p == NULL)
  {
    printf("Empty LIST\n");
    exit(1);
  }
  do {
    printf("%d\t",p->data);
    p = p->next;
  } while(p != NULL);
  printf("\n");
}

void reverse(NODE **head)
{
  NODE *current, *prev, *next;
  current = *head;
  prev = NULL;
  while(current != NULL)
  {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  *head = prev;
}

int addList(NODE *head)
{
  int sum = 0;
  NODE *p;
  p = head;
  while(p != NULL)
  {
    sum += p->data;
    p = p->next;
  }
  return sum;
}

int main()
{
  NODE *head = NULL;
  int choice;
  char ch;
  do {
    printf("1.Insert\n2.Delete\n3.Display\n4.Reverse\n5.Add List\nChoice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: printf("Insert Call\n");
              int ele, pos;
              printf("Enter Element : ");
              scanf("%d",&ele);
              printf("Enter Position: ");
              scanf("%d",&pos);
              insert(&head , ele , pos);
              break;

      case 2: printf("Delete Call\n");
              printf("Enter position: ");
              int position;
              scanf("%d",&position);
              printf("Deleted Element is %d\n",delete(&head , position));
              break;

      case 3: printf("Display Call\n");
              Display(head);
              break;

      case 4: reverse(&head);
              break;

      case 5: printf("The sum of elements of Linked List is : %d\n",addList(head));
              break;

      default: printf("Invalid Choice\n");
    }
    printf("Do you want to continue(y/n): ");
    scanf(" %c",&ch);
  } while(ch == 'y');
  return 0;
}
