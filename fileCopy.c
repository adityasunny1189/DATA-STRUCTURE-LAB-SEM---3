#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc , char *argv[]) {
    FILE *sourceFile, *destinationFile;
    char ch;
    if(argc != 3) {
        printf("Improper number of arguments\n");
        exit(1);
    }
    sourceFile = fopen(argv[1], "r");
    if(sourceFile == NULL) {
        printf("Source file unavailable\n");
        exit(1);
    }
    destinationFile = fopen(argv[2], "w");
    while(1) {
        ch = fgetc(sourceFile);
        if(ch == EOF) 
            break;
        else
            fputc(ch, destinationFile);
    }
    fclose(sourceFile);
    fclose(destinationFile);
    return 0;
}
