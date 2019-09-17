#pragma once
#pragma warning(disable : 4996)
#include <string.h>
#include <malloc.h>
#include <stdio.h>
typedef struct _person
{
	char *name;
	int age;
	char phoneNumber[16];
}Person;

void personMemCpy(void *p1, void *p2);
void personClear(void *p);
void personPrint(void *p);
int personNameCompare(void *p1, void *p2);
int personAgeCompare(void *p1, void *p2);
int personCompare(void *p1, void *p2);
