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

void inorder(BST root) {
  if(root != NULL) {
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
  }
}

void preorder(BST root) {
  if(root != NULL) {
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(BST root) {
  if(root != NULL) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
  }
}

BST *delete(BST *root, int data) {

}
