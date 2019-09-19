#include "person.h"
#include <string.h>
#include <stdio.h>

void personMemCpy(void *p1, void *p2)
{
	if (((Person *)p2)->name != NULL)
	{
		if (((Person *)p1)->name != NULL)
			free(((Person *)p1)->name);
		((Person *)p1)->name = (char *)malloc(strlen(((Person *)p2)->name) + 1);
		strcpy(((Person *)p1)->name, ((Person *)p2)->name);
	}
	else
	{
		if (((Person *)p1)->name != NULL)
		{
			free(((Person *)p1)->name);
			((Person *)p1)->name = NULL;
		}
	}

	/* personClear(p1);
	if (((Person *)p2)->name != NULL)
	{
	((Person *)p1)->name = (char *)malloc(strlen(((Person *)p2)->name) + 1);
	strcpy(((Person *)p1)->name, ((Person *)p2)->name);
	*/
	((Person *)p1)->age = ((Person *)p2)->age;
	strcpy(((Person *)p1)->phoneNumber, ((Person *)p2)->phoneNumber);
}
void personClear(void *p)
{
	if (((Person *)p)->name != NULL)	{
		memset(((Person *)p)->name, 0, strlen(((Person *)p)->name));
		free(((Person *)p)->name);
		((Person *)p)->name = NULL; //dangling 방지!
	}
	((Person *)p)->age = 0;
	memset(((Person *)p)->phoneNumber, 0, sizeof(((Person *)p)->phoneNumber));
	return;
}
void personPrint(void *p)
{
	printf("이름 : %s 나이 : %d세 번호 : %s\n",
		((Person *)p)->name, ((Person *)p)->age, ((Person *)p)->phoneNumber);
}
int personNameCompare(void *p1, void *p2)
{
	return strcmp(((Person *)p1)->name, ((Person *)p2)->name);
}
int personAgeCompare(void *p1, void *p2)
{
	if (((Person *)p1)->age > ((Person *)p2)->age)
	{
		return 1;
	}
	else if (((Person *)p1)->age == ((Person *)p2)->age)
		return 0;
	else
		return -1;
}
int personCompare(void *p1, void *p2)
{
	if (personNameCompare(p1, p2) == 0 && personAgeCompare == 0)
		return 0;
	else return -1;
}