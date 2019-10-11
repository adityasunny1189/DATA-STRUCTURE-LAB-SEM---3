#include<stdio.h>
#include<stdlib.h>


//declaring the size of stack
#define size 5


//creating stack
struct stack
{
    int data[size];
    int top;
};


//checkimg stack full condition
int isFullStack(struct stack *st)
{
    if(st->top == size - 1)
        return 1;
    else
        return 0;
}


//checking stack empty condition
int isEmptyStack(struct stack *st)
{
    if(st->top == -1)
        return 1;
    else
        return 0;
}


//pushing a element on top of stack
int push(struct stack *st , int ele)
{
    if(isFullStack(st))
    {
        printf("!Stack Overflow\n");
        exit(1);
    }
    st->data[++st->top] = ele;
    return 1;
}


//poping out or removing element from top of stack
int pop(struct stack *st)
{
    if(isEmptyStack(st))
    {
        printf("!Stack Underflow\n");
        exit(1);
    }
    int ele = st->data[st->top--];
    return ele;
}


//displaying the stack content
void displayStack(struct stack st)
{
    printf("Top -->\t");
    for(int i = 0 ; i <= st.top ; i++)
        printf("%d\t",st.data[i]);
    printf("<--Bottom\n");
}


//returning the top element
int topOfStack(struct stack st)
{
    return st.data[st.top];
}


//returning the bottom element
int bottomOfStack(struct stack st)
{
    return st.data[0];
}


//returning the middle element
int middleOfStack(struct stack st)
{
    return st.data[st.top/2];
}

//Deallocating or deleting the stack
int deleteStack(struct stack *st)
{
    free((*st).data);
    free(st);
    return 1;
}

//Sum of all elements of stack
int sumOfstackElements(struct stack st)
{
    int sum = 0 ;
    for(int i = 0 ; i <= st.top ; i++)
        sum = sum + st.data[i];
    return sum;
}

//Reverse stack
int reverseStack(struct stack *st)
{
    int temp1 , pos = st->top;
    for(int i = 0 ; i <= pos / 2 ; i++)
    {
        temp1 = st->data[i] ;
        st->data[i] = st->data[pos];
        st->data[pos] = temp1;
        pos--;
    }
    return 1;
}

//Palindrom Checker for stack
int checkPalindrom(struct stack st)
{
    int pal = 0 ;
    int check = st.top/2;
    for(int i = 0 ; i < st.top / 2 ; i++)
    {
        if(st.data[i] == st.data[st.top])
            pal++;
        else
            pal--;
        st.top--;
    }
    if(pal == check)
        return 1;
    else
        return 0;
}

//Finding the maximum element of the stack
int maxStackElement(struct stack st)
{
    int max = 0 , ele;
    for(int i = 0 ; i < st.top ; i++)
    {
        ele = st.data[i];
        if(max > ele)
            max = max;
        else
            max = ele;
    }
    return max;
}

//Finding the minimum element in the stack
int minStackElement(struct stack st)
{
    int min , ele ;
    for(int i = 0 ; i < st.top ; i++)
    {
        ele = st.data[i];
        if(min > ele)
            min = ele;
        else
            min = min;
    }
    return min;
}

//Deleting the bottom Element
// int deleteBottomElement(struct stack *st)
// {

// }

// //Delete the middle Element
// int deleteMiddleElement(struct stack *st)
// {

// }

//Dynamically incresing the size of stack
// int increaseSize(struct stack *st , int no)
// {
//     size = (int *)calloc(no, sizeof(struct stack));
// }

int main()
{
    struct stack st;
    st.top = -1;
    int choice ;
    char do_you_want_to_continue;
    printf("STACK IMPLEMENTATION\n");
    do
    {
        printf("Available commands:-\n1.push Element\n2.Pop Element\n3.Display Stack\n4.Top Element\n5.Bottom Element\n6.Middle Element\n7.Sum of stack Element\n8.Reverse Stack\n9.Palindrom Checker\n10.Max Element\n11.Min Element\n12.Deleting the stack\n13.Deleting the first element\n14.Deleting the middle element\n15.exit program\nEnter Your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("Enter no to push : ");
                    int ele;
                    scanf("%d",&ele);
                    if(push(&st,ele) == 1)
                        printf("Element Sucessfully pushed\n");
                    else
                        printf("Element Not pushed sucessfully\n");
                    break;

            case 2: printf("Poped up element is : %d\n",pop(&st));
                    break;

            case 3: printf("Stack Elemrnts are:-\n");
                    displayStack(st);
                    break;

            case 4: printf("Top of stack Element is : %d\n",topOfStack(st));
                    break;

            case 5: printf("Bottom Element of stack is : %d\n",bottomOfStack(st));
                    break;

            case 6: printf("Middle Element is : %d\n",middleOfStack(st));
                    break;

            case 7: printf("Sum of Stack Elements is : %d\n",sumOfstackElements(st));
                    break;

            case 8: if(reverseStack(&st) == 1)
                        printf("Stack Reversed\n");
                    displayStack(st);
                    break;

            case 9: if(checkPalindrom(st) == 1)
                        printf("Stack is Palindrom\n");
                    else
                        printf("Not Palindrom\n");
                    break;

            case 10:printf("Max Element in the stack is : %d\n",maxStackElement(st));
                    break;

            case 11:printf("Min Stack Element is : %d\n",minStackElement(st));
                    break;

            case 12:if(deleteStack(&st) == 1)
                        printf("Stack Sucessfully deleted\n");
                    else
                        printf("Stack not deleted\n");
                    break;

            // case 13:

            // case 14:

            case 15:printf("Thank You :)\n");
                    exit(0);

            default:printf("Invalid Choice\n");
        }
        printf("\nDo you Want to Continue(y/n): ");
        scanf(" %c",&do_you_want_to_continue);
    } while (do_you_want_to_continue == 'y');
    printf("\n");
    return 0;
}