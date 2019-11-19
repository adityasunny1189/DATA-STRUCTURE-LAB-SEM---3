#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node NODE;

void push(NODE **head, int ele) {
  NODE *newN;
  newN = (NODE *)malloc(sizeof(NODE));
  if(!newN) {
    printf("Memory allocation error\n");
    return;
  }
  newN->data = ele;
  newN->next = *head;
  *head = newN;
}

int pop(NODE **head) {
  NODE *temp = *head;
  if(temp == NULL) {
    printf("Empty Stack\n");
    return;
  }
  *head = (*head)->next;
  int elem = temp->data;
  free(temp);
  return elem;
}

void display(NODE *head) {
  NODE *temp;
  temp = head;
  while(temp != NULL) {
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  NODE *head = NULL;
  int choice, ele;
  char cnt;
  do {
    printf("1.push\n2.pop\n3.display\nchoice: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: printf("Enter no to push: ");
              scanf("%d",&ele);
              push(&head,ele);
              break;

      case 2: printf("Poped element is: %d\n",pop(&head));break;

      case 3: display(head);break;

      default: printf("invalid choice\n");
    }
    printf("Continue(y/n): ");
    scanf(" %c",&cnt);
  }while(cnt == 'y');
  return 0;
}
