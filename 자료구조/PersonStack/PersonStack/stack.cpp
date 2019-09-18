#include "stack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void initStack(Stack *sPtr)
{
	sPtr->head = (Snode *)calloc(1, sizeof(Snode));
	assert(sPtr->head != NULL);
	sPtr->tail = (Snode *)calloc(1, sizeof(Snode));
	assert(sPtr->tail != NULL);
	sPtr->head->next = sPtr->tail;
	sPtr->tail->next = sPtr->tail;
	sPtr->cur = NULL;
	return;
}
int push(Stack *sPtr, DataType indata)
{
	Snode *np;
	np = (Snode *)calloc(1, sizeof(Snode));
	assert(np != NULL);
	np->data = indata;
	np->next = sPtr->head->next;
	sPtr->head->next = np;
	return 0;
}
int pop(Stack *sPtr, DataType *popData)
{
	int res;
	Snode *tp;
	sPtr->cur = sPtr->head->next;
	res = isStackEmpty(sPtr);
	if (res != TRUE)
	{
		tp = sPtr->head->next;
		sPtr->cur = sPtr->cur->next;
		sPtr->head->next = sPtr->cur;
		free(tp);
	}
	return 0;
}
void printStack(Stack *sPtr, void(*print)(DataType *))
{
	DataType data;
	sPtr->cur = sPtr->head->next;
	while (sPtr->cur != sPtr->tail)
	{
		printPerson(&sPtr->cur->data);
		sPtr->cur = sPtr->cur->next;
	}
	return;
}
void destroyStack(Stack *sPtr)
{
	Snode *tp;
	sPtr->cur = sPtr->head->next;
	while (sPtr->cur != sPtr->tail)
	{
		tp = sPtr->cur->next;
		free(sPtr->cur);
		sPtr->cur = tp;
	}
	free(sPtr->head);
	free(sPtr->tail);
	sPtr->head = NULL;
	sPtr->tail = NULL;
	sPtr->cur = NULL;
	return;
}
int getStackTop(Stack *sPtr, DataType *getData)
{
	*getData = sPtr->head->next->data;
	printf("\tStackÀÇ top : %d\n", *getData);
	return 0;
}
int isStackEmpty(Stack *sPtr)
{
	if (sPtr->head->next == sPtr->tail)
		return TRUE;
	return FALSE;
}