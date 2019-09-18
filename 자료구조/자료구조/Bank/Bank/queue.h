#pragma once
#pragma warning(disable : 4996)
#include "datatype.h"
enum{ FALSE, TRUE };

typedef struct _queue
{
	DataType *queue;
	int qSize;
	int front, rear;
}Queue;

void initQueue(Queue *qPtr, int size);
int enqueue(Queue *qPtr, DataType inData);
int dequeue(Queue *qPtr, DataType *getData);
void printQueue(const Queue *qPtr, void(*print)(DataType *));
void destroyQueue(Queue *qPtr);
int isQueueEmpty(const Queue *qPtr);
int isQueueFull(const Queue *qPtr);
void printInt(DataType *);