#pragma once
#pragma warning (disable : 4996)
#include "datatype.h"

typedef struct _node Node;
struct _node{
	Node *prev;
	DataType data;
	Node *next;
};

typedef struct _linkedList{
	Node *head;
	Node *cur;
	Node *tail;
	int length;
}LinkedList;

void create(LinkedList *lp);
Node *makeNode(DataType *dataPtr, Node *prev, Node *next);
Node *appendFromHead(LinkedList *lp, DataType *dataPtr);
Node *appendFromTail(LinkedList *lp, DataType *dataPtr);
void display(LinkedList *lp, void(*print)(DataType *));
void deleteNode(LinkedList *lp, Node *target);
Node *searchUnique(LinkedList *lp, DataType *dataPtr, int(*compare)(DataType *, DataType *));
Node ** searchDuplicate(LinkedList *lp, int *searchCnt, DataType *dataPtr, int(*compare)(DataType *, DataType *));
void sortList(LinkedList *lp, int(*compare)(DataType *, DataType *));
void destroy(LinkedList *lp);
int printOnePage(LinkedList *lp, int cnt);
