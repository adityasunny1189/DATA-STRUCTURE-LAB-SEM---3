#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
  char data[20];
  int top;
};

void push(struct stack *st, char ele) {
  st->data[++st->top] = ele;
}

char pop(struct stack *st) {
  return st->data[st->top--];
}

void check(struct stack st) {
  int j = st.top;
  for(int i = 0 ; i <= st.top / 2 ; i++) {
    if(st.data[i] == st.data[j]) {
      j--;
    }
    else {
      printf("Not Matched Parenthesis\n");
      return;
    }
  }
  printf("Matched Parenthesis\n");
}

void display(struct stack st) {
  for(int i = 0; i <= st.top; i++) {
    printf("%c",st.data[i]);
  }
  printf("\n");
}

int main() {
  struct stack st;
  st.top = -1;
  char data[20];
  printf("Enter string: ");
  scanf("%s",data);
  for(int i = 0 ; i < strlen(data) ; i++) {
    push(&st, data[i]);
  }
  printf("%d\n",st.top);
  printf("String Entered: ");
  display(st);
  check(st);
  return;
}
