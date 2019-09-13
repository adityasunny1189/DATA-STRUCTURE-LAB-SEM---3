#include<stdio.h>
int main()
{
    struct st
    {
        int a;
        float b;
        char c;
    };
    struct st st1 = {2,1.2,'a'};
    printf("%d %f %c\n",st1.a,st1.b,st1.c);
    struct str2
    {
        int ch;
        struct st st1;
    }st2;
    printf("%c",st2.st1.c);
    return 0;
}
