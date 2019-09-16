#include "person.h"
#include <string.h>
#include <stdio.h>
void *find(void *begin, void *end, void *value, size_t size, int(*compareData)(void *, void *))
{
	while (begin != end)
	{
		if (compareData(begin,value) != 0)
		{
			begin = (char *)begin + size;
		}
		else return begin;
	}
	return begin;
}
int compareName(void *p1, void *p2)
{
	return strcmp(((Person *)p1)->name, ((Person *)p2)->name);
}

int compareAge(void *p1, void *p2)
{
	if (((Person *)p1)->age > *(int *)p2)
	{
		return 1;
	}
	else if (((Person *)p1)->age == *(int *)p2)
		return 0;
	else
		return -1;
}
