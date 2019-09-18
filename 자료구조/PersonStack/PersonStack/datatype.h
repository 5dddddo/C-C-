#pragma once
typedef struct _person
{
	char name[20];
	int age;
}Person;
typedef Person DataType;

void printPerson(DataType *p);