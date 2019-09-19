#include "datatype.h"
#include <string.h>
#include <stdio.h>

int comparePersonName(DataType *p1, DataType *p2)
{
	int res;
	res = strcmp(p1->name, p2->name);
	if (res > 0) return 1;
	else if (res == 0) return 0;
	else return -1;
}
int comparePersonAge(DataType *p1, DataType *p2)
{
	if (p1->age > p2->age) return 1;
	else if (p1->age == p2->age) return 0;
	else return -1;
}
void printPerson(DataType *p)
{
	printf("%s",p->str);
}