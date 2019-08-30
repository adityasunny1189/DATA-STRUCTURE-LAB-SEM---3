#include<stdio.h>

struct Employee
{
    char name[20];
    char id[20];
    int salary;
    int age;
}E1;

void read_data(FILE *fp);
void display_data(FILE *fp);
void search_data(FILE *fp,char str[]);

int main()
{
    FILE *fp;
    printf("Welcome to employee datasheet\n");
    printf("Choose your choice\n");
    printf("1.Read Data\n2.Write Data\n3.Search Data\n4.Exit\n");
    int choice;
    char eid[20];
    switch(choice)
    {
        case 1:display_data(fp);
                break;
        case 2:read_data(fp);
                break;
        case 3:printf("Enter the employee id to search\n");
                scanf("%s",eid);
                search_data(fp,eid);
                break;
    }
}