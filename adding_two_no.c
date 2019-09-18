#include<stdio.h>
int add_function(int a,int b) {
    return a+b;
}
int main()
{
    int a,b;
    printf("enter two no\n");
    scanf("%d%d",&a,&b);
    int result = add_function(a,b);
    printf("result is %d",result);
    return 0;
}
