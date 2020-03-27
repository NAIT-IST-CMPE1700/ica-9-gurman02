#pragma once
#ifndef HEADERH
#define HEADERH

//struct contians the name, id, marks and a pointer to the next item in the list array;
typedef struct data
{
	char name[20];
	int id;
	int mark;
	struct data* next;
} student;

//method for adding new elements to the list array
void addElement(student* head, char name[], int id, int mark);

#endif // !header.h