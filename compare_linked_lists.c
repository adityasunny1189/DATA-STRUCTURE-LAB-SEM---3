#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
  char data;
  struct node *next;
};

typedef struct node NODE;

void insert(NODE **head, char ele) {
  NODE *newNode;
  newNode = (NODE *)malloc(sizeof(NODE));
  newNode->data = ele;
  newNode->next = *head;
  *head = newNode;
}

int compare(NODE *l1, NODE *l2) {
  NODE *list1, *list2;
  list1 = l1;
  list2 = l2;
  while(list1 != NULL || list2 != NULL) {
    if(list1->data == list2->data) {
      list1 = list1->next;
      list2 = list2->next;
    }
    if(list1 != NULL && list2 == NULL)
      return 1;
    else if(list1 == NULL && list2 != NULL)
      return -1;
  }
  return 0;
}

void display(NODE *head) {
  NODE *p;
  p = head;
  while(p != NULL) {
    printf("%d-->",p->data);
  }
  printf("\n");
}

int main() {
  NODE *l1, *l2;
  char cnt;
  int choice, ele;
  l1 = l2 = NULL;
  do {
    printf("1.Insert list 1\n2.Insert list 2\n3.display\n4.compare\n5.exit\nChoice: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: printf("Enter element to insert: ");
              scanf("%d",&ele);
              insert(&l1,ele);
            break;

      case 2: printf("Enter no to insert: ");
              scanf("%d",&ele);
              insert(&l2,ele);
            break;

      case 3: printf("List 1: ");
              display(l1);
              printf("\nList 2: ");
              display(l2);
            break;

      case 4: printf("The relation is: %d",compare(l1,l2));
            break;

      case 5: exit(0);

      default:printf("Invalid coice\n");
    }
    printf("Continue: ");
    scanf(" %c",&cnt);
  }while(cnt == 'y');
  return 0;
}
