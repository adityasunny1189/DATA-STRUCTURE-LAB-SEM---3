#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
};

typedef struct Node NODE;

NODE *getnode() {
    NODE *newNode;
    newNode = (NODE *)malloc(sizeof(NODE));
    return newNode;
}

void insertAtFirstPosition(NODE **head, int ele) {
    NODE *newN;
    newN = getnode();
    newN->data = ele;
    newN->next = *head;
    newN->prev = NULL;
    (*head)->prev = newN;
    *head = newN;
}

void insertAtLastPosition(NODE **head, int ele) {
    NODE *newN, *p;
    p = *head;
    newN = getnode();
    newN->data = ele;
    while(p->next != NULL) {
        p = p->next;
    }
    newN->prev = p;
    p->next = newN;
    newN->next = NULL;
}

void insertAtPosition(NODE **head, int pos, int ele) {
    int k = 0;
    NODE *newN, *p, *q;
    newN = getnode();
    newN->data = ele;
    p = *head;
    while(k < pos) {
        k++;
        q = p;
        p = p->next;
    }
    q->next = newN;
    newN->next = p;
    newN->prev = q;
    p->prev = newN;
}

int deleteFirstElement(NODE **head) {
    int ele;
    NODE *p;
    p = *head;
    ele = p->data;
    *head = (*head)->next;
    (*head)->prev = NULL;
    free(p);
    return ele;
}

int deleteLastElement(NODE **head) {
    int ele;
    NODE *p;
    while(p->next != NULL) {
        p = p->next;
    }
    ele = p->data;
    p->prev->next = NULL;
    free(p);
    return ele;
}

int deletePosElement(NODE **head, int pos) {
    NODE *p, *q;
    int ele;
    p = *head;
    int k = 0 ;
    while(k < pos) {
        k++;
        q = p;
        p = p->next;
    }
    ele = p->data;
    q->next = p->next;
    p->next->prev = q;
    free(p);
    return ele;
}

void displayDoublyLinkedList(NODE *head) {
    NODE *p;
    p = head;
    while(p->next != NULL) {
        printf("%d-->",p->data);
        p = p->next;
    }
    printf("%d\n",p->data);
}

int main()
{
    NODE *head = getnode();
    head->data = 0;
    head->next = head->prev = NULL;
    int choice, ele, pos;
    char ch;
    do {
        printf("1.Insert at first position\n2.Insert at last position\n3.Insert at desired position\n4.delete first node\n5.delete last node\n6.delete desired node\n7.Display\nChoice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("Enter element: ");
                    scanf("%d",&ele);
                    insertAtFirstPosition(&head,ele);
                    break;

            case 3: printf("Enter element: ");
                    scanf("%d",&ele);
                    printf("Enter position: ");
                    scanf("%d",&pos);
                    insertAtPosition(&head,pos,ele);
                    break;

            case 2: printf("Enter element: ");
                    scanf("%d",&ele);
                    insertAtLastPosition(&head,ele);
                    break;

            case 4: printf("Deleted element is: %d\n",deleteFirstElement(&head));
                    break;

            case 5: printf("Deleted element is: %d\n",deleteLastElement(&head));
                    break;

            case 6: printf("Enter position of node to delete: ");
                    scanf("%d",&pos);
                    printf("Deleted element is: %d\n",deletePosElement(&head,pos));
                    break;

            case 7: printf("Linked List content\n");
                    displayDoublyLinkedList(head);
                    break;

            default:printf("Invalid choice\n");
        }
        printf("Do you want to continue: ");
        scanf(" %c",&ch);
    }while(ch == 'y');
    return 0;
}
