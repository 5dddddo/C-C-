#include "datatype.h"
#include <string.h>
#include <stdio.h>

int compareLineNumber(DataType *p1, DataType *p2)
{
	if (p1->lineNum == p2->lineNum) return 0;
	else return -1;
}
void printPerson(DataType *p)
{
	printf("%d\n", p->lineNum);
}