#include <stdio.h>

struct date
    {
        unsigned int day:5;
        unsigned int month:4;
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

     if(D1.day == 28)
     {
        if(D1.month == 2)
        {
            if(D1.year % 4 == 0 || D1.year % 400 == 0 && D1.year % 100 != 0)
            {
                D1.day++;
            }
            else
            {
                D1.day = 1;
                D1.month++;
            }
        }
     }

    else if(D1.day == 30)
    {
        if(D1.month == 4 ||D1.month == 6 ||D1.month == 9 ||D1.month == 11)
        {
            D1.day = 1;
            D1.month++;
        }
        else
        {
            D1.day++;
        }
    }

    else if(D1.day == 31)
    {
        if(D1.month == 12)
        {
            D1.day = 1;
            D1.month = 1;
            D1.year++;
        }
        else
        {
            D1.day =1;
            D1.month++;
        }
    }

    else
    {
        D1.day++;
    }

    printf("Tommorow's Date is %d-%d-%d",D1.day,D1.month,D1.year);
    return 0;
}
