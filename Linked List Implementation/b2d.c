#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct stack
{
    int data[20];
    int top;
}st;

int b2d(int n)
{
    if(n == 1 || n == 0)
        st.data[++st.top] = n;
    else
    {
        st.data[++st.top] = (n%10);
        b2d(n/10);
    }
}

int main()
{
    st.top = -1;
    int bin , sum = 0;
    printf("Enter a binary no: ");
    scanf("%d",&bin);
    b2d(bin);
    for(int i = 0 ; i <= st.top ; i++)
    {
        sum = sum + st.data[i]*pow(2,i);
    }
    printf("Decimal Form of %d is: %d",bin,sum);
    return 0;
}
