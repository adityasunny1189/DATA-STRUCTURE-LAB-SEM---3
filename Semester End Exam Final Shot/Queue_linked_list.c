#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node Node;

void insert(Node **head,int ele) {
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = ele;
  temp->next = NULL;
  Node *p = *head;
  if(*head == NULL) {
    *head = temp;
    return;
  }
  while(p->next != NULL) {
    p = p->next;
  }
  p->next = temp;
}

void reverse(Node **head) {
  Node *prev = NULL;
  Node *cur = *head;
  Node *next;
  while(cur != NULL) {
    next = cur->next;
    cur->next = prev;
    prev = cur;
    cur = next;
  }
  *head = prev;
}

void delete(Node **head) {
  Node *p = *head;
  int ele = p->data;
  *head = (*head)->next;
  free(p);
  printf("Deleted node is: %d\n",ele);
}

void display(Node *head) {
  while(head != NULL) {
    printf("%d ",head->data);
    head = head->next;
  }
  printf("\n");
}

int main() {
  Node *head = NULL;
  int choice,ele;
  char ch;
  do {
    /* code */
    printf("1.Insert\n2.delete\n3.display\nchoice: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: printf("Enter no to insert: ");
              scanf("%d",&ele);
              insert(&head,ele);
              break;

      case 2: delete(&head);
              break;

      case 3: display(head);break;

      case 4: reverse(&head);break;

      default: printf("Invalid option!!\n");
    }
    printf("Do you want to continue: ");
    scanf(" %c",&ch);
  } while(ch == 'y');
}
