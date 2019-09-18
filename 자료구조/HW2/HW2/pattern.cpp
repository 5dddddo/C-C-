#include "dataType.h"
#include <string.h>
#include <stdio.h>

void printPattern(DataType *p)
{
	printf("[%s] : %2d°³\n", p->pattern, p->cnt);
}
int comparePatternPattern(DataType *p1, DataType *p2)
{
	int res;
	res = strcmp(p1->pattern, p2->pattern);
	if (res > 0) return 1;
	else if (res == 0) return 0;
	else return -1;
}
int comparePatternCnt(DataType *p1, DataType *p2)
{
	if (p1->cnt > p2->cnt) return 1;
	else if (p1->cnt == p2->cnt) return 0;
	else return -1;

}
