#include<stdio.h>
int main()
{
    struct student
    {
        char name[10];
        char usn[11];
        char address[30];
        int sem;
        int marks[6];
    } s1;
    printf("enter the student details\n");
    printf("Name: ");
    scanf("%s",s1.name);
    printf("USN: ");
    scanf("%s",s1.usn);
    printf("Address: ");
    scanf("%s",s1.address);
    printf("Semester: ");
    scanf("%d",&s1.sem);
    printf("Enter marks of five subjects:\n");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&s1.marks[i]);
    }
    printf("\n");
    printf(" _______________________________\n");
    printf("|Name: %s\t\t\t|\n",s1.name);
    printf("|USN : %s\t\t|\n",s1.usn);
    printf("|Address: %s\t\t|\n",s1.address);
    printf("|Semester: %d\t\t\t|\n",s1.sem);
    printf("|Marks: ");
    for(int j=0;j<5;j++)
        printf("%d  ",s1.marks[j]);
    printf("\t|\n");
    printf("|_______________________________|\n");
    return 0;
}
