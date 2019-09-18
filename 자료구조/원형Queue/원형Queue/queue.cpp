#include <stdio.h>
#include <malloc.h>
#include <assert.h>
#include "queue.h"

void initQueue(Queue *qPtr, int size)
{
	qPtr->qSize = size;
	qPtr->front = 0;
	qPtr->rear = 0;
	qPtr->queue = (DataType *)calloc(qPtr->qSize, sizeof(DataType));
}
int enqueue(Queue *qPtr, DataType inData)
{
	int res;
	if ((res = isQueueFull(qPtr)) != 1)
	{
		qPtr->queue[qPtr->rear] = inData;
		qPtr->rear = ((qPtr->rear) + 1) % qPtr->qSize;
		return TRUE;
	}
	return FALSE;
}
int dequeue(Queue *qPtr, DataType *getData)
{
	int res;
	if ((res = isQueueEmpty(qPtr)) != 1)
	{
		*getData = qPtr->queue[qPtr->front];
		qPtr->front= ((qPtr->front) + 1) % qPtr->qSize;
		return TRUE;
	}
	else return FALSE;
}
void printQueue(const Queue *qPtr, void(*print)(DataType *))
{
	int i;
	for (i = qPtr->front; i != qPtr->rear; i = ((i + 1) % qPtr->qSize))
		printInt(&qPtr->queue[i]);
	return;
}
void destroyQueue(Queue *qPtr)
{
	free(qPtr->queue);
	qPtr->queue = NULL;
	qPtr->qSize = 0;
	qPtr->front = 0;
	qPtr->rear = 0;
}
int isQueueEmpty(const Queue *qPtr)
{
	/*
	if (((qPtr->rear) + 1) % qPtr->qSize != qPtr->front)
		return TRUE;
	else return FALSE;*/
	if (qPtr->front == qPtr->rear)
		return TRUE;
	else FALSE;
}
int isQueueFull(const Queue *qPtr)
{
	if (((qPtr->rear) + 1) % qPtr->qSize == qPtr->front)
		return TRUE;
	else return FALSE;
}