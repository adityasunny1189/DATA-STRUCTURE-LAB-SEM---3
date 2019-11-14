#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
  struct node *prev;
};

typedef struct node NODE;

NODE *getnode() {
  NODE *newNode;
  newNode = (NODE *)malloc(sizeof(NODE));
  return newNode;
}

void 
