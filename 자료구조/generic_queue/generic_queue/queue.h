#pragma once
#pragma warning(disable : 4996)
enum{FALSE,TRUE};

typedef struct _queue
{
	void *queue;
	int qSize;
	int front, rear;
}Queue;

void initQueue(Queue *qPtr, int qSize, int dataSize);
int enqueue(Queue *qPtr, void *inData,int dataSize,void (*dataCpy)(void *,void *));
int dequeue(Queue *qPtr, void *getData,int dataSize, void (*dataCpy)(void *,void *),void (*memFree)(void *));
void printQueue(const Queue *qPtr, int dataSize, void(*dataPrint)(void *));
void destroyQueue(Queue *qPtr,int dataSize, void (*memFree)(void *));
int isQueueEmpty(const Queue *qPtr);
int isQueueFull(const Queue *qPtr);