#include <stdlib.h>
#include <stdio.h>
#include "header.h";

int main(int argc, char** argv)
{
    char name[10][20];
    int id[10];
    int marks[10];

    for (int i = 0; i < 10; i++)
    {
        printf("\nWhat is the students name?\n");
        scanf_s("%s", name[i][20], 20 * sizeof(char));
        printf("\nWhat is the student id?\n");
        scanf_s("%d", id[i], sizeof(int));
        printf("\nWhat is the student mark?\n");
        scanf_s("%d", marks[i], sizeof(int));
    }

	exit(EXIT_SUCCESS);
}

//void addElement(student* head, char name[], int id, int mark) {
//    student* current = head;
//
//    while (current->next != NULL) {
//        current = current->next;
//    }
//
//    //adding a new element to the list array
//    current->next = (student*)malloc(sizeof(student));
//    current->next->name[20] = name;
//    current->next->id = id;
//    current->next->mark = mark;
//    current->next->next = NULL;
//}