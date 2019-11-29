#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node {
  char data;
  struct node *left;
  struct node *right;
};

typedef struct node BST;

BST *eval
