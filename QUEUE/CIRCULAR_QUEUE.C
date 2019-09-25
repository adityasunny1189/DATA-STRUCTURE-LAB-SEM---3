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
    if((Q->front == 0 && Q->rear == SIZE - 1) || (Q->front - Q->rear == 1))
        return 1;
    else
        return 0;
}

/*int spaceAvailable(struct Queue *Q)
{

}

int spaceNotAvailable(struct Queue *Q)
{

}*/

void Equeue(struct Queue *Q, int no)
{
    if(isFull(Q))
    {
        printf("Queue Overflow\n");
        exit(1);
    }
    if(Q->front == -1)
        Q->front++;
    if((Q->rear < SIZE - 1) || ((Q->rear + 1) < Q->front))
        Q->arr[++Q->rear] = no;
}

void Dqueue(struct Queue *Q)
{
    if(isEmpty(Q))
    {
        printf("Queue Underflow\n");
        exit(2);
    }
    if(Q->front == SIZE - 1)
        Q->front = 0;
    else
        Q->front++;
}

void DisplayQueue(struct Queue *Q)
{
    if(Q->rear > Q->front)
    {
        for(int i = Q->front ; i < Q->rear ; i++)
        {
            printf("%d\t",Q->arr[i]);
        }
    }
    else if(Q->front > Q->rear)
    {
        for(int j = Q->front ; j < SIZE -1 ; j++)
            printf("%d\t",Q->arr[j]);
        for(int j = 0 ; j < Q->rear ; j++)
            printf("%d",Q->arr[j]);
    }
}

int main()
{
    int no,choice;
    char cont;
    struct Queue Q;
    Q.rear = Q.front = -1;
    printf("Circular Queue Implementation\n");
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

            case 2: printf("Deleted first element\n");
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
