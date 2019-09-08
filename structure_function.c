#include<stdio.h>

struct point
{
    int x;
    int y;
}P1;

struct point takePoint(int x, int y)
{
    P1.x = x;
    P1.y = y;
    return P1;
}

int main()
{
    printf("Enter coordinates\n");
    int x,y;
    scanf("%d%d",&x,&y);
    takePoint(x,y);
    printf("Coordinates are (%d,%d)\n",P1.x,P1.y);
    return 0;
}