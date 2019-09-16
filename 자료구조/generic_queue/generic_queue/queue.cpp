#include <malloc.h>
#include <assert.h>
#include "queue.h"
#include "person.h"
#include <Windows.h>
#include <conio.h>
void initQueue(Queue *qPtr, int qSize, int dataSize)
{
	qPtr->qSize = qSize;
	qPtr->front = 0;
	qPtr->rear = 0;
	qPtr->queue = (int *)calloc(qPtr->qSize, dataSize);
}
int enqueue(Queue *qPtr, void *inData, int dataSize, void(*dataCpy)(void *, void *))
{
	int res;
	if ((res = isQueueFull(qPtr)) != 1)
	{
		dataCpy((char *)(qPtr->queue) + dataSize*qPtr->rear,inData);
		qPtr->rear = ((qPtr->rear) + 1) % qPtr->qSize;
		return TRUE;
	}
	return FALSE;
}
int dequeue(Queue *qPtr, void *getData, int dataSize, void(*dataCpy)(void *, void *), void(*memFree)(void *))
{
	int res;
	if ((res = isQueueEmpty(qPtr)) != 1)
	{
		dataCpy(getData, (char *)(qPtr->queue) + dataSize*qPtr->front);
		memFree((char *)(qPtr->queue) + dataSize*qPtr->front);
		qPtr->front= ((qPtr->front) + 1) % qPtr->qSize;
		return TRUE;
	}
	else return FALSE;
}
void printQueue(const Queue *qPtr, int dataSize, void(*dataPrint)(void *))
{
	int i;
	for (i = qPtr->front; i != qPtr->rear; i = ((i + 1) % qPtr->qSize))
		dataPrint((char *)(qPtr->queue) + dataSize*i);

	return;
}
void destroyQueue(Queue *qPtr, int dataSize, void(*memFree)(void *))
{
	for (int i = 0; i < qPtr->rear; i++)
	{
		memFree(((char *)qPtr->queue) + dataSize*i);
		qPtr->rear--;
	}
	free(qPtr->queue);
	qPtr->queue = NULL;
	qPtr->qSize = 0;
	qPtr->front = 0;
	qPtr->rear = 0;
}
int isQueueEmpty(const Queue *qPtr)
{
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