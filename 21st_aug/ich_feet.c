#include<stdio.h>
int main()
{
    struct length
    {
         float inch;
         float feet;
    }L1;
    char choice;
    printf("What conversion you want(I\F)\n");
    scanf("%c",&choice);
    if (choice == 'I')
    {
        printf("Enter length in inches\n");
        scanf("%f",&L1.inch);
        L1.feet = L1.inch/12;
        printf("Length in feet is %.2f",L1.feet);
    }
    else if(choice == 'F')
    {
        printf("Enter length in feet\n");
        scanf("%f",&L1.feet);
        L1.inch = L1.feet * 12.0;
        printf("Length in inch is %.2f",L1.inch);
    }
    else
    {
        printf("Invalid Length Measure\n");
    }
}
