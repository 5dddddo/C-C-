#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "genericLinkedlist.h"
#include <Windows.h>
void create(LinkedList *lp)
{
	lp->head = (Node *)calloc(1, sizeof(Node)); //Head Node 생성
	lp->tail = (Node *)calloc(1, sizeof(Node)); //Tail Node 생성
	lp->head->next = lp->tail; //Head의 next -> Tail의 prev
	lp->tail->prev = lp->head; //Tail의 prev -> Head의 next
	lp->head->prev = lp->head; //Head의 prev -> Head 자신
	lp->tail->next = lp->tail; //Tail의 next -> Tail 자신
	lp->cur = NULL;
	lp->length = 0;

	return;
}

Node *makeNode(void *dataPtr, Node *prev, Node *next, size_t size, void(*myMemCpy)(void *, void *))
{
	Node *np;
	np = (Node *)calloc(1, sizeof(Node)+size);
	// sizeof(Node)+size == data영역의 크기 + NULL
	// calloc으로 해야지 malloc으로하면 안됨!
	if (np == NULL) return np; //할당 실패시 0 return
	np->prev = prev; // tail의 prev를 np의 prev에 저장
	np->next = next; // tail의 next를 np의 next에 저장
	np->prev->next = np; //이전 node가 새 node를 가리키도록
	np->next->prev = np; //tail의 prev가 새 node의 next를 가리키도록

	//np->data = *dataPtr; //Bit copy
	myMemCpy(np + 1, dataPtr); //Deep copy
	// np + 1 : 노드뒤에 붙어있는 data영역 주소 (Node *) 100번지 + 1 * (Node)크기 
	return np;
}


Node *appendFromTail(LinkedList *lp, void *item, size_t size, void(*myMemCpy)(void *, void *))
{
	lp->cur = makeNode(item, lp->tail->prev, lp->tail, size, myMemCpy); // ( ,prev,next)
	//성공 : 새 노드 주소 return, 실패 : NULL return
	if (lp->cur != NULL) lp->length++; //할당 성공시 length 1 증가
	return lp->cur;
}


Node *linearSearchUnique(LinkedList *lp, void *target, int(*compare)(void *, void *))
{
	lp->cur = lp->head->next; //#1. cur가 첫 노드 가르키게 함 
	while (lp->cur != lp->tail)
	{
		if (compare(lp->cur + 1, target) == 0)
			return lp->cur;
		lp->cur = lp->cur->next; //#2. 다음 노드로 이동시킴
	}
	return NULL;
}

void display(LinkedList *lp, void(*dataPrint)(int, int *, void *))
{
	int count = 0, sum = 0;
	system("cls");
	lp->cur = lp->head->next; //#1. cur가 첫 노드 가르키게 함 
	while (lp->cur != lp->tail)
	{
		count++;
		dataPrint(count, &sum, lp->cur + 1);
		lp->cur = lp->cur->next; //#2. 다음 노드로 이동시킴
	}
	printf("\n전체 단어의 개수 : %d	평균 단어 길이 : %d\n", count, sum / count);
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