#include<stdio.h>
#include<stdlib.h>

//Forming a Node structure
struct Node {
  int data;
  struct Node *next;
};

typedef struct Node NODE;

//Insertion function to insert a node at specified position
void insert(NODE **head, int ele, int pos) {
  int k = 1;
  NODE *p, *q, *newNode;
  newNode = (NODE *)malloc(sizeof(NODE));
  if(!newNode) {
    printf("Memory allocation error\n");
    return NULL;
  }
  newNode->data = ele;
  p = *head;
  if(pos == 1) {
    newNode->next = p;
    *head = newNode;
  }
  else {
    while((p != NULL) && (k < pos)) {
      k++;
      q = p;
      p = p->next;
    }
    q->next = newNode;
    newNode->next = p;
  }
}

//Delete function to delete a node from specified position
int delete(NODE **head, int pos) {
  int ele, k = 1;
  NODE *p, *q;
  p = *head;
  if(p == NULL) {
    printf("Empty Linked list\n");
    return NULL;
  }
  if(pos == 1) {
    *head = p->next;
    ele = p->data;
    free(p);
  }
  else {
    while((p != NULL) && (k < pos)) {
      k++;
      q = p;
      p = p->next;
    }
    if(p == NULL) {
      printf("Position not found\n");
      return NULL;
    }
    else {
      q->next = p->next;
      ele = p->data;
      free(p);
    }
  }
  return ele;
}

//Display the linked List
void display(NODE *head) {
  NODE *p;
  p = head;
  if(p == NULL) {
    printf("Empty list\n");
    return NULL;
  }
  do {
    printf("%d\t",p->data);
    p = p->next;
  } while(p != NULL);
  printf("\n");
}

//Finding the length of linked list
int length(NODE *head) {
  int len = 1;
  NODE *p;
  p = head;
  if(p == NULL) {
    printf("Empty list\n");
    return 0;
  }
  while(p->next != NULL) {
    p = p->next;
    len++;
  }
  return len;
}

//function to sort the linked list with T(O) = n^2
void sort(NODE **head) {
  NODE *p, *q;
  int k = 0, temp;
  p = q = *head;
  while(k < length(q)) {
    while(p != NULL) {
      p = p->next;
      if((q)->data > p->data) {
        temp = p->data;
        p->data = (q)->data;
        (q)->data = temp;
      }
    }
    p = *head;
    k++;
  }
}

//Delete node without passing head node
void deleteNodeWithoutHead(NODE **node) {
  NODE *p;
  p = *node;
  free(p);
  *node = (*node)->next;
}

//function to delete all occurance of a number
void deleteAlloccurance(NODE **head, int x) {
  NODE *p, *q, *r;
    p = q = *head;
    if(p->data == x) {
      p = p->next;
    }
    else {
      while(p != NULL) {
      if(p->data != x) {
          q = p;
          p = p->next;
          if(p->data == x) {
              r = p->next;
              free(p);
              p = r;
              q->next = p;
          }
      }
      else {
          r = p;
          p = p->next;
          q->next = p;
          free(r);
      }
    }
    }
}

//find the middle element
void middle(NODE *head, int len) {
  NODE *p;
  int k = 1;
  p = head;
  if(p == NULL) {
    printf("Empty List\n");
    return;
  }
  int mid = (len / 2) + 1;
  while(k < mid) {
    p = p->next;
    k++;
  }
  printf("Middle element is: %d\n",p->data);
}

//Search the specific element in linked list
void search(NODE *head, int ele) {
  int pos = 1;
  NODE *p;
  p = head;
  if(p == NULL) {
    printf("Empty list\n");
    return NULL;
  }
  while(p != NULL) {
    if(ele == p->data) {
      printf("Element found at: %d\n",pos);
      return;
    }
    p = p->next;
    pos++;
  }
  printf("Element not found\n");
}

//Display the linked list in reverse order using recursion
void displayRev(NODE *head) {
  NODE *p;
  p = head;
  if(p == NULL)
    return;
  displayRev(p->next);
  printf("%d\t",p->data);
}

//display odd numbered nodes from the List
void displayOddPosNodes(NODE *head) {
  NODE *p;
  int k = 1;
  p = head;
  if(p == NULL) {
    printf("Empty list\n");
    return;
  }
  while(p != NULL) {
    if(k % 2 == 1) {
      printf("%d\t",p->data);
    }
    k++;
    p = p->next;
  }
  printf("\n");
}

//Permanently Reverse a linked List
void reverse(NODE **head) {
  NODE *cur, *pre, *nxt;
  cur = *head;
  pre = NULL;
  if(cur == NULL) {
    printf("Empty list\n");
    return;
  }
  while(cur != NULL) {
    nxt = cur->next;
    cur->next = pre;
    pre = cur;
    cur = nxt;
  }
  *head = pre;
  printf("Linked list reversed\n");
}
//main fucntion
int main() {
  NODE *head = NULL;
  int choice, ele, pos;
  char ch;
  do {
    printf("1.insert\n2.delete\n3.display\n4.exit\n5.length\n6.search\n7.middle element\n8.Display Reverse list\n9.display odd nodes\n10.reverse\n11.sort\n12.delete all keys\n13.Delete node without passing head\nChoice: ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: printf("Enter no to insert: ");
              scanf("%d",&ele);
              printf("Enter position to insert: ");
              scanf("%d",&pos);
              insert(&head,ele,pos);
              break;

      case 2: printf("Enter the position of Node to delete: ");
              scanf("%d",&pos);
              printf("Deleted element is: %d\n",delete(&head,pos));
              break;

      case 3: printf("The given list is: \n");
              display(head);
              printf("\n");
              break;

      case 4: exit(0);

      case 5: printf("Length of the linked list is: %d",length(head));
              break;

      case 6: printf("Enter the element to serch: ");
              scanf("%d",&ele);
              search(head,ele);
              break;

      case 7: middle(head,length(head));
              break;

      case 8: displayRev(head);
              break;

      case 9: displayOddPosNodes(head);
              break;

      case 10:reverse(&head);
              break;

      case 11:sort(&head);
              break;

      case 12:printf("Enter key: ");
              int key;
              scanf("%d",&key);
              deleteAlloccurance(&head,key);
              break;

      case 13:printf("Enter element to delete: ");
              scanf("%d",&ele);
              NODE *nodeToDelete;
              nodeToDelete = searchNodeOfThisElement(head,ele);
              deleteNodeWithoutHead(&nodeToDelete);
              break;

      default: printf("Invalid choice\n");
    }
    printf("\nDo you want to continue: ");
    scanf(" %c",&ch);
  } while(ch == 'y');
  return 0;
}
