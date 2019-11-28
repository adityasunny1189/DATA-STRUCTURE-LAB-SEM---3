#include<stdio.h>
#include<stdlib.h>

struct BinarySearchTree {
  int data;
  struct BinarySearchTree *leftChild;
  struct BinarySearchTree *rightChild;
};

typedef struct BinarySearchTree BST;

BST *getnode() {
  return (BST *)malloc(sizeof(BST));
}

int findChild(BST *root, int ele) {
  if(root->data == ele)
    return 1;
  else if(root->data > ele)
    return findChild(root->leftChild, ele);
  else if(root->data < ele)
    return findChild(root->rightChild, ele);
  else
    return 0;
}

int findMinimumElement(BST *root) {
  if(root == NULL)
    return 0;
  else if(root->leftChild == NULL)
    return root->data;
  else
    return findMinimumElement(root->leftChild);
}

int findMaximumElement(BST *root) {
  if(root == NULL)
    return 0;
  else if(root->rightChild == NULL)
    return root->data;
  else
    return findMaximumElement(root->rightChild);
}

void inorder(BST *root) {
  if(root != NULL) {
    inorder(root->leftChild);
    printf("%d ",root->data);
    inorder(root->rightChild);
  }
}

void preorder(BST *root) {
  if(root != NULL) {
    printf("%d ",root->data);
    preorder(root->leftChild);
    preorder(root->rightChild);
  }
}

void postorder(BST *root) {
  if(root) {
    postorder(root->leftChild);
    postorder(root->rightChild);
    printf("%d ",root->data);
  }
}

BST *insert(BST *root, int ele) {
  if(root == NULL) {
    BST *newNode;
    newNode = getnode();
    if(!newNode) {
      printf("Memory allocation error\n");
      return;
    }
    else {
      newNode->data = ele;
      newNode->leftChild = newNode->rightChild = NULL;
      root = newNode;
    }
  }
  else {
    if(ele < root->data)
      root->leftChild = insert(root->leftChild, ele);
    else if(ele > root->data)
      root->rightChild = insert(root->rightChild, ele);
    else
      printf("Node already present so cant duplicate\n");
  }
  return root;
}

BST *delete(BST *root, int ele) {
  BST *temp;
  if(root == NULL) {
    printf("Empty tree\n");
  }
  else if(root->data > ele)
    root->leftChild = delete(root->leftChild, ele);
  else if(root->data < ele)
    root->rightChild = delete(root->rightChild, ele);
  else {
    if(root->leftChild && root->rightChild) {
      temp = findMaximumElement(root->leftChild);
      root->data = temp->data;
      root->leftChild = delete(root->leftChild, root->data);
    }

  }
}

int leastCommonAncestor(BST *root, int n1, int n2) {
  while(1) {
    if((n1 < root->data && n2 > root->data) || (n1 > root->data && n2 < root->data))
      return root->data;
    else if(n1 < root->data)
      root = root->left;
    else
      root = root->right;
  }
}
