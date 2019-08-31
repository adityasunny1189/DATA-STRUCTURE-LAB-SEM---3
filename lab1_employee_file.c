#include<stdio.h>
#include<stdlib.h>

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
    int choice;
    char eid[20];
    printf("Welcome to employee datasheet\n");
    printf("Choose your choice\n");
    printf("1.Display Data\n2.Read Data\n3.Search Data\n4.Exit\n");
    scanf("%d",&choice);
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
        case 4:printf("Thanks\n");
                break;
        default:printf("Invalid command\n");
    }
}

void read_data(FILE *fp)
{
    fp = fopen("Employee.dat","W");
    if(fp == NULL)
    {
        printf("Error 404\n");
        return;
    }
    fread(&E1,sizeof(struct Employee),1,fp);
}

void display_data(FILE *fp)
{
    char ch;
    fp = fopen("Employee.dat","r");
    if(fp == NULL)
    {
        printf("Error 404\n");
        return;
    }
    while(ch != EOF)
    {
        ch = getc(fp);
        printf("%c",ch);
    }
    printf("\n");
    fclose(fp);
}

void search_data(FILE *fp,char str[])
{
    fp = fopen("Employee.dat","r");
    if(fp == NULL)
    {
        printf("Error 404\n");
        return;
    }
}