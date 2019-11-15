#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

typedef struct node NODE;

NODE *getnode() {
  NODE *newNode;
  newNode = (NODE *)malloc(sizeof(NODE));
  return newNode;
}

void insert(NODE **head, int ele) {
  NODE *newN;
  newN = getnode();
  newN->data = ele;
  newN->next = *head;
  *head = newN;
}

void display(NODE *head) {
  NODE *temp;
  temp = head;
  while(temp != NULL) {
    printf("%d-->",temp->data);
    temp = temp->next;
  }
  printf("\n");
}

int search(NODE *head, int ele) {
  while(head != NULL) {
    if(ele == head->data)
      return 1;
    head = head->next;
  }
  return 0;
}

void union_list(NODE *List1, NODE *List2) {
  NODE *temp;
  temp = List1;
  while(List2 != NULL) {
    if(!search(temp,List2->data))
      insert(&temp,List2->data);
    List2 = List2->next;
  }
  display(temp);
}

void Intersection_list(NODE *List1, NODE *List2) {
  NODE *temp1, *temp2 = NULL;
  temp1 = List1;
  while(List2 != NULL) {
    if(search(temp1, List2->data))
      insert(&temp2, List2->data);
    List2 = List2->next;
  }
  display(temp2);
}

int main() {
  int choice;
  char ch;
  int ele;
  NODE *List1head = NULL , *List2head = NULL;
  do {
    /* code */
    printf("1.Insert List1\n2.Insert List2\n3.Display List1\n4.Display List2\n5.Union\n6.Intersection\nChoice: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: printf("Enter no to insert: ");
              scanf("%d",&ele);
              insert(&List1head, ele);
              break;

      case 2: printf("Enter no to insert: ");
              scanf("%d",&ele);
              insert(&List2head, ele);
              break;

      case 3: display(List1head);break;

      case 4: display(List2head);break;

      case 5: union_list(List1head, List2head);break;

      case 6: Intersection_list(List1head, List2head);break;

      default:printf("Invalid Choice\n");
    }
    printf("Continue(y/n): ");
    scanf(" %c",&ch);
  } while(ch == 'y');
  return 0;
}
