#pragma once
#pragma warning (disable : 4996)

typedef struct _node Node;
struct _node{
	Node *prev;
	char data[100];
	Node *next;
};

typedef struct _linkedList{
	Node *head;
	Node *cur;
	Node *tail;
	int length;
}LinkedList;

void create(LinkedList *lp);
Node *makeNode(char *dataPtr, Node *prev, Node *next);
Node *appendFromTail(LinkedList *lp, char *dataPtr);
void display(LinkedList *lp, void(*print)(char *));
void printWord(char *p);
void destroy(LinkedList *lp);

