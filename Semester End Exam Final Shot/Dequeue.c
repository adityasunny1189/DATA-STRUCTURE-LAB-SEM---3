#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

typedef struct node Node;

Node *front = NULL;
Node *rear = NULL;

void insertFront(int ele) {
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  temp->data = ele;
  if(front == NULL) {
    front = temp;
    rear = front;
  }
  else {
    temp->next = front;
    front->prev = temp;
    front = temp;
  }
}

void insertRear(int ele) {
  Node *temp;
  temp = (Node *)malloc(sizeof(Node));
  temp->data = ele;
  if(rear == NULL) {
    rear = temp;
    front = rear;
  }
  else {
    temp->prev = rear;
    rear->next = temp;
    rear = temp;
  }
}

void deleteFront() {
  int ele = front->data;
  front = front->next;
  front->prev = NULL;
  printf("Deleted element from front end is: %d\n",ele);
}

void deleterear() {
  int ele = rear->data;
  rear = rear->prev;
  rear->next = NULL;
  printf("Deleted data from rear end: %d\n",ele);
}

void display() {
  Node *temp = front;
  while(temp != NULL) {
    printf("%d ",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  int choice,ele;
  char ch;
  do {
    /* code */
    printf("1.Insert Front\n2.Insert Last\n3.Display Front\n5.Delete Front\n6.Delete Last\nChoice: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: printf("Enter No to insert: ");
              scanf("%d",&ele);
              insertFront(ele);
              break;

      case 2: printf("Enter No to insert: ");
              scanf("%d",&ele);
              insertRear(ele);
              break;

      case 3: display();break;

      case 5: deleteFront();break;

      case 6: deleterear();break;

      default: printf("Invalid Option\n");
    }
    printf("Do you want to continue: ");
    scanf(" %c",&ch);
  } while(ch == 'y');
  return 0;
}
