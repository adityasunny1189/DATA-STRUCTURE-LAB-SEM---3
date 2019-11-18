#include<stdio.h>
#include<stdlib.h>

struct Dnode {
  int data;
  struct Dnode *next;
  struct Dnode *prev;
};

typedef struct Dnode NODE;

NODE *getNode() {
  NODE *newNode;
  newNode = (NODE *)malloc(sizeof(NODE));
  return newNode;
}

void insert(NODE **head, int ele, int pos) {
  NODE *newN, *temp;
  temp = *head;
  newN->data = ele;
  if(temp == NULL) {
    newN->next = NULL;
    newN->prev = NULL;
    *head = newN;
  }
  else if(pos == 1) {
    newN->next = temp;
    newN->prev = NULL;
    temp->prev = newN;
    *head = newN;
  }
}
