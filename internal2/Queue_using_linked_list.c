#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node NODE;

void equeue(NODE **head, int ele) {
  NODE *newN, *temp;
  temp = *head;
  newN = (NODE *)malloc(sizeof(NODE));
  if(!newN) {
    printf("Memory allocation error\n");
    return;
  }
  newN->data = ele;
  newN->next = NULL;
  if(temp == NULL) {
    *head = newN;
  }
  else {
    while(temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newN;
  }
}

int dqueue(NODE **head) {
  NODE *temp = *head;
  if(*head == NULL) {
    printf("Empty Queue\n");
    return;
  }
  int ele = temp->data;
  *head = (*head)->next;
  free(temp);
  return ele;
}

void display(NODE *head) {
  NODE *temp = head;
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
    printf("1.Equeue\n2.Dqueue\n3.display\nchoice: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: printf("Enter no to insert: ");
              scanf("%d",&ele);
              equeue(&head,ele);
              break;

      case 2: printf("Poped element is: %d\n",dqueue(&head));break;

      case 3: display(head);break;

      default: printf("invalid choice\n");
    }
    printf("Continue(y/n): ");
    scanf(" %c",&cnt);
  }while(cnt == 'y');
  return 0;
}
