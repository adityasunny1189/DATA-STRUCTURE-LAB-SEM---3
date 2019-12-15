#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main() {
    FILE *fp;
    fp = fopen("test_file", "w");
    if(fp == NULL) {
        printf("Error in opening file\n");
        exit(1);
    }
    fprintf(fp, "ABCD");
    fseek(fp,10,SEEK_CUR);
    fprintf(fp, "EFGH");
    fclose(fp);
    return 0;
}
