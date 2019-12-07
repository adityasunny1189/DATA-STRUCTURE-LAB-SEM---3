#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 20

struct stack {
         char data[size];
         int top;
}S;

void push(char ch) {
         S.data[++S.top] = ch;
}

char pop() {
         return S.data[S.top--];
}

void display() {
         printf("%s",S);
}

int prec(char ch) {
         switch(ch) {
                  case '(':
                  case ')':return 1;

                  case '{':
                  case '}':return 2;

                  case '[':
                  case ']':return 3;
         }
}

int main() {
         S.top = -1;
         char bracket_expression[15];
         printf("Enter valid bracket sequence: ");
         scanf("%s",bracket_expression);
         for(int i = 0; i < strlen(bracket_expression); i++) {
                  if(bracket_expression[i] == '(' || bracket_expression[i] == '{' ||bracket_expression[i] == '[') {
                           push(bracket_expression[i]);
                  }
                  else {
                           if(prec(bracket_expression[i]) != prec(pop())) {
                                    printf("NO\n");
                                    return 0;
                           } 
                  }
         }
         if(S.top != -1) {
                  printf("NO\n");
                  return 0;
         }
         printf("YES\n");
         return 0;
}


















