#include "word.h"
#include <string.h>
#include <stdio.h>

void wordMemCpy(void *p1, void *p2)
{
	if (((Word *)p2)->wp != NULL)
	{
		if (((Word *)p1)->wp != NULL)
			free(((Word *)p1)->wp);
		((Word *)p1)->wp = (char *)malloc(strlen(((Word *)p2)->wp) + 1);
		strcpy(((Word *)p1)->wp, ((Word *)p2)->wp);
	}
	else
	{
		if (((Word *)p1)->wp != NULL)
		{
			free(((Word *)p1)->wp);
			((Word *)p1)->wp = NULL;
		}
	}
	/* wordClear(p1);
	if (((Word *)p2)->wp!= NULL)
	{
	((Word *)p1)->wp = (char *)malloc(strlen(((Word *)p2)->wp) + 1);
	strcpy(((Word *)p1)->wp, ((Word *)p2)->wp);
	*/
	((Word *)p1)->length = ((Word *)p2)->length;
}
void wordClear(void *p)
{
	if (((Word *)p)->wp != NULL)
	{
		memset(((Word *)p)->wp, 0, strlen(((Word *)p)->wp));
		free(((Word *)p)->wp);
		((Word *)p)->wp = NULL; //dangling 방지!
	}
	((Word *)p)->length = 0;
	return;
}
void wordPrint(int count, int *sum, void *p)
{
	printf("%3d 번째 단어 : %10s	단어길이 : %d\n", count, ((Word *)p)->wp, ((Word *)p)->length);
	*sum += ((Word *)p)->length;

}
int wordCompare(void *p1, void *p2)
{
	return strcmp(((Word *)p1)->wp, (char *)p2);
}
