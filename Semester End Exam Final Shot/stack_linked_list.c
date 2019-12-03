#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node Node;

void push(Node **head,int ele) {
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = ele;
  temp->next = *head;
  *head = temp;
}

void pop(Node **head) {
  int ele = (*head)->data;
  *head = (*head)->next;
  printf("Deleted node is: %d",ele);
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
    printf("1.push\n2.pop\n3.display\nchoice: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: printf("Enter no to insert: ");
              scanf("%d",&ele);
              push(&head,ele);
              break;

      case 2: pop(&head);
              break;

      case 3: display(head);break;

      default: printf("Invalid option!!\n");
    }
    printf("Do you want to continue: ");
    scanf(" %c",&ch);
  } while(ch == 'y');
}
