#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
  char data[20];
  struct Node *next;
};

typedef struct Node NODE;

NODE *getNode() {
  NODE *newNode = (NODE *)malloc(sizeof(NODE));
  return newNode;
}

//strcpy(destination , source);

NODE *insert(NODE *head, char data[20]) {
  NODE *newNode;
  newNode = getNode();
  if(!newNode) {
    printf("Memory allocation error\n");
    return;
  }
  strcpy(newNode->data, data);
  newNode->next = head;
  head = newNode;
  return head;
}

NODE *delete(NODE *head) {
  NODE *temp;
  temp = head;
  head = temp->next;
  printf("Deleted element is: %s",temp->data);
  free(temp);
  return head;
}

void display(NODE *head) {
  while(head != NULL) {
    printf("%s--",head->data);
  }
  printf("\n");
}
