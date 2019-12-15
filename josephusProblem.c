#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct prisoners {
    char name[10];
    int prisonerID;
    struct prisoners *next;
};

int groupSize = 0;

typedef struct prisoners P;

void AddPrisoner(P **head, char name[], int pid) {
    P *temp = (P *)malloc(sizeof(P)), *p = *head;
    strcpy(temp->name, name);
    temp->prisonerID = pid;
    if(*head == NULL) {
        *head = temp;
        return;
    }
    else {
        while(p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

int Winner(int size, int skipPosition) {
    if(size == 1)
        return 1;
    else 
        return ((Winner(size - 1, skipPosition) + skipPosition) % size);
}

void displayPrisoners(P *head) {
    while(head != NULL) {
        printf("%s\t%d\n",head->name,head->prisonerID);
        head = head->next;
    }
}

void displayWinner(P *head, int skipcount) {
    int k = 0;
    printf("The Prisoner who wins is at position: %d\n",Winner(groupSize, skipcount));
    while(k < Winner(groupSize, skipcount)) {
        head = head->next;
        k++;
    }
    printf("%s\t%d\n",head->name, head->prisonerID);
}

int main() {
    P *head = NULL;
    char name[10], ch;
    int pid, choice, skip;
    do {
        printf("1.Add Prisoner\n2.See Who Wins\n3.Display Prisoners\nChoice: ");
        scanf("%d",&choice);
        switch(choice) {
            case 1: printf("Enter prisoners name with id: ");
                    scanf("%s %d",name, &pid);
                    AddPrisoner(&head, name, pid);
                    groupSize++;
                    break;

            case 2: printf("Enter skip place count: ");
                    scanf("%d",&skip);
                    displayWinner(head, skip);
                    break;

            case 3: displayPrisoners(head);break;

            default: printf("Invalid choice\n");
        }
    printf("Do you want to continue: ");
    scanf(" %c",&ch);
    }while(ch == 'y');
}










