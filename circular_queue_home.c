#include<stdio.h>
#include<stdlib.h>

#define size 4

struct Queue
{
    int data[size];
    int front,rear;
};

int isEmpty(struct Queue *Q)
{
    if(Q->front == -1)
      return 1;
    else
      return 0;
}

int isFull(struct Queue *Q)
{
    if((Q->rear == size - 1 && Q->front == 0) || (Q->front - Q->rear == 1))
      return 1;
    else
      return 0;
}

void Equeue(struct Queue *Q, int no)
{
    if(isFull(Q))
    {
      printf("Queue Full Can't Push No\n");
      exit(1);
    }
    else if(isEmpty(Q))
    {
      Q->front = Q->rear = 0;
      Q->data[0] = no;
    }
    else if(Q->rear == size - 1)
    {
      Q->rear = 0;
      Q->data[Q->rear] = no;
    }
    else
    {
      Q->data[++Q->rear] = no;
    }
}

void Dqueue(struct Queue *Q)
{
    if(isEmpty(Q))
    {
      printf("Queue Empty Can't delete element\n");
      exit(1);
    }
    else if(Q->front == size - 1)
    {
      printf("Deleted Elemet is %d\n",Q->data[Q->front]);
      Q->front = 0;
    }
    else if(Q->rear == Q->front)
    {
      printf("Deleted Element is %d\n",Q->data[Q->front]);
      Q->front = Q->rear = -1;
    }
    else
    {
      printf("Deleted Elemet is %d\n",Q->data[Q->front++]);
    }
}

void Display(struct Queue Q)
{
  if(isEmpty(&Q))
  {
    printf("Queue Empty!\n");
    exit(1);
  }
  if(Q.rear == size - 1)
  {
    for(int i = Q.front ; i <= Q.rear ; i++)
      printf("%d\t",Q.data[i]);
  }
  else if(Q.rear < Q.front)
  {
    for(int i = Q.front ; i <= size - 1 ; i++)
      printf("%d\t",Q.data[i]);
    for(int i = 0 ; i <= Q.rear ; i++)
      printf("%d\t",Q.data[i]);
  }
  else if(Q.front < Q.rear)
  {
    for(int i = Q.front ; i <= Q.rear ; i++)
      printf("%d\t",Q.data[i]);
  }
  else if(Q.rear == Q.front)
  {
    printf("%d\t",Q.data[Q.rear]);
  }
  else
  {
    for(int i = Q.front ; i <= size - 1 ; i++)
      printf("%d\t",Q.data[i]);
    for(int i = 0 ; i <= Q.rear ; i++)
      printf("%d\t",Q.data[i]);
  }
  printf("\n");
}

int main()
{
    printf("Circular Queue Implementation\n");
    struct Queue Q;
    Q.front = -1;
    Q.rear = -1;
    char choice ;
    int ch;
    do {
      printf("1.Enqueue\n2.Dequeue\n3.Display\nYour Choice: ");
      scanf("%d",&ch);
      switch (ch) {
        case 1: printf("Enter no to insert: ");
                int no;
                scanf("%d",&no);
                Equeue(&Q,no);
                break;

        case 2: Dqueue(&Q);
                break;

        case 3: Display(Q);
                break;

        case 4: exit(0);

        default: printf("Invalid Choice\n");
      }
      printf("Do you want to continue: ");
      scanf(" %c",&choice);
    } while(choice == 'y');
    return 0;
}
