//Single linked list Program

#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

void insert(Node **head, int data, int pos) {
    Node *temp, *p = *head, *q;
    int k = 1;
    temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if(*head == NULL) {
        *head = temp;
        return;
    }
    else if(pos == 1) {
        temp->next = *head;
        *head = temp;
        return;
    }
    else {
        while(k < pos && p != NULL) {
            k++;
            q = p;
            p = p->next;
        }
        q->next = temp;
        temp->next = p;                          
    }
}

void delete(Node **head, int pos) {
    Node *p = *head, *q;
    int k = 1;
    if(*head == NULL) {
        printf("No element to delete\n");
        return;
    }
    if(pos == 1) {
        *head = (*head)->next;
        printf("Deleted Element: %d\n",p->data);
        free(p);
    }
    else {
        while(k < pos && p != NULL) {
            k++;
            q = p;
            p = p->next;
        }
        if(p) {
            q->next = p->next;
            printf("Deleted Element: %d\n",p->data);
            free(p);
        }
        else {
            printf("Error in finding position!!!\n");
        }
    }
} 

void display(Node *head) {
    if(head == NULL) {
        printf("Error in finding elements!!!\n");
        return;
    }
    while(head) {
        printf("%d\t",head->data);
        head = head->next;
    }
    printf("\n");
}


void reverse(Node **head) {
    Node *cur, *next, *prev;
    prev = NULL;
    cur = *head;
    while(cur != NULL) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    *head = prev;
}

int main() {
    Node *head = NULL;
    int ele, pos, choice;
    char ch;
    do {
        printf("1.insert\n2.delete\n3.display\n4.reverse\nchoice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("Enter element with position: ");
                    scanf("%d %d",&ele, &pos);
                    insert(&head, ele, pos);
                    break;

            case 2: printf("Enter the desired element position to delete: ");
                    scanf("%d",&pos);
                    delete(&head, pos);
                    break;

            case 3: display(head);
                    break;

            case 4: reverse(&head);
                    break;

            default: printf("out of choices!!!\n");
        }
    printf("Do you want to continue: ");
    scanf(" %c",&ch);
    }while(ch == 'y');
}


















