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
  NODE *p;
  p = *head;
  if(p == NULL) {
    printf("Empty list\n");
  }
  else {
    int ele = p->data;
    *head = p->next;
    free(p);
    return ele;
  }
}

int mid(NODE *head) {
  NODE *p, *q;
  p = head;
  q = head;
  int k = 0, m = 0;
  while(p->next != NULL) {
    k++;
    p = p->next;
  }
  while(m < k/2) {
    q = q->next;
    m++;
  }
  return q->data;
}

int main() {
  char ch;
  int ele;
  NODE *top = NULL;
  do {
    int choice;
    printf("1.Insert\n2.Delete\n3.mid\nChoice : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: printf("Enter element to insert: ");
              scanf("%d",&ele);
              push(&top,ele);
              break;

      case 2: printf("Deleted element is %d\n",pop(&top));
              break;

      case 3: printf("%d\n",mid(top));
              break;

      default: printf("Invalid choice\n");
    }
    printf("Do you want to continue: ");
    scanf(" %c",&ch);
  } while(ch == 'y');
  return 0;
}
