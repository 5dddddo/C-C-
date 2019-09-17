#pragma once
#pragma warning (disable : 4996)
#include "person.h"
typedef struct _node Node;
struct _node{
	Node *prev;
	Node *next;
};

typedef struct _linkedList{
	Node *head;
	Node *cur;
	Node *tail;
	int length;
}LinkedList;

void create(LinkedList *lp);
Node *makeNode(void *dataPtr, Node *prev, Node *next, size_t size, void(*myMemCpy)(void *, void *));
Node *appendFromHead(LinkedList *lp, void *item, size_t size, void(*myMemCpy)(void *, void *));
Node *appendFromTail(LinkedList *lp, void *item, size_t size, void(*myMemCpy)(void *, void *));
Node *deleteNode(LinkedList *lp, Node *index, void(*dataFree)(void *));
Node *linearSearchUnique(LinkedList *lp, void *target, int(*compare)(void *, void *));
Node **linearSearchDuplicate(LinkedList *lp, void *dataPtr, int *searchNodeCount, int(*compare)(void *, void *));
void sortList(LinkedList *list, size_t size, int(*compare)(void *, void *), void(*myMemCpy)(void *, void *), void(*dataFree)(void *));
void display(LinkedList *lp, void(*dataPrint)(void *));
void destroy(LinkedList *lp, void(*dataFree)(void *));

