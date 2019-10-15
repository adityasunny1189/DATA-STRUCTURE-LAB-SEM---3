#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct employee
{
  int id;
  char name[20];
  int salary;
  int age;
  char dept[5];
};

struct employee emp;

void read()
{
  printf("Enter details to ");
}

void write()
{
  FILE *fp;
  fp = fopen("emp.txt" , "w");
  if(fp == NULL)
  {
    printf("File not found\n");
    exit(1);
  }
  printf("Enter Details to write (id,name,salary,age,dept)\n");
  scanf("%d%s%d%d%s",&emp.id,emp.name,&emp.salary,&emp.age,emp.dept);
  fprintf("%d\t%s\t%d\t%d\t%s",emp.id,emp.name,emp.salary,emp.age,emp.dept);
  fclose(fp);
}

int main()
{
  int choice;
  printf("1.Read\n2.Write\n3.Display\n4.Search\nChoice: ");
  scanf("%d",&choice);
  switch(choice)
  {
    case 1: printf("Read Operation\n");
            read();
            break;

    case 2: printf("Write Operation\n");
            write();
            break;
  }
  return 0;
}
