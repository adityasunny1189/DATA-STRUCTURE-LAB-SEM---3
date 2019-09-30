#include<stdio.h>
#include<stdlib.h>

void TowerOfHanoi(char from_rod, char to_rod, char aux_rod, int no)
{
    if(no == 1)
        printf("\nPlace plate 1 from %c to %c\n",from_rod,to_rod);
    else
    {
        TowerOfHanoi(from_rod,aux_rod,to_rod,no-1);
        printf("\nPlace plate %d from %c to %c\n",no,from_rod,to_rod);
        TowerOfHanoi(aux_rod,to_rod,from_rod,no-1);
    }
}

int main()
{
    int noOfPlates;
    printf("Enter no of Plates: ");
    scanf("%d",&noOfPlates);
    TowerOfHanoi('A', 'B', 'C', noOfPlates);
    return 0;
}