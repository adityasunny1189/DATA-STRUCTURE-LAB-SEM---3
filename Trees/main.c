#include<stdio.h>
#include<stdlib.h>

struct treeNode {
    int data;
    struct treeNode *lchild, *rchild;
};

typedef struct treeNode TNODE;

void insert(TNODE **root, int ele) {
    TNODE *newNode,*parent, *temp;
    temp = *root;
    newNode = (TNODE *)malloc(sizeof(TNODE));
    newNode->data = ele;
    while(temp != NULL) {
        parent = temp;
        if(ele < temp->data)
            temp = temp->lchild;
        else if(ele > temp->data)
            temp = temp->rchild;
        else
        {
            printf("Node is already present\n");
            return;
        }
    }
    if(ele < parent->data)
        parent->lchild = newNode;
    else
        parent->rchild = newNode;
}

void deleteNode(TNODE **root, int ele) {
    TNODE *temp, *q, *parent, *succesor;
    if(*root == NULL)
    {
        printf("Empty tree\n");
        return;
    }
    temp = *root;
    parent = NULL;
    while(temp != NULL) {
        parent = temp;
        if(ele == temp->data)
            break;
        temp = (key < temp->data)?temp->lchild:temp->rchild;
    }
    if(temp == NULL){
        printf("Data not found\n");
        return;
    }
    else if(temp->lchild == NULL)
        q = temp->rchild;
    else if(temp->rchild == NULL)
        q = temp->lchild;
    else {

    }
    if(parent == NULL)
        return q;
    else if(parent->lchild == NULL)
        q = parent->lchild;
    else
        q = parent->rchild;
}

void display(TNODE *root) {
    TNODE *temp;
    temp = root;
}
