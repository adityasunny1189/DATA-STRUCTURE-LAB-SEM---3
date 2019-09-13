#include<stdio.h>
int main()
{
    float avg = 0;
    struct student
    {
        char name[10];
        char usn[11];
        char address[30];
        int sem;
        int marks[6];
    };
    struct student s1[100];
    printf("enter the total no of student in class: ");
    int no;
    scanf("%d",&no);
    for(int k = 0; k < no; k++)
    {
        printf("enter the student details\n");
        printf("Name: ");
        scanf("%s",s1[k].name);
        printf("USN: ");
        scanf("%s",s1[k].usn);
        printf("Address: ");
        scanf("%s",s1[k].address);
        printf("Semester: ");
        scanf("%d",&s1[k].sem);
        printf("Enter marks of five subjects:\n");
        for (int i = 0; i < 5; i++)
        {
            scanf("%d",&s1[k].marks[i]);
        }
        printf("\n");
    }
    printf("Average marks of student subject wise: \n");
    for(int l = 0; l < no; l++)
    {
        for(int m = 0; m < 5; m++)
        {
            avg = avg + s1[l].marks[m];
        }
        printf("%f\t",avg/5);
        avg = 0;
    }
    return 0;
}
