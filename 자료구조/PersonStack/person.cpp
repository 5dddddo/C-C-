#include "datatype.h"
#include <stdio.h>
void printPerson(DataType *p)
{
	printf("%s : %d\n", p->name, p->age);
	return;
}
