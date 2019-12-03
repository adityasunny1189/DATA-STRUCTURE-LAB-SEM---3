#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

typedef struct node Node;

Node *lastNode = NULL;

Node *getnode() {
  return (Node *)malloc(sizeof(Node));
}

void insert(Node **head, int data, int pos) {
  Node *p = *head, *q, *temp = getnode();
  int k = 0;
  if(!temp) {
    printf("Memory allocation error\n");
    return;
  }
  temp->data = data;
  if(pos == 1) {
    temp->prev = NULL;
    temp->next = *head;
    if(*head)
      (*head)->prev = temp;
    *head = temp;
  }
  else {
    while((p != NULL) && (k < pos)) {
      q = p;
      p = p->next;
      k++;
    }
      q->next = temp;
      temp->prev = q;
      temp->next = p;
      if(p)
        p->prev = temp;
  }
  lastNode = *head;
  while(lastNode->next != NULL)
    lastNode = lastNode->next;
}

void display(Node *head) {
  while(head != NULL) {
    printf("%d ",head->data);
    head = head->next;
  }
  printf("\n");
}

Node *delete_firstNode(Node **head) {
  Node *temp = lastNode;
  while(temp->prev != NULL)
    temp = temp->prev;
  if(temp->next == NULL) {
    lastNode = NULL;
    *head = NULL;
    return *head;
  }
  *head = temp->next;
  free(temp);
  return *head;
}

int main() {
  int no,choice,pos;
  char ch;
  Node *start;
  Node *head;
  start->data = 0;
  start->prev = NULL;
  head = NULL;
  start->next = head;
  // head->next = head->prev = NULL;
  do {
    /* code */
    printf("1.Insert\n2.Display\n3.Delete first node\nChoice: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: printf("Enter no insert: ");
              scanf("%d",&no);
              printf("Enter position to insert: ");
              scanf("%d",&pos);
              insert(&head,no,pos);
              start->data++;
              break;

      case 2: display(head);
              break;

      case 3: start->next = delete_firstNode(&head);
              break;

      case 4: printf("%d\n",lastNode->data);break;

      default: printf("Invalid Option!!!\n");
    }
    printf("Continue: ");
    scanf(" %c",&ch);
  } while(ch == 'y');
}
