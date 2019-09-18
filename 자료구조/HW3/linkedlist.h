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
Node *appendFromTail(LinkedList *lp, DataType *dataPtr);
void display(LinkedList *lp, void(*print)(DataType *));
void destroy(LinkedList *lp);
void printPerson(DataType *p);