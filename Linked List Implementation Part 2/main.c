#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;

    struct Node *next;
};

typedef struct Node NODE;

void insert(NODE **head , int data)
{
    NODE *temp;

    temp = (NODE *)malloc(sizeof(NODE));

    if(!temp)
    {
        printf("Memory allocation error\n");

        return;
    }

    temp->data = data;

    temp->next = *head;

    *head = temp;
}

void display(NODE *head)
{
    NODE *temp;

    temp = head;

    if(temp == NULL)
    {
        printf("Empty list\n");

        return;
    }

    do
    {
        printf("%d\t",temp->data);

        temp = temp->next;

    }while(temp != NULL);

    printf("\n");
}

NODE *intersection(NODE *head1 , NODE *head2)
{
    NODE *temp1, *temp2, *intersected_node;

    intersected_node = (NODE *)malloc(sizeof(NODE));

    temp1 = head1;

    temp2 = head2;

    if(temp1 == NULL || temp2 == NULL)
    {
        printf("Empty List");

        return NULL;
    }

    while(temp1 != NULL)
    {

        while(temp2 != NULL)
        {

            if(temp1->data == temp2->data)
            {

                insert(&intersected_node, temp1->data);
            }

            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return intersected_node;
}

NODE *union_of_lists(NODE *head1, NODE *head2)
{
    NODE *temp1, *temp2, *union_node;

    temp1 = head1;

    temp2 = head2;

    if(temp1 == NULL || temp2 == NULL)
    {
        printf("Empty List");

        return NULL;
    }

    union_node = (NODE *)malloc(sizeof(NODE));


}


int main()
{

    NODE *head1 = NULL,     *head2 = NULL;

    int     ele1,   ele2,   data_to_insert,     choice;

    char continue_the_process;

    printf("\nIntersection and Union Implementation\n");

    printf("Enter the list 1\n");

    printf("\nEnter the no of elements in list 1: ");

    scanf("%d",&ele1);

    printf("\nEnter the elements: \n");

    for(int i = 0; i < ele1; i++)
    {
        scanf("%d",&data_to_insert);

        insert(&head1, data_to_insert);
    }

    printf("\nEnter the list 2\n");

    printf("\nEnter the no of elements in list 2: ");

    scanf("%d",&ele2);

    printf("\nEnter the elements: \n");

    for(int i = 0; i < ele2; i++)
    {
        scanf("%d",&data_to_insert);

        insert(&head2, data_to_insert);
    }

    do
    {
        printf("\n1.View list 1\n2.View list 2\n3.Intersection\n4.Union\n5.Exit\nChoice: ");

        scanf("%d",&choice);

        switch(choice)
        {
            case 1: display(head1);break;

            case 2: display(head2);break;

            case 3: display(intersection(head1, head2));break;

            case 4: display(union_of_lists(head1, head2));

            case 5: exit(0);

            default: printf("Invalid choice\n");
        }

        printf("\nDo you want to continue: ");

        scanf(" %c",&continue_the_process);

    }while(continue_the_process == 'y');

    return 0;
}
