#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "linkedlist.h"
#include <conio.h>
#include <Windows.h>
void create(LinkedList *lp)
{
	lp->head = (Node *)calloc(1, sizeof(Node)); //Head Node ����
	lp->tail = (Node *)calloc(1, sizeof(Node)); //Tail Node ����
	lp->head->next = lp->tail; //Head�� next -> Tail�� prev
	lp->tail->prev = lp->head; //Tail�� prev -> Head�� next
	lp->head->prev = lp->head; //Head�� prev -> Head �ڽ�
	lp->tail->next = lp->tail; //Tail�� next -> Tail �ڽ�
	lp->cur = NULL;
	lp->length = 0;

	return;
}

Node *makeNode(DataType *dataPtr, Node *prev, Node *next)
{
	Node *np;
	np = (Node *)calloc(1, sizeof(Node));
	if (np == NULL) return np; //�Ҵ� ���н� 0 return
	np->prev = prev; // tail�� prev�� np�� prev�� ����
	np->next = next; // tail�� next�� np�� next�� ����
	np->prev->next = np; //���� node�� �� node�� ����Ű����
	np->next->prev = np; //tail�� prev�� �� node�� next�� ����Ű����
	np->data = *dataPtr; //np�� data�� ����ü ���� ����(�ʱ�ȭ)
	return np;
}

Node *appendFromTail(LinkedList *lp, DataType *dataPtr)
{
	lp->cur = makeNode(dataPtr, lp->tail->prev, lp->tail); // ( ,prev,next)
	//���� : �� ��� �ּ� return, ���� : NULL return
	if (lp->cur != NULL) lp->length++; //�Ҵ� ������ length 1 ����
	return lp->cur;
}

void display(LinkedList *lp, void(*print)(DataType *))
{
	system("cls");
	lp->cur = lp->head->next; //#1. cur�� ù ��� ����Ű�� �� 
	while (lp->cur != lp->tail)
	{
		print(&lp->cur->data);
		lp->cur = lp->cur->next; //#2. ���� ���� �̵���Ŵ
	}
	return;
}

Node * searchUnique(LinkedList *lp, DataType *dataPtr, int(*compare)(DataType *, DataType *))
{
	lp->cur = lp->head->next; //#1. cur�� ù ��� ����Ű�� ��
	while (lp->cur != lp->tail)
	{
		if (compare(&lp->cur->data, dataPtr) == 0)
			return lp->cur;
		lp->cur = lp->cur->next; //#2. ���� ���� �̵���Ŵ
	}
	return NULL;
}

void destroy(LinkedList *lp)
{
	Node *tp;
	lp->cur = lp->head->next;
	while (lp->cur != lp->tail)
	{
		tp = lp->cur->next;
		free(lp->cur);
		lp->cur = tp;
	}
	free(lp->head);
	free(lp->tail);
	return;
}

int printOnePage(LinkedList *lp, int cnt)
{
	Node *np;
	DataType temp;
	temp.lineNum = cnt * 24 + 1;
	np = searchUnique(lp, &temp, compareLineNumber);
	if (np == NULL){ return 1; }
	for (int i = 0; i < 24; i++)
	{
		printf("%s", np->data.str);
	
		np = np->next;
		if (np == lp->tail) { return 1; }

	}
	return 0;
}