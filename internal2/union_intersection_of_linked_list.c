#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

void insert(NODE **head, int ele) {

}

int search(NODE *head, int ele) {
  NODE *temp = head;
  while(temp != NULL) {
    if(temp->data == ele)
      return 1;
    temp = temp->next;
  }
  return 0;
}

void unionList(NODE *l1, NODE *l2) {
  NODE *list1 = l1, *list2 = l2;
  while(list2 != NULL) {
    if(!search(list1, list2->data))
      insert(&list1, list2->data);
    list2 = list2->next;
  }
  display(list1);
}

void intersectedList(NODE *l1, NODE *l2) {
  NODE *temp = NULL;
  while(l2 != NULL) {
    if(search(l1, l2->data))
      insert(&temp, l2->data);
    l2 = l2->next;
  }
  display(temp);
}
