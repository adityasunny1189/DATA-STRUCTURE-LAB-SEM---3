#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
         int data;
         struct Node *next;
         struct Node *prev;
};

typedef struct Node NODE;

NODE *lastNode = NULL;

NODE *getNode() {
         return (NODE *)malloc(sizeof(NODE));
}

void insert(NODE **head, int data_field, int data) {
         NODE *newN = getNode();
         newN->data = data;
         if(*head == NULL) {
                  *head = newN;
                  return;
         }
         NODE *temp = *head;
         while((temp->data != data_field) && (temp != NULL)){
                  temp = temp->next;         
         }
         if(temp == NULL) {
                  printf("No such data field present\n");
                  return;         
         }
         if(temp->next != NULL) {
                  NODE *nxtNode = temp->next;
                  nxtNode->prev = newN;
         }
         newN->next = temp->next;
         temp->next = newN;
         newN->prev = temp;
         lastNode = *head;
         while(lastNode->next != NULL) 
                  lastNode = lastNode->next;
}

void swapNode(NODE **head, int m, int n) {
         
}

NODE *deleteFirstNode(NODE **head) {

}

void display(NODE *head) {
         if(head == NULL) {
                  printf("Empty List!\n");
                  return;
         }
         while(head != NULL) {
                  printf("%d  ",head->data);
                  head = head->next;         
         }
         printf("\n");
}

int main() {
         int choice, ele, data_field, m, n;
         char ch;
         NODE *start = getNode();
         NODE *head = NULL;
         start->data = 0;
         start->next = head;
         start->prev = NULL;
         do {
                  printf("1.Insert\n2.Delete First Node\n3.Display\n4.Swap Node\nChoice: ");
                  scanf("%d",&choice);
                  switch(choice) {
                           case 1:  printf("Enter data: ");   
                                    scanf("%d",&ele);
                                    printf("Enter data field: ");
                                    scanf("%d",&data_field);
                                    insert(&head, data_field, ele);
                                    start->data++;
                                    break;

                           case 2:  start->next = deleteFirstNode(&head);
                                    start->data--;
                                    break;

                           case 3:  display(head);
                                    break;

                           case 4:  printf("Enter positions(m and n): ");
                                    scanf("%d %d",&m,&n);
                                    swapNode(&head, m, n);
                                    break;

                           default: printf("Invalid Option!!\n");
                  }
                  printf("Do you want to continue: ");
                  scanf(" %c",&ch);
         }while(ch == 'y');
         return 0;
}

















