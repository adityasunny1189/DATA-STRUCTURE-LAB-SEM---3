// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
//
// struct student {
//   char name[20];
//   int sem;
//   char branch[5];
//   int usn;
// }stu;
//
// void search(int sid) {
//   FILE *fp;
//   fp = fopen("student.txt","r");
//   while(fscanf(fp,"%s %d %s %d",stu.name,&stu.sem,stu.branch,&stu.usn) != EOF) {
//     if(stu.usn == sid) {
//       printf("%s %d %s %d",stu.name,stu.sem,stu.branch,stu.usn);
//       break;
//     }
//   }
//   fclose(fp);
// }
//
// int main() {
//   FILE *fp;
//   fp = fopen("student.txt","w");
//   char another_data = 'y';
//   while(another_data == 'y') {
//     printf("Enter student name semester branch usn: ");
//     scanf("%s %d %s %d",stu.name,&stu.sem,stu.branch,&stu.usn);
//     // fwrite(&stu,sizeof(stu),1,fp);
//     fprintf(fp,"%s %d %s %d\n",stu.name,stu.sem,stu.branch,stu.usn);
//     printf("Do you want to add another data: ");
//     scanf(" %c",&another_data);
//   }
//   fclose(fp);
//   printf("Enter usn to search: ");
//   int sid;
//   scanf("%d",&sid);
//   search(sid);
//   return 0;
// }

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
  char name[20];
  char branch[5];
  int sem;
  int usn;
}stu;

void search_student_data(int sid) {
  FILE *fp;
  int found = 0;
  fp = fopen("STUDENT_DATA.txt","r");
  while(fscanf(fp,"%s %s %d %d",stu.name,stu.branch,&stu.sem,&stu.usn) != EOF) {
    if(stu.usn == sid) {
      found++;
      printf("%s %s %d %d",stu.name,stu.branch,stu.sem,stu.usn);
      break;
    }
  }
  if(found == 0) {
    printf("Data not found\n");
  }
  fclose(fp);
}

void write_student_data() {
  FILE *fp;
  fp = fopen("STUDENT_DATA.txt","w");
  char another_data;
  do {
    printf("Enter name branch sem usn: ");
    scanf("%s %s %d %d",stu.name,stu.branch,&stu.sem,&stu.usn);
    fprintf(fp,"%s %s %d %d\n",stu.name,stu.branch,stu.sem,stu.usn);
    printf("Do you want to add another data: ");
    scanf(" %c",&another_data);
  }while(another_data == 'y');
  fclose(fp);
}

void display_student_data() {
  FILE *fp;
  fp = fopen("STUDENT_DATA.txt","r");
  while(fscanf(fp,"%s %s %d %d",stu.name,stu.branch,&stu.sem,&stu.usn) != EOF) {
    printf("%s %s %d %d\n",stu.name,stu.branch,stu.sem,stu.usn);
  }
  fclose(fp);
}

int main() {
  int choice;
  int sid;
  char ch;
  do {
    /* code */
    printf("1.Insert student data\n2.Display student data\n3.Search student data\nChoice: ");
    scanf("%d",&choice);
    switch(choice) {
      case 1: write_student_data();break;
      case 2: display_student_data();break;
      case 3: printf("Enter USN to search: ");
              scanf("%d",&sid);
              search_student_data(sid);break;
      default: printf("Invalid Option!!!\n");
    }
    printf("Do you want to continue: ");
    scanf(" %c",&ch);
  } while(ch == 'y');
  return 0;
}
