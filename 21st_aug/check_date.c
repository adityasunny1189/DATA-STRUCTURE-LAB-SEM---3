#include<stdio.h>

struct date
    {
        unsigned int day;
        unsigned int month;
        unsigned int year;
    }D1;

int check_date(struct date D1)
{
    if (D1.day > 31)
    {
        return 1;
    }
    if (D1.month > 12)
    {
        return 1;
    }
    if (D1.day > 30)
    {
        if(D1.month == 4 || D1.month == 6 || D1.month == 9 || D1.month == 11)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
    if(D1.month == 2)
    {
        if(D1.year % 4 == 0 || D1.year % 400 == 0 && D1.year % 100 != 0)
        {
            if(D1.day > 29)
                return 1;
        }
        else
        {
            if(D1.day > 28)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int n;
    printf("enter Today's date\n");
    printf("Day: ");
    scanf("%d",&n);
    D1.day = n;
    printf("Month: ");
    scanf("%d",&n);
    D1.month = n;
    printf("Year: ");
    scanf("%d",&D1.year);
    printf("Today's Date is %d-%d-%d\n",D1.day,D1.month,D1.year);
    if(check_date(D1) == 1)
    {
        printf("INVALID DATE\n");
    }
    else
    {
        printf("VALID date\n");
    }
    return 0;
}
