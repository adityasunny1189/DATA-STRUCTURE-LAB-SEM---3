#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

typedef struct node NODE;

NODE *front = NULL;
NODE *rear = NULL;

void insertFront(int ele) {
  NODE *newN;
  newN = (NODE *)malloc(sizeof(NODE));
  if(newN == NULL) {
    printf("Memory allocation error\n");
    return;
  }
  newN->data = ele;
  if(front == NULL)
    front = rear = newN;
  else {
    front->prev = newN;
    newN->next = front;
    front = newN;
  }
}

void insertRear(int ele) {
  NODE *newN;
  newN = (NODE *)malloc(sizeof(NODE));
  if(newN == NULL) {
    printf("Memory allocation error\n");
    return;
  }
  newN->data = ele;
  if(rear == NULL)
    front = rear = newN;
  else {
    rear->next = newN;
    newN->prev = rear;
    rear = newN;
  }
}

int deleteFront() {
  NODE *temp = front;
  if(front == rear) {
    int elem = front->data;
    front = rear = NULL;
    return elem;
  }
  front = front->next;
  front->prev = NULL;
  int ele = temp->data;
  free(temp);
  return ele;
}

int deleteRear() {
  NODE *temp = rear;
  if(front == rear) {
    int elem = rear->data;
    front = rear = NULL;
    return elem;
  }
  int ele = temp->data;
  rear = rear->prev;
  rear->next = NULL;
  free(temp);
  return ele;
}

void display() {
  NODE *temp = front;
  while(temp != NULL) {
    printf("%d-->",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int main() {
  int choice,ele;
  char cnt;
  do {
    /* code */
    printf("1.Insert Front\n2.Insert Rear\n3.Delete Front\n4.Delete Rear\n5.Display\nChoice: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: printf("Enter no to insert: ");
              scanf("%d",&ele);
              insertFront(ele);
              break;

      case 2: printf("Enter no to insert: ");
              scanf("%d",&ele);
              insertRear(ele);
              break;

      case 3: printf("Deleted node is : %d\n",deleteFront());break;

      case 4: printf("Deleted rear elem is: %d\n",deleteRear());break;

      case 5: display();break;

      default: printf("Invalid choice\n");
    }
    printf("Continue(y/n): ");
    scanf(" %c",&cnt);
  } while(cnt == 'y');
  return 0;
}
