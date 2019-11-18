#include<stdio.h>
#include<stdlib.h>

struct BinarySearchTree {
  int data;
  struct BinarySearchTree *left;
  struct BinarySearchTree *right;
};

typedef struct BinarySearchTree BST;

BST *insert(BST *root, int ele) {
  if(root == NULL) {
    root = (BST *)malloc(sizeof(BST));
    if(root == NULL) {
      printf("Memory allocation error\n");
      return;
    }
    else {
      root->data = ele;
      root->left = root->right = NULL;
    }
  }
  else {
    if(ele > root->data)
      root->right = insert(root->right, ele);
    else if(ele < root->data)
      root->left = insert(root->left, ele);
    else
      printf("Same Node present in the tree\n");
  }
  return root;
}

BST *delete(BST *root, int data) {
  
}
