#include <stdio.h>

int main()
{
    struct date
    {
        int day:5;
        int month:4;
        int year;
    }D1,D2;
    int n;
    printf("enter Today's date\n");
    printf("Day: ");
    scanf("%d",&n);
    D1.day = n;
    printf("Month: ");
    scanf("%d",&n);
    D1.month = n;
    printf("Month: ");
    scanf("%d",&D1.year);
    printf("Today's Date is %d-%d-%d",D1.day,D1.month,D1.year);
    return 0;
}
