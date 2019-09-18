#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <malloc.h>
#include <conio.h>
#include <Windows.h>
#include "linkedlist2.h"
void create(LinkedList *lp)
{
	lp->head = (Node *)calloc(1, sizeof(Node));
	lp->tail = (Node *)calloc(1, sizeof(Node));
	lp->head->next = lp->tail;
	lp->head->prev = lp->head;
	lp->tail->next = lp->tail;
	lp->tail->prev = lp->head;
	lp->length = 0;
	lp->cur = NULL;
}
Node *makeNode(DataType *dataPtr, Node *prev, Node *next)
{
	Node *np;
	np = (Node *)calloc(1, sizeof(Node));
	if (np == NULL) return np;
	np->prev = prev;
	np->next = next;
	np->prev->next = np;
	np->next->prev = np;
	np->data = *dataPtr;
	return np;
}
Node *appendFromHead(LinkedList *lp, DataType *dataPtr)
{
	lp->cur = makeNode(dataPtr, lp->head, lp->head->next);
	if (lp->cur != NULL) lp->length++;
	return lp->cur;
}
Node *appendFromTail(LinkedList *lp, DataType *dataPtr)
{
	lp->cur = makeNode(dataPtr, lp->tail->prev, lp->tail);
	if (lp->cur != NULL) lp->length++;
	return lp->cur;
}
void display(LinkedList *lp, void(*print)(DataType *))
{
	system("cls");
	lp->cur = lp->head->next;
	while (lp->cur != lp->tail)
	{
		print(&lp->cur->data);
		lp->cur = lp->cur->next;
	}
	printf("# 아무 키나 누르면 메뉴로 돌아갑니다. #\n ");
	getch();
}
void deleteNode(LinkedList *lp, Node *target)
{
	target->next->prev = target->prev;
	target->prev->next = target->next;
	free(target);
	lp->length--;
}
Node *searchUnique(LinkedList *lp, DataType *dataPtr, int(*compare)(DataType *, DataType *))
{
	lp->cur = lp->head->next;
	while (lp->cur != lp->tail)
	{
		if (compare(&lp->cur->data, dataPtr) == 0)
			return lp->cur;
		lp->cur = lp->cur->next;
	}
	return NULL;
}
Node **searchDuplicate(LinkedList *lp, int *searchCnt, DataType *dataPtr, int(*compare)(DataType *, DataType *))
{
	*searchCnt = 0;
	Node **p = NULL;
	lp->cur = lp->head->next;
	while (lp->cur != lp->tail)
	{
		if (compare(dataPtr, &lp->cur->data) == 0)
		{
			(*searchCnt)++;
			p = (Node **)realloc(p, sizeof(Node *)*(*searchCnt));
			p[*searchCnt - 1] = lp->cur;
		}
		lp->cur = lp->cur->next;
	}
	return p;
}
void sortList(LinkedList *lp, int(*compare)(DataType *, DataType *))
{
	char s;
	Node *tp;
	DataType temp;
	system("cls");
	printf("# 이름 Sort(n,N) / 나이 Sort(a,A) : ");
	scanf("%c", &s);
	lp->cur = lp->head->next;
	while (lp->cur != lp->tail->prev)
	{
		tp = lp->cur->next;
		while (tp != lp->tail)
		{
			if (s == 'N' || s == 'n')
			{
				if (comparePersonName(&tp->data, &lp->cur->data) == 1)
				{
					temp = tp->data;
					tp->data = lp->cur->data;
					lp->cur->data = temp;
				}
			}
			else if (s == 'A' || s == 'a')
			{
				if (comparePersonAge(&tp->data, &lp->cur->data) == 1)
				{
					temp = tp->data;
					tp->data = lp->cur->data;
					lp->cur->data = temp;
				}
			}
			tp = tp->next;
		}
		lp->cur = lp->cur->next;
	}
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
}