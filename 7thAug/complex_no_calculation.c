#include<stdio.h>
void add(float a,float b,float c,float d)
{
    float re = a + b;
    float im = c + d;
    printf("Sum of %.2f + i%.2f and %.2f + i%.2f is %.2f + i%.2f",a,c,b,d,re,im);
}
void sub(float a,float b,float c,float d)
{
    float re = a - b;
    float im = c-d;
    if (c > d)
        printf("Sub of %.2f + i%.2f and %.2f + i%.2f is %.2f + i%.2f",a,c,b,d,re,im);
    else
        printf("Sub of %.2f + i%.2f and %.2f + i%.2f is %.2f - i%.2f",a,c,b,d,re,d-c);
}
void mul(float a,float b,float c,float d)
{
    float re = a*b - c*d;
    float im = a*c + b*d;
    printf("Mul of %.2f + i%.2f and %.2f + i%.2f is %.2f + i%.2f",a,c,b,d,re,im);
}
int main()
{
    struct complex
    {
        float real;
        float img;
    };
    struct complex com1,com2;
    printf("enter the first complex no\n");
        printf("real part: ");
        scanf("%f",&com1.real);
        printf("imaginary part: ");
        scanf("%f",&com1.img);
    printf("enter the second complex no\n");
        printf("real part: ");
        scanf("%f",&com2.real);
        printf("imaginary part: ");
        scanf("%f",&com2.img);
    printf("Enter your choice (+,-,*): ");
    char choice;
    scanf(" %c",&choice);
    switch(choice)
    {
        case '+':add(com1.real,com2.real,com1.img,com2.img);
                 break;
        case '-':sub(com1.real,com2.real,com1.img,com2.img);
                 break;
        case '*':mul(com1.real,com2.real,com1.img,com2.img);
                 break;
        default : printf("invalid operator\n");
    }
    return 0;
}
