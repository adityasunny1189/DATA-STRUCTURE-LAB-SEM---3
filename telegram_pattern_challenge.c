#include<stdio.h>
#include<stdlib.h>
int main()
{
    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j <= 2 ; j++)
        {
            if(i == j)
            {
                printf("~");
                break;
            }
            else if(i % 2 == 0)
            {
                printf("*");
            }
            else
            {
                printf("+");
            }
        }
        printf(")\n");
    }
    for(int i = 0 ; i < 2 ; i++)
    {
        for(int j = 2 ; j > i ; j--)
        {
            if(i == 0)
                printf("+");
            else
                printf("*");
        }
        printf(")\n");
    }
}