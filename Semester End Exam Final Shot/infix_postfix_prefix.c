#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
  char data[10];
  int top;
};

void push(struct stack *S, char ch) {
  S->data[++S->top] = ch;
}

char pop(struct stack *S) {
  return S->data[S->top--];
}

int main() {
  struct stack *S;
  S.top = -1;
  char infix[15], postfix[15], prefix[15];
  printf("Enter the valid infix statement: ");
  scanf("%s",infix);
  for(int i = 0; i < strlen(infix); i++) {
    if(isalpha(infix[i]))
      printf("%c",infix[i]);
    else if(infix[i] == ')') {
      while(infix[i] != "(") {
        printf("%c",pop(&S));
      }
    }
    else {
      push(&S,infix[i]);
    }
  }
  while(S.top != -1) {
    printf("%c",pop(&S));
  }
  return 0;
}
