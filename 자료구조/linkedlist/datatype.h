#pragma once
typedef struct _person
{
	char name[20];
	int age;
}Person;

typedef Person DataType;

int comparePersonName(DataType *p1, DataType *p2);
int comparePersonAge(DataType *p1, DataType *p2);
void printPerson(DataType *p);
