#include<stdio.h>
#include<stdlib.h>

#define size 5

struct Cqueue {
  int data[size];
  int front;
  int rear;
};

int isFull(struct Cqueue *CQ) {
  if((CQ->rear == size - 1 && CQ->front == 0) || (CQ->front - CQ->rear == 1))
    return 1;
  return 0;
}

int isEmpty(struct Cqueue *CQ) {
  if(CQ->front == -1)
    return 1;
  return 0;
}

void insert(struct Cqueue *CQ, int data) {
  if(isFull(CQ)) {
    printf("Queue Full!!!\n");
    return;
  }
  else if(isEmpty(CQ)) {
    CQ->front = CQ->rear = 0;
    CQ->data[0] = data;
  }
  else if(CQ->rear == size - 1) {
    CQ->rear = 0;
    CQ->data[0] = data;
  }
  else {
    CQ->data[++CQ->rear] = data;
  }
}

int delete(struct Cqueue *CQ) {
  if(isEmpty(CQ)) {
    printf("Queue Empty!!!\n");
    return 0;
  }
  else if(CQ->front == CQ->rear) {
    int ele = CQ->data[CQ->front];
    CQ->front = CQ->rear = -1;
    return ele;
  }
  else if(CQ->front == size - 1) {
    int ele = CQ->data[CQ->front];
    CQ->front = 0;
    return ele;
  }
  else {
    return CQ->data[CQ->front++];
  }
}

void display(struct Cqueue CQ) {
  if(CQ.front == -1) {
    printf("Empty Queue\n");
    return;
  }
  else if(CQ.front <= CQ.rear) {
    for(int i = CQ.front; i <= CQ.rear; i++) {
      printf("%d ",CQ.data[i]);
    }
  }
  else {
    for(int i = CQ.front; i <= size - 1; i++) {
      printf("%d ",CQ.data[i]);
    }
    for(int i = 0; i <= CQ.rear; i++) {
      printf("%d ",CQ.data[i]);
    }
  }
  printf("\n");
}

int main() {
  struct Cqueue CQ;
  CQ.front = CQ.rear = -1;
  char ch;
  int choice, ele;
  do {
    /* code */
    printf("1.Insert\n2.Delete\n3.Display\nChoice: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: printf("Enter no to insert: ");
              scanf("%d",&ele);
              insert(&CQ,ele);
              break;

      case 2: printf("Deleted element is: %d\n",delete(&CQ));break;

      case 3: display(CQ);break;

      default: printf("Invalid Choice\n");
    }
    printf("Do you want to continue: ");
    scanf(" %c",&ch);
  } while(ch == 'y');
  return 0;
}
