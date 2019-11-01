#include<stdio.h>
#include<stdlib.h>
#define size 5

struct queue {
  int data[size];
  int rear;
  int front;
};

int empty(struct queue *Q) {
  if(Q->front == -1)
    return 1;
  return 0;
}

int full(struct queue *Q) {
  if((Q->front == 0 && Q->rear == size - 1) || (Q->front - Q->rear == 1))
    return 1;
  return 0;
}

void equeue(struct queue *Q, int ele) {
  if(full(Q)) {
    printf("Cant push data Queue full\n");
  //  return;
  }
  else if(empty(Q)) {
    Q->front = Q->rear = 0;
    Q->data[0] = ele;
  }
  else if(Q->rear == size - 1) {
    Q->rear = 0;
    Q->data[Q->rear] = ele;
  }
  else {
    Q->data[++Q->rear] = ele;
  }
}

int dqueue(struct queue *Q) {
  if(empty(Q)) {
    printf("Empty Queue\n");
    return;
  }
  else if(Q->front == Q->rear) {
    int ele = Q->data[Q->front];
    Q->front = Q->rear = -1;
    return ele;
  }
  else if(Q->front == size - 1) {
    int ele = Q->data[Q->front];
    Q->front = 0;
    return ele;
  }
  else {
    return Q->data[Q->front++];
  }
}

void display(struct queue Q) {
  printf("F-->");
  if(Q.front <= Q.rear) {
    for(int i = Q.front; i <= Q.rear; i++) {
      printf("%d-->",Q.data[i]);
    }
  }
  else {
    for(int i = Q.front; i < size; i++)
      printf("%d-->",Q.data[i]);
    for(int i = 0; i <= Q.rear; i++) {
      printf("%d-->",Q.data[i]);
    }
  }
  printf("R\n");
}


int main() {
  struct queue Q;
  Q.front = Q.rear = -1;
  int choice;
  char ch;
  do {
    /* code */
    printf("1.equeue\n2.dqueue\n3.display\nchoice: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: printf("Enter element to insert: ");
              int ele;
              scanf("%d",&ele);
              equeue(&Q, ele);
              break;

      case 2: printf("Deleted element is: %d\n",dqueue(&Q));
              break;

      case 3: display(Q);
              break;

      default: printf("Invalid choice\n");
    }
    printf("y/n: ");
    scanf(" %c",&ch);
  } while(ch == 'y');
  return 0;
}
