#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct student {
  char name[20];
  int sem;
  char branch[5];
  int usn;
}stu;

void search(int sid) {
  FILE *fp;
  fp = fopen("student.txt","r");
  while(fscanf(fp,"%s %d %s %d",stu.name,&stu.sem,stu.branch,&stu.usn) != EOF) {
    if(stu.usn == sid) {
      printf("%s %d %s %d",stu.name,stu.sem,stu.branch,stu.usn);
      break;
    }
  }
  fclose(fp);
}

int main() {
  FILE *fp;
  fp = fopen("student.txt","w");
  char another_data = 'y';
  while(another_data == 'y') {
    printf("Enter student name semester branch usn: ");
    scanf("%s %d %s %d",stu.name,&stu.sem,stu.branch,&stu.usn);
    // fwrite(&stu,sizeof(stu),1,fp);
    fprintf(fp,"%s %d %s %d\n",stu.name,stu.sem,stu.branch,stu.usn);
    printf("Do you want to add another data: ");
    scanf(" %c",&another_data);
  }
  fclose(fp);
  printf("Enter usn to search: ");
  int sid;
  scanf("%d",&sid);
  search(sid);
  return 0;
}
