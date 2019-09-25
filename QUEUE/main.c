#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

struct Queue
{
    int rear,front;
    int arr[SIZE];
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
    //if((Q->rear + 1) % SIZE == Q->front)
    if(Q->rear == SIZE - 1)
        return 1;
    else
        return 0;
}

void Equeue(struct Queue *Q, int no)
{
    if(isFull(Q))
    {
        printf("Queue Overflow\n");
        exit(1);
    }
    Q->rear++;
    Q->arr[Q->rear] = no;
    if(Q->front == -1)
        Q->front++;
}

void Dqueue(struct Queue *Q)
{
    if(isEmpty(Q))
    {
        printf("Queue Underflow\n");
        exit(2);
    }
    Q->front++;
}

void DisplayQueue(struct Queue *Q)
{
    for(int i = Q->front ; i <= Q->rear ; i++)
    {
        printf("%d\t",Q->arr[i]);
    }
}

int main()
{
    int no,choice;
    char cont;
    struct Queue Q;
    Q.rear = Q.front = -1;
    printf("Queue Implementation\n");
    do
    {
        printf("Enter your choice\n1.EQUEUE\n2.DQUEUE\n3.DISPLAY\n4.EXIT\nChoice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter no to insert: ");
                    scanf("%d",&no);
                    Equeue(&Q,no);
                    break;

            case 2: printf("Deleting First Element\n");
                    Dqueue(&Q);
                    break;

            case 3: printf("FRONT -> ");
                    DisplayQueue(&Q);
                    printf(" <- REAR\n");
                    break;

            case 4: printf("Thank You\n");
                    exit(0);

            default: printf("Invalid choice\n");
        }
        printf("Do you want to continue(y/n): ");
        scanf(" %c",&cont);
    } while (cont == 'y');
    return 0;
}
