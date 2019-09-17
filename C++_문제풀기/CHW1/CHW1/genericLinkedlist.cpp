#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "genericLinkedlist.h"
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

Node *makeNode(void *dataPtr, Node *prev, Node *next, size_t size, void(*myMemCpy)(void *, void *))
{
	Node *np;
	np = (Node *)calloc(1, sizeof(Node)+size);
	// sizeof(Node)+size == data������ ũ�� + NULL
	// calloc���� �ؾ��� malloc�����ϸ� �ȵ�!
	if (np == NULL) return np; //�Ҵ� ���н� 0 return
	np->prev = prev; // tail�� prev�� np�� prev�� ����
	np->next = next; // tail�� next�� np�� next�� ����
	np->prev->next = np; //���� node�� �� node�� ����Ű����
	np->next->prev = np; //tail�� prev�� �� node�� next�� ����Ű����

	//np->data = *dataPtr; //Bit copy
	myMemCpy(np + 1, dataPtr); //Deep copy
	// np + 1 : ���ڿ� �پ��ִ� data���� �ּ� (Node *) 100���� + 1 * (Node)ũ�� 
	return np;
}


Node *appendFromTail(LinkedList *lp, void *item, size_t size, void(*myMemCpy)(void *, void *))
{
	lp->cur = makeNode(item, lp->tail->prev, lp->tail, size, myMemCpy); // ( ,prev,next)
	//���� : �� ��� �ּ� return, ���� : NULL return
	if (lp->cur != NULL) lp->length++; //�Ҵ� ������ length 1 ����
	return lp->cur;
}


Node *linearSearchUnique(LinkedList *lp, void *target, int(*compare)(void *, void *))
{
	lp->cur = lp->head->next; //#1. cur�� ù ��� ����Ű�� �� 
	while (lp->cur != lp->tail)
	{
		if (compare(lp->cur + 1, target) == 0)
			return lp->cur;
		lp->cur = lp->cur->next; //#2. ���� ���� �̵���Ŵ
	}
	return NULL;
}

void display(LinkedList *lp, void(*dataPrint)(int, int *, void *))
{
	int count = 0, sum = 0;
	system("cls");
	lp->cur = lp->head->next; //#1. cur�� ù ��� ����Ű�� �� 
	while (lp->cur != lp->tail)
	{
		count++;
		dataPrint(count, &sum, lp->cur + 1);
		lp->cur = lp->cur->next; //#2. ���� ���� �̵���Ŵ
	}
	printf("\n��ü �ܾ��� ���� : %d	��� �ܾ� ���� : %d\n", count, sum / count);
	return;
}

void destroy(LinkedList *lp, void(*dataFree)(void *))
{
	Node *tp;
	lp->cur = lp->head->next;
	while (lp->cur != lp->tail)
	{
		tp = lp->cur->next;
		dataFree(lp->cur + 1);
		lp->cur = tp;
	}
	free(lp->head);
	free(lp->tail);
	return;
}