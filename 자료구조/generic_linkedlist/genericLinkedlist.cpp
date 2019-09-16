#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "genericLinkedlist.h"
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

Node *appendFromHead(LinkedList *lp, void *item, size_t size, void(*myMemCpy)(void *, void *))
{
	lp->cur = makeNode(item, lp->head, lp->head->next, size, myMemCpy); // ( ,prev,next)
	//���� : �� ��� �ּ� return, ���� : NULL return
	if (lp->cur != NULL) lp->length++; //�Ҵ� ������ length 1 ����
	return lp->cur;
}

Node *appendFromTail(LinkedList *lp, void *item, size_t size, void(*myMemCpy)(void *, void *))
{
	lp->cur = makeNode(item, lp->tail->prev, lp->tail, size, myMemCpy); // ( ,prev,next)
	//���� : �� ��� �ּ� return, ���� : NULL return
	if (lp->cur != NULL) lp->length++; //�Ҵ� ������ length 1 ����
	return lp->cur;
}
Node *deleteNode(LinkedList *lp, Node *index, void(*dataFree)(void *))
{
	index->prev->next = index->next;
	index->next->prev = index->prev;
	
	//dataFree�� ��!
	dataFree(index + 1);
	free(index);
	lp->length--;
	return index;
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

Node **linearSearchDuplicate(LinkedList *lp, void *dataPtr, int *searchNodeCount, int(*compare)(void *, void *))
{
	*searchNodeCount = 0; //�׻� �ʱ�ȭ�ؾ� �ݺ� �˻�����!
	Node **p = NULL;
	lp->cur = lp->head->next; //#1. cur�� ù ��� ����Ű�� �� 
	while (lp->cur != lp->tail)
	{
		if (compare((lp->cur) + 1, dataPtr) == 0)
		{
			(*searchNodeCount)++;  //*searchCnt++ �ϸ� �ȵ�! ����!!!
			p = (Node **)realloc(p, sizeof(Node *)*(*searchNodeCount));
			assert(p != NULL);
			p[*searchNodeCount - 1] = lp->cur;
		}
		lp->cur = lp->cur->next; //#2. ���� ���� �̵���Ŵ
	}
	return p;
}

void display(LinkedList *lp, void(*dataPrint)(void *))
{
	system("cls");
	lp->cur = lp->head->next; //#1. cur�� ù ��� ����Ű�� �� 
	while (lp->cur != lp->tail)
	{
		dataPrint(lp->cur + 1);
		lp->cur = lp->cur->next; //#2. ���� ���� �̵���Ŵ
	}
	return;
}

void sortList(LinkedList *lp, size_t size, int(*compare)(void *, void *), void(*myMemCpy)(void *, void *), void(*dataFree)(void *))
{
	Node *tp;
	void *temp = calloc(1, size);
	lp->cur = lp->head->next; //#1. cur�� ù ��� ����Ű�� �� 
	while (lp->cur != lp->tail->prev)
	{
		tp = lp->cur->next;
		while (tp != lp->tail)
		{
			if (compare(lp->cur + 1, tp + 1) == 1)
			{
				myMemCpy(temp, lp->cur + 1);
				//dataFree(lp->cur + 1);
				myMemCpy(lp->cur + 1, tp + 1);
				//dataFree(tp + 1);
				myMemCpy(tp + 1, temp);
			}
			tp = tp->next;
		}
		lp->cur = lp->cur->next; //#2. ���� ���� �̵���Ŵ
		
		//�޸� ���� �����ϱ�!
		dataFree(temp);
		free(temp);
	}
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