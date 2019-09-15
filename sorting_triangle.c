#include<stdio.h>
#include<math.h>

struct triangle
{
    int a;
    int b;
    int c;
};

void Sort_tri(struct triangle *tri, int n)
{
    int key;
    float p,s;
    for(int i = 0 ; i < n ; i++)
    {
        p = (tri[i].a + tri[i].b + tri[i].c)/2;
        s = sqrt(p * (p - tri[i].a) * (p - tri[i].b) * (p - tri[i].c));
    }
    for(int j = 1 ; j < n ; j++)
    {
        
    }
}

int main()
{
    int n;
    struct triangle tri[n];
    for(int i = 0 ; i < n ; i++)
    {
        scanf("%d%d%d",&tri[i].a,&tri[i].b,tri[i].c);
    }    
    Sort_tri(tri,n);
    for(int i = 0 ; i < n ; i++)
    {
        printf("%d %d %d",tri[i].a,tri[i].b,tri[i].c);
    }
    return 0;
}