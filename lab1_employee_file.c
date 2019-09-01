#include<stdio.h>
#include<stdlib.h>

struct Employee
{
    char name[20];
    char id[20];
    char dept[10];
    int salary;
}E1;

void Write_data(FILE *fp);
void display_data(FILE *fp);
void search_data(FILE *fp,char str[]);

int main()
{
    FILE *fp;
    int choice;
    char eid[20];
    printf("Welcome to employee datasheet\n");
    printf("Choose your choice\n");
    printf("1.Display Data\n2.Write Data\n3.Search Data\n4.Exit\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:display_data(fp);
                break;
        case 2:Write_data(fp);
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

void Write_data(FILE *fp)
{
    fp = fopen("Employee.txt","a");
    if(fp == NULL)
    {
        printf("Error 404\n");
        return;
    }
    printf("Enter name id Department and Salary\n");
    scanf("%s%s%s%d",E1.name,E1.id,E1.dept,&E1.salary);
    // fwrite(&E1,sizeof(E1),1,fp);
    fprintf(fp,"%s\t%s\t%s\t%d\n",E1.name,E1.id,E1.dept,E1.salary);
    printf("\n");
    fclose(fp);
}

void display_data(FILE *fp)
{
    char ch;
    fp = fopen("Employee.txt","r");
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
    //file can also be read in this way
    // while(fread(&E1,sizeof(struct Employee),1,fp) == 1)
    // {
    //     printf("%s%s%s%d",E1.name,E1.id,E1.dept,E1.salary);
    // }
    printf("\n");
    fclose(fp);
}

void search_data(FILE *fp,char str[])
{
    fp = fopen("Employee.txt","r");
    if(fp == NULL)
    {
        printf("Error 404\n");
        return;
    }
}