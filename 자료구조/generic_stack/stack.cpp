#include "stack.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "person.h"
void initStack(Stack *sPtr, size_t sSize, size_t dataSize)
{
	sPtr->sSize = sSize;
	sPtr->stack = (int *)calloc(sSize, dataSize);
	//방 크기 잘못잡음!! sizeof(dataSize) 하면 안됨
	sPtr->top = -1;
}

void clearStack(Stack *sPtr, size_t dataSize, void(*memFree)(void *))
{
	int i;
	for (i = 0; i < sPtr->sSize; i++)
		((char *)sPtr->stack)[i] = 0;
	sPtr->top = -1;
}
int push(Stack *sPtr, void *pushData, size_t dataSize, void(*memCpy)(void *, void *))
{
	int res;
	if ((res = isStackFull(sPtr)) != 1)
	{
		sPtr->top++;
		memCpy(((char *)sPtr->stack) + dataSize*sPtr->top, pushData);
	}
	else
		printf("push 실패\n");
	return 0;
}

int pop(Stack *sPtr, void *popData, size_t dataSize, void(*memCpy)(void *, void *), void(*memFree)(void *))
{
	int temp;
	if ((temp = isStackEmpty(sPtr)) != 1)
	{
		memCpy(popData, ((char *)sPtr->stack) + dataSize*sPtr->top);
		memFree(((char *)sPtr->stack) + dataSize*sPtr->top);
		sPtr->top--;
		return 1;
	}
	else
		printf("pop 실패\n");
	return 0;
}

void printStack(const Stack *sPtr, size_t dataSize, void(*memPrint)(void *))
{
	int i;
	for (i = sPtr->top; i >= 0; i--)
		memPrint(((char *)sPtr->stack) + dataSize*i);

	return;
}

void destroyStack(Stack *sPtr, size_t dataSize, void(*memFree)(void *))
{
	// 이름 동적할당 메모리 해제하기
	for (int i = 0; i < sPtr->top; i++)
	{
		memFree(((char *)sPtr->stack) + dataSize*i);
		sPtr->top--;
	}
	free(sPtr->stack);
	sPtr->stack = NULL;
	sPtr->sSize = 0;
	sPtr->top = -1;
	return;
}
int isStackFull(Stack *sPtr)
{
	if (sPtr->top == sPtr->sSize - 1) return 1;
	else return 0;
}
int isStackEmpty(Stack *sPtr)
{
	if (sPtr->top == -1) return 1;
	else return 0;
}
