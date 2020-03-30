#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "header.h";

int main(int argc, char** argv)
{
    //declare variables
    char name[10][20];
    int id[10] = { 89,57,85,37,19,68,49,24,87,45 };
    int marks[10] = { 90,24,67,98,78,57,96,34,25,100 };
    int index;
    int itemp;
    int userInput = 0;
    char stemp[20];
    student* current;
    student idSort;
    student markSort;

    //initilize names
    strcpy_s(name[0], 20, "jhon");
    strcpy_s(name[1], 20, "bill");
    strcpy_s(name[2], 20, "bob");
    strcpy_s(name[3], 20, "jack");
    strcpy_s(name[4], 20, "ryan");
    strcpy_s(name[5], 20, "gavin");
    strcpy_s(name[6], 20, "geff");
    strcpy_s(name[7], 20, "ray");
    strcpy_s(name[8], 20, "george");
    strcpy_s(name[9], 20, "micheal");

    //print info before sorting
    printf("Before sorting\n");
    printf("Name | ID | Mark\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s %d %d\n", name[i], id[i], marks[i]);
    }

    //sort arrays according to ids
    for (int i = 0; i < 9; i++)
    {
        index = i;
        for (int currentID = i + 1; currentID < 10; currentID++)
        {
            if (id[index] > id[currentID])
            {
                index = currentID;
            }
        }

        itemp = id[index];
        id[index] = id[i];
        id[i] = itemp;

        itemp = marks[index];
        marks[index] = marks[i];
        marks[i] = itemp;

        strcpy_s(stemp, 20, name[index]);
        strcpy_s(name[index], 20, name[i]);
        strcpy_s(name[i], 20, stemp);
    }

    //create the linked list for id sort
    strcpy_s(idSort.name, 20, name[0]);
    idSort.id = id[0];
    idSort.mark = marks[0];
    idSort.next = NULL;

    for (int i = 1; i < 10; i++)
    {
        addElement(&idSort, name[i], id[i], marks[i]);
    }


    //sort arrays according to marks
    for (int i = 0; i < 9; i++)
    {
        index = i;
        for (int currentMark = i + 1; currentMark < 10; currentMark++)
        {
            if (marks[index] < marks[currentMark])
            {
                index = currentMark;
            }
        }

        itemp = id[index];
        id[index] = id[i];
        id[i] = itemp;

        itemp = marks[index];
        marks[index] = marks[i];
        marks[i] = itemp;

        strcpy_s(stemp, 20, name[index]);
        strcpy_s(name[index], 20, name[i]);
        strcpy_s(name[i], 20, stemp);
    }

    //create mark sort linked list
    strcpy_s(markSort.name, 20, name[0]);
    markSort.id = id[0];
    markSort.mark = marks[0];
    markSort.next = NULL;

    for (int i = 1; i < 10; i++)
    {
        addElement(&markSort, name[i], id[i], marks[i]);
    }

    //display menu to user
    while (userInput != 5)
    {
        printf("\nChose one of the fowlling options and input the number:\n");
        printf("1.Display list in order of Id's\n");
        printf("2.Display list in descending order of Marks\n");
        printf("3.Display the names, marks and rank of a person given the ID\n");
        printf("4.Display the names and marks of all person above a thresholdmarks value\n");
        printf("5.Exit\n");
        printf("Enter your input: ");
        scanf_s("%d", &userInput, sizeof(int));
        printf("\n");

        if (userInput == 1)
        {
            printf("Name | ID | Mark\n");

            current = &idSort;
            for (int i = 0; i < 10; i++)
            {
                printf("%s %d %d\n", current->name, current->id, current->mark);
                current = current->next;
            }
        }
        else if (userInput == 2)
        {
            printf("Name | ID | Mark\n");

            current = &markSort;
            for (int i = 0; i < 10; i++)
            {
                printf("%s %d %d\n", current->name, current->id, current->mark);
                current = current->next;
            }
        }
        else if (userInput == 3)
        {
            printf("Enter the id of the person you wish to display: ");
            scanf_s("%d", &userInput, sizeof(int));
            printf("\n");

            printf("Name | Mark | Rank\n");

            current = &idSort;
            for (int i = 0; i < 10; i++)
            {
                if (current->id == userInput)
                {
                    printf("%s %d %d\n", current->name, current->mark, i+1);
                }
                current = current->next;
            }
            userInput = 3;
        }
        else if (userInput == 4)
        {
            printf("Enter the threshold mark: ");
            scanf_s("%d", &userInput, sizeof(int));
            printf("\n");

            printf("Name | ID | Mark\n");

            current = &markSort;
            for (int i = 0; i < 10; i++)
            {
                if (current->mark >= userInput)
                {
                    printf("%s %d %d\n", current->name, current->id, current->mark);
                }
                current = current->next;
            }
            userInput = 4;
        }
    }

	exit(EXIT_SUCCESS);
}

void addElement(student* head, char name[], int id, int mark) {
    student* current = head;

    while (current->next != NULL) {
        current = current->next;
    }

    //adding a new element to the list array
    current->next = (student*)malloc(sizeof(student));
    //current->next->name[1] = name;
    strcpy_s(current->next->name, 20, name);
    current->next->id = id;
    current->next->mark = mark;
    current->next->next = NULL;
}