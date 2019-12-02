#include<stdio.h>
#include<stdlib.h>

#define size 5

struct queue {
  int data[size];
  int front;
  int rear;
};

int isFull(struct queue *Q) {
  if(Q->rear == size - 1)
    return 1;
  return 0;
}

int isEmpty(struct queue *Q) {
  if(Q->front == -1)
    return 1;
  return 0;
}

void insert(struct queue *Q, int data) {
  if(isFull(Q)) {
    printf("Can't insert in full Queue\n");
    return;
  }
  else if(isEmpty(Q)) {
    Q->rear = Q->front = 0;
    Q->data[Q->rear] = data;
    return;
  }
  Q->data[++Q->rear] = data;
}

int pop(struct queue *Q) {
  if(isEmpty(Q)) {
    printf("Queue Empty!!!\n");
    return;
  }
  else if(Q->front == Q->rear) {
    int ele = Q->data[Q->front];
    Q->front = Q->rear = -1;
    return ele;
  }
  return Q->data[Q->front++];
}

void display(struct queue Q) {
  if(Q.front == -1) {
    printf("Empty Queue\n");
    return;
  }
  for(int i = Q.front; i <= Q.rear; i++) {
    printf("%d ",Q.data[i]);
  }
  printf("\n");
}

int main() {
  struct queue Q;
  Q.front = Q.rear = -1;
  char ch;
  int choice, ele;
  do {
    /* code */
    printf("1.Insert\n2.Delete\n3.Display\nChoice: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: printf("Enter no to insert: ");
              scanf("%d",&ele);
              insert(&Q,ele);
              break;

      case 2: printf("Deleted element is: %d\n",pop(&Q));break;

      case 3: display(Q);break;

      default: printf("Invalid Choice\n");
    }
    printf("Do you want to continue: ");
    scanf(" %c",&ch);
  } while(ch == 'y');
  return 0;
}
