#include<stdio.h>
#include<string.h>

void flame(int z)
{
    switch(z)
    {
        case 1:printf("FRIENDS\n"); break;
        case 2:printf("LOVE\n"); break;
        case 3:printf("AFFECTION\n"); break;
        case 4:printf("MARRIDGE\n"); break;
        case 5:printf("ENEMY\n"); break;
        default:printf("No Relation\n");
    }
}

int main()
{
    printf("\t\t\t\tFLAME CALCULATOR\n\n");
    char name1[20], name2[20];
    printf("enter your name: ");
    gets(name1);
    printf("enter your crush name: ");
    gets(name2);

    int x = strlen(name1);
    int y = strlen(name2);
    int z = x + y; 

    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            if(name1[i] == name2[j])
            {
                name1[i] = name2[j] = ' ';
                z = z - 2;
            }
        }
    }

    if(z <= 5)
    {
        flame(z);
    }
    else if(z > 5)
    {
        int r = z % 5;
        flame(r);
    }
    return 0;
}