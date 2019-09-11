#include<stdio.h>
#include<stdlib.h>

struct EMPLOYEE
{
    char name[19];
    char id[20];
    int salary;
    int age;
}E1;

void displayData();
void readData();
void searchData(char eid[]);

int main()
{
    printf("Welcome to Employee dataFile\n");
    char eid[20];
    FILE *fp;
  /*  fp = fopen("ABC.txt","w");
    fputs("Name\tID\tSalary\tAge\n",fp);*/
    printf("Enter your choice\n");
    int choice;
    printf("1.DISPLAY DATA\n2.READ DATA\n3.SEARCH DATA\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1:printf("This choice is for displaying data\n");
                displayData();
                break;
        case 2:printf("This choice is for reading data from user\n");
                readData();
                break;
        case 3:printf("This data is for searching employee data\n");
                printf("Enter employee ID to search\n");
                scanf("%s",eid);
                searchData(eid);
                break;
        default:printf("INVALID CHOICE\n");
    }
   // fclose(fp);
}

void displayData()
{
    char ch;

    FILE *fp;
    fp = fopen("ABC.txt","r");
    if(fp == NULL)
    {
        printf("FILE NOT FOUND\n");
        exit(1);
    }
    while(fread(&E1,sizeof(struct EMPLOYEE),1,fp)== 1)
    {
        //ch = getc(fp);
        printf("\nName: %s, ID=%s, Salary= %d, age= %d",E1.name, E1.id,E1.salary,E1.age);
    }
    fclose(fp);
}

void readData()
{
    char choice = 'Y';
    FILE *fp;
    fp = fopen("ABC1.txt","ab+");
    if(fp == NULL)
    {
        printf("File not found\n");
        exit(1);
    }
    do{
        printf("enter the Employee details(name/id/salary/age)\n");
        scanf("%s%s%d%d",E1.name,E1.id,&E1.salary,&E1.age);
        fwrite(&E1,sizeof(struct EMPLOYEE),1,fp);
        printf("Do you want to continue\n");
        scanf(" %c",&choice);
    }while(choice == 'Y');
    printf("\n\n");
    fclose(fp);
}

void searchData(char eid[])
{

}
