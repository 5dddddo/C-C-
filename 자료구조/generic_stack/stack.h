#pragma once
typedef struct _stack
{
	void *stack;
	int sSize;
	int top;
}Stack;


void initStack(Stack *sPtr, size_t sSize, size_t dataSize);
void clearStack(Stack *sPtr, size_t dataSize, void(*memFree)(void *));
int push(Stack *sPtr, void *pushData, size_t dataSize, void(*memCpy)(void *, void *));
int pop(Stack *sPtr, void *popData, size_t dataSize, void(*memCpy)(void *, void *), void(*memFree)(void *));
void printStack(const Stack *sPtr, size_t dataSize, void(*memPrint)(void *));
void destroyStack(Stack *sPtr, size_t dataSize, void(*memFree)(void *));
int isStackFull(Stack *sPtr);
int isStackEmpty(Stack *sPtr);
