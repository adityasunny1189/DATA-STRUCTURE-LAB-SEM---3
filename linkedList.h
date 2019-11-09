#include<stdio.h>
#include<stdlib.h>

struct Node {
  int data;
  struct Node *next;
};

typedef struct Node NODE;

//Insertion function to insert a node at specified position
void insert(NODE **head, int ele, int pos) {
  int k = 1;
  NODE *p, *q, *newNode;
  newNode = (NODE *)malloc(sizeof(NODE));
  newNode->data = ele;
  p = *head;
  if(pos == 1) {
    newNode->next = p;
    *head = newNode;
  }
  else {
    while((p != NULL) && (k < pos)) {
      k++;
      q = p;
      p = p->next;
    }
    q->next = newNode;
    newNode->next = p;
  }
}

//Delete function to delete a node from specified position
int delete(NODE **head, int pos) {
  int ele, k = 1;
  NODE *p, *q;
  p = *head;
  if(pos == 1) {
    *head = p->next;
    ele = p->data;
    free(p);
  }
  else {
    while((p != NULL) && (k < pos)) {
      k++;
      q = p;
      p = p->next;
    }
    else {
      q->next = p->next;
      ele = p->data;
      free(p);
    }
  }
  return ele;
}

//Display the linked List
void display(NODE *head) {
  NODE *p;
  p = head;
  do {
    printf("%d\t",p->data);
    p = p->next;
  } while(p != NULL);}

//Finding the length of linked list
int length(NODE *head) {
  int len = 1;
  NODE *p;
  p = head;
  while(p->next != NULL) {
    p = p->next;
    len++;
  }
  return len;
}

//function to sort the linked list with T(O) = n^2
void sort(NODE **head) {
  NODE *p, *q;
  int k = 0, temp;
  p = q = *head;
  while(k < length(q)) {
    while(p != NULL) {
      p = p->next;
      if((q)->data > p->data) {
        temp = p->data;
        p->data = (q)->data;
        (q)->data = temp;
      }
    }
    p = *head;
    k++;
  }
}

//Delete node without passing head node
void deleteNodeWithoutHead(NODE **node) {
  NODE *p;
  p = *node;
  free(p);
  *node = (*node)->next;
}

//function to delete all occurance of a number
void deleteAlloccurance(NODE **head, int x) {
  NODE *p, *q, *r;
    p = q = *head;
    if(p->data == x) {
      p = p->next;
    }
    else {
      while(p != NULL) {
      if(p->data != x) {
          q = p;
          p = p->next;
          if(p->data == x) {
              r = p->next;
              free(p);
              p = r;
              q->next = p;
          }
      }
      else {
          r = p;
          p = p->next;
          q->next = p;
          free(r);
      }
    }
    }
}

//find the middle element
void middle(NODE *head, int len) {
  NODE *p;
  int k = 1;
  p = head;
  int mid = (len / 2) + 1;
  while(k < mid) {
    p = p->next;
    k++;
  }
  printf("Middle element is: %d\n",p->data);
}

//Search the specific element in linked list
void search(NODE *head, int ele) {
  int pos = 1;
  NODE *p;
  p = head;
  while(p != NULL) {
    if(ele == p->data) {
      printf("Element found at: %d\n",pos);
      return;
    }
    p = p->next;
    pos++;
  }}

//Display the linked list in reverse order using recursion
void displayRev(NODE *head) {
  NODE *p;
  p = head;
  if(p == NULL)
    return;
  displayRev(p->next);
  printf("%d\t",p->data);
}

//display odd numbered nodes from the List
void displayOddPosNodes(NODE *head) {
  NODE *p;
  int k = 1;
  p = head;
  while(p != NULL) {
    if(k % 2 == 1) {
      printf("%d\t",p->data);
    }
    k++;
    p = p->next;
  }
  printf("\n");
}

//Permanently Reverse a linked List
void reverse(NODE **head) {
  NODE *cur, *pre, *nxt;
  cur = *head;
  pre = NULL;
  while(cur != NULL) {
    nxt = cur->next;
    cur->next = pre;
    pre = cur;
    cur = nxt;
  }
  *head = pre;
  printf("Linked list reversed\n");
}
