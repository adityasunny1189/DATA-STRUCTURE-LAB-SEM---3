#include<stdio.h>
#include<stdlib.h>

struct Node
{
  int data;
  struct Node *next;
};

typedef struct Node NODE;

// struct stack *createStack()
// {
//   return NULL;
// }

void insert(NODE **top, int data)
{
  NODE *temp;
  temp = (NODE *)malloc(sizeof(NODE));
  if(!temp)
  {
    printf("Memory allocation error\n");
    return ;
  }
  temp->data = data;
  temp->next = *top;
  *top = temp;
}

int delete(NODE **top)
{
  int data;
  NODE *temp;
  temp = *top;
  if(temp == NULL)
  {
    printf("Empty List\n");
    return ;
  }
  *top = (*top)->next;
  data = temp->data;
  free(temp);
  return data;
}

void display(NODE *top)
{
  if(top == NULL)
  {
    printf("Empty List\n");
    return ;
  }
  while(top != NULL)
  {
    printf("%d-->",top->data);
    top = top->next;
  }
  printf("\n");
}

int main()
{
  char ch;
  int ele;
  NODE *top = NULL;
  do {
    int choice;
    printf("1.Insert\n2.Delete\n3.Display\nChoice : ");
    scanf("%d",&choice);
    switch(choice)
    {
      case 1: printf("Enter element to insert: ");
              scanf("%d",&ele);
              insert(&top,ele);
              break;

      case 2: printf("Deleted element is %d\n",delete(&top));
              break;

      case 3: printf("The stack is : \n");
              display(top);
              break;

      default: printf("Invalid choice\n");
    }
    printf("Do you want to continue: ");
    scanf(" %c",&ch);
  } while(ch == 'y');
  return 0;
}
