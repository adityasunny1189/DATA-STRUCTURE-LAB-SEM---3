#include<stdio.h>
#include<stdlib.h>

int main(int argc , char argv[])
{
    FILE *fp1, *fp2;
    char ch;
    fp1 = fopen(argv[1],"rb+");
    if(argc != 3)
    {
        printf("less no of args\n");
        exit(2);
    }
    if(fp1 == NULL)
    {
        printf("invalid source file name\n");
        exit(1);
    }
    fp2 = fopen(argv[2],"wb+");
    if(fp2 == NULL)
    {
        printf("invalid destination file\n");
        fclose(fp1);
        exit(2);
    }
    while(1)
    {
        ch = getc(fp1);
        if(ch == EOF)
            break;
        else
            putc(ch,fp2);
    }
}