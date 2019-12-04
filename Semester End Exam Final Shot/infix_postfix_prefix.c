#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


struct stack {
  char data[10];
  int top;
};

int prec(char ch) {
  switch(ch) {
    case '#':
    case '(':return 0;break;
    case '+':
    case '-':return 1;break;
    case '*':
    case '/':return 2;break;
    case '^':return 3;break;
  }
}

int main() {
  char ch;
  int i = 0, j = 0;
  struct stack S;
  S.top = -1;
  S.data[++S.top] = '#';
  char infix[15], postfix[15];
  printf("Enter the valid infix statement: ");
  scanf("%s",infix);
  while(infix[i] != '\0')
  {
    ch = infix[i];
    if(isalpha(ch) || isdigit(ch))
      postfix[j++] = ch;

    else if(ch == '(')
      S.data[++S.top] = ch;

    else if(ch == ')')
    {
      while((ch = S.data[S.top--]) !=  '(')
        postfix[j++] = ch;
    }

    else
    {
      if(prec(ch) > prec(S.data[S.top]))
        S.data[++S.top] = ch;
      // else if(prec(ch) < prec(S.data[S.top])) {
      else {
        postfix[j++] = S.data[S.top--];
        S.data[++S.top] = ch;
      }
    }
    i++;
  }
  printf("%d",S.top);
  while(S.data[S.top] != '#') {
    postfix[j++] = S.data[S.top--];
  }
  postfix[j] = '\0';
  printf("%s\n",postfix);
  return 0;
}

// #include<stdio.h>
// #include<stdlib.h>
// #include<ctype.h>
//
// struct stack
// {
//     char arr[30];
//     int top;
// };
//
// int prec(char ch)
// {
//     switch(ch)
//     {
//         case '#':
//         case '(':return 0;break;
//         case '+':
//         case '-':return 1;break;
//         case '*':
//         case '/':return 2;break;
//         case '^':return 3;break;
//     }
// }
//
// int main()
// {
//     int i = 0,j = 0;
//     char ch;
//     struct stack S1;
//     S1.top = -1;
//     char infix[30],postfix[30];
//     printf("Enter valid infix expression: ");
//     scanf("%s",infix);
//     S1.arr[++S1.top] = '#';
//     while(infix[i] != '\0')
//     {
//         ch = infix[i];
//         if(isdigit(ch) || isalpha(ch))
//         {
//             postfix[j] = ch;
//             j++;
//         }
//         else if(ch == '(')
//         {
//             S1.arr[++S1.top] = ch;
//         }
//         else if(ch == ')')
//         {
//             while((ch = S1.arr[S1.top--]) != '(')
//             {
//                 postfix[j++] = S1.arr[S1.top];
//             }
//         }
//         else
//         {
//             if(prec(ch) < prec(S1.arr[S1.top]))
//             {
//                 postfix[j++] = S1.arr[S1.top--];
//             }
//             else if(prec(ch) == prec(S1.arr[S1.top]))
//             {
//                 postfix[j++] = S1.arr[S1.top--];
//                 S1.arr[++S1.top] = ch;
//             }
//             else
//                 S1.arr[++S1.top] = ch;
//         }
//         i++;
//     }
//     while((ch=S1.arr[S1.top]) != '#')
//     {
//         postfix[j++] = S1.arr[S1.top];
//         S1.top--;
//     }
//     postfix[j] = '\0';
//     printf("%s",postfix);
// }
