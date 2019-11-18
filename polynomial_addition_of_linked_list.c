#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  int powX;
  int powY;
  struct node *next;
};

typedef struct node NODE;

NODE *getnode() {
  NODE *newNode;
  newNode = (NODE *)malloc(sizeof(NODE));
  return newNode;
}

void insert(NODE **head, int coef, int px, int py) {
  NODE *newN, *temp;
  newN = getnode();
  newN->data = coef;
  newN->powX = px;
  newN->powY = py;
  temp = *head;
  if(*head == NULL)
    *head = newN;
  else {
    while(temp->next != NULL)
      temp = temp->next;
    temp->next = newN;
  }
}

void display(NODE *head) {
  while(head != NULL) {
    printf(" %dx^%dy^%d +",head->data,head->powX,head->powY);
    head = head->next;
  }
  printf("\n");
}

int search(NODE **temp, int coef, int px, int py) {
  NODE *head;
  head = *temp;
  while(head != NULL) {
    if(head->powX == px && head->powY == py)
    {
      printf("%d\t%d\t%d\n",head->data,head->powX,head->powY);
      (*temp)->data += coef;
      return 1;
    }
    head = head->next;
  }
  return 0;
}

void add(NODE *P1, NODE *P2) {
  NODE *temp;
  temp = P1;
  while(P2 != NULL) {
    if(!search(&temp, P2->data, P2->powX, P2->powY))
      insert(&temp, P2->data, P2->powX, P2->powY);
    P2 = P2->next;
  }
  display(temp);
}

int main() {
  int coef, px, py, choice;
  char ch;
  NODE *P1 = NULL, *P2 = NULL;
  do {
    printf("1.Add in Polynomial 1\n2.Add in Polynomial 2\n3.Display Polynomial 1\n4.Display Polynomial 2\n5.Add\nChoice: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: printf("Enter the values\n");
              printf("Coefficient: ");
              scanf("%d",&coef);
              printf("Power of X: ");
              scanf("%d",&px);
              printf("Power of Y: ");
              scanf("%d",&py);
              insert(&P1, coef, px, py);
              break;

      case 2: printf("Enter the values\n");
              printf("Coefficient: ");
              scanf("%d",&coef);
              printf("Power of X: ");
              scanf("%d",&px);
              printf("Power of Y: ");
              scanf("%d",&py);
              insert(&P2, coef, px, py);
              break;

      case 3: display(P1);break;

      case 4: display(P2);break;

      case 5: add(P1, P2);break;

      default:printf("Invalid Choice\n");
    }
    printf("Continue(y/n): ");
    scanf(" %c",&ch);
  } while(ch == 'y');
  return 0;
}
