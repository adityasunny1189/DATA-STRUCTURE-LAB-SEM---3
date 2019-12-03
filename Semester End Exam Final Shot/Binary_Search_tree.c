#include<stdio.h>
#include<stdlib.h>

struct BinarySearchTreeNode {
  int data;
  struct BinarySearchTreeNode *left;
  struct BinarySearchTreeNode *right;
};

typedef struct BinarySearchTreeNode BST;

BST *insert(BST *root, int ele) {
  if(root == NULL) {
    root = (BST *)malloc(sizeof(BST));
    root->data = ele;
    root->left = root->right = NULL;
  }
  else {
    if(ele > root->data)
      root->right = insert(root->right, ele);
    else if(ele < root->data)
      root->left = insert(root->left, ele);
    else {
      printf("Root already present\n");
    }
  }
  return root;
}

void inorder(BST *root) {
  if(root) {
    inorder(root->left);
    printf("%d ",root->data);
    inorder(root->right);
  }
}

void preorder(BST *root) {
  if(root) {
    printf("%d ",root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

void postorder(BST *root) {
  if(root) {
    postorder(root->left);
    postorder(root->right);
    printf("%d ",root->data);
  }
}

BST *findMax(BST *root) {
  if(root == NULL)
    return NULL;
  else if(root->right == NULL)
    return root;
  else
    return findMax(root->right);
}

BST *delete(BST *root,int ele) {
  BST *temp;
  if(root == NULL) {
    printf("Empty Tree\n");
    return NULL;
  }
  else if(ele > root->data)
    root->right = delete(root->right, ele);
  else if(ele < root->data)
    root->left = delete(root->left, ele);
  else {
    if(root->left && root->right) {
      temp = findMax(root->left);
      root->data = temp->data;
      root->left = delete(root->left,root->data);
    }
    else {
      temp = root;
      if(root->left == NULL)
        root = root->right;
      else if(root->right == NULL)
        root = root->left;
      free(temp);
    }
  }
  return root;
}

int main() {
    int choice,ele;
    char ch;
    BST *root = NULL;
    do {
      /* code */
      printf("1.Insert node\n2.Delete node\n3.inorder\n4.preorder\n5.postorder\nchoice: ");
      scanf("%d",&choice);
      switch(choice) {
        case 1: printf("Enter ele: ");
                scanf("%d",&ele);
                root = insert(root,ele);
                break;

        case 2: printf("Enter ele: ");
                scanf("%d",&ele);
                root = delete(root,ele);
                break;

        case 3: inorder(root);break;
        case 4: preorder(root);break;
        case 5: postorder(root);break;
      }
      printf("(y/n): ");
      scanf(" %c",&ch);
    } while(ch == 'y');
  }
}
