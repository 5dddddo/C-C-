#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "linkedlist.h"
#include <conio.h>
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

Node *makeNode(char *dataPtr, Node *prev, Node *next)
{
	Node *np;
	np = (Node *)calloc(1, sizeof(Node));
	if (np == NULL) return np; //할당 실패시 0 return
	np->prev = prev; // tail의 prev를 np의 prev에 저장
	np->next = next; // tail의 next를 np의 next에 저장
	np->prev->next = np; //이전 node가 새 node를 가리키도록
	np->next->prev = np; //tail의 prev가 새 node의 next를 가리키도록
	strcpy(np->data, dataPtr);
	return np;
}


Node *appendFromTail(LinkedList *lp, char *dataPtr)
{
	lp->cur = makeNode(dataPtr, lp->tail->prev, lp->tail); // ( ,prev,next)
	//성공 : 새 노드 주소 return, 실패 : NULL return
	if (lp->cur != NULL) lp->length++; //할당 성공시 length 1 증가

	return lp->cur;
}

void display(LinkedList *lp, void(*print)(char *))
{
	lp->cur = lp->head->next; //#1. cur가 첫 노드 가르키게 함 
	while (lp->cur != lp->tail)
	{
		print(lp->cur->data);
		lp->cur = lp->cur->next; //#2. 다음 노드로 이동시킴
	}
	return;
}

void printWord(char *p)
{
	printf("%s / ", p);
}

void deleteNode(LinkedList *lp, Node *target)
{
	target->prev->next = target->next;
	target->next->prev = target->prev;
	free(target);
	lp->length--;
	return;
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
