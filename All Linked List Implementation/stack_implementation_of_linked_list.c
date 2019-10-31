#include<stdio.h>
#include<stdlib.h>

//Defining a structure for node
struct Node {
  int data;
  struct Node *next;
};

typedef struct Node NODE;

//push function for pushing a element at top of stack
//here i am adding the element at the front of the List
void push(NODE **head, int ele) {
  NODE *newNode;
  newNode = (NODE *)malloc(sizeof(NODE));
  if(!newNode) {
    printf("Memory allocation error\n");
    return;
  }
  newNode->data = ele;
  newNode->next = *head;
  *head = newNode;
}

//Pop function to delete top of stack
//here i am deleting the first node
int pop(NODE **head) {
  if(*head == NULL) {
    printf("Empty list\n");
    return;
  }
  int ele = (*head)->data;
  *head = (*head)->next;
  return ele;
}

int main() {
  char ch;
  int ele;
  NODE *top = NULL;
  do {
    int choice;
    printf("1.Insert\n2.Delete\nChoice : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: printf("Enter element to insert: ");
              scanf("%d",&ele);
              push(&top,ele);
              break;

      case 2: printf("Deleted element is %d\n",pop(&top));
              break;

      default: printf("Invalid choice\n");
    }
    printf("Do you want to continue: ");
    scanf(" %c",&ch);
  } while(ch == 'y');
  return 0;
}
