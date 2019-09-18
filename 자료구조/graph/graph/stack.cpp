#include "stack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void initStack(Stack *sPtr, int sSize)
{
	sPtr->sSize = sSize;
	sPtr->stack = (int *)calloc(sSize, sizeof(int));
	sPtr->top = -1;
}

void clearStack(Stack *sPtr)
{
	int i;
	for (i = 0; i < sPtr->sSize; i++)
		sPtr->stack[i] = 0;
	sPtr->top = -1;
}
int push(Stack *sPtr, int inData)
{
	sPtr->top++;
	if (sPtr->top <= sPtr->sSize - 1)
		sPtr->stack[sPtr->top] = inData;
	else
	{
		printf("push ½ÇÆÐ\n");
		sPtr->top--;
	}
	return 0;
}
int pop(Stack *sPtr, int *popData)
{
	if (sPtr->top != -1)
	{
		*popData = sPtr->stack[sPtr->top];
		sPtr->top--;
	}
	return 0;
}

void printStack(const Stack *sPtr)
{
	int i;
	for (i = sPtr->top; i >= 0; i--)
		printf("%d ", sPtr->stack[i]);
	return;
}

void destroyStack(Stack *sPtr)
{
	free(sPtr->stack);
	sPtr->stack = NULL;
	sPtr->sSize = 0;
	sPtr->top = -1;
	return;
}
int isStackEmpty(const Stack *sPtr)
{
	if (sPtr->top == -1)
		return 1;
	else return 0;
}