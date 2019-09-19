#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include <string.h>
#include "linkedlist.h"
#include <conio.h>
#include <Windows.h>
void create(LinkedList *lp)
{
	lp->head = (Node *)calloc(1,sizeof(Node)); //Head Node 생성
	lp->tail = (Node *)calloc(1,sizeof(Node)); //Tail Node 생성
	lp->head->next = lp->tail; //Head의 next -> Tail의 prev
	lp->tail->prev = lp->head; //Tail의 prev -> Head의 next
	lp->head->prev = lp->head; //Head의 prev -> Head 자신
	lp->tail->next = lp->tail; //Tail의 next -> Tail 자신
	lp->cur = NULL;
	lp->length = 0;

	return;
}

Node *makeNode(DataType *dataPtr, Node *prev, Node *next)
{
	Node *np;
	np = (Node *)calloc(1, sizeof(Node));
	if (np == NULL) return np; //할당 실패시 0 return
	np->prev = prev; // tail의 prev를 np의 prev에 저장
	np->next = next; // tail의 next를 np의 next에 저장
	np->prev->next = np; //이전 node가 새 node를 가리키도록
	np->next->prev = np; //tail의 prev가 새 node의 next를 가리키도록
	np->data = *dataPtr; //np의 data에 구조체 내용 대입(초기화)
	return np;
}

Node *appendFromHead(LinkedList *lp, DataType *dataPtr)
{
	lp->cur = makeNode(dataPtr, lp->head, lp->head->next); // ( ,prev,next)
	//성공 : 새 노드 주소 return, 실패 : NULL return
	if (lp->cur != NULL) lp->length++; //할당 성공시 length 1 증가
	return lp->cur;
}

Node *appendFromTail(LinkedList *lp, DataType *dataPtr)
{
	lp->cur = makeNode(dataPtr, lp->tail->prev, lp->tail); // ( ,prev,next)
	//성공 : 새 노드 주소 return, 실패 : NULL return
	if (lp->cur != NULL) lp->length++; //할당 성공시 length 1 증가
	return lp->cur;
}

void display(LinkedList *lp, void(*print)(DataType *))
{
	system("cls");
	lp->cur = lp->head->next; //#1. cur가 첫 노드 가르키게 함 
	while (lp->cur != lp->tail)
	{
		print(&lp->cur->data);
		lp->cur = lp->cur->next; //#2. 다음 노드로 이동시킴
	}
	printf("# 아무 키나 누르면 주 메뉴로 돌아갑니다.\n");
	getch();
	return;
}

Node * searchUnique(LinkedList *lp, DataType *dataPtr, int(*compare)(DataType *, DataType *))
{
	lp->cur = lp->head->next; //#1. cur가 첫 노드 가르키게 함 
	while (lp->cur != lp->tail)
	{
		if (comparePersonName(&lp->cur->data, dataPtr) == 0)
			return lp->cur;
		lp->cur = lp->cur->next; //#2. 다음 노드로 이동시킴
	}
	return NULL;
}

Node ** searchDuplicate(LinkedList *lp, int *searchCnt, DataType *dataPtr, int(*compare)(DataType *, DataType *))
{
	*searchCnt = 0; //항상 초기화해야 반복 검색가능!
	Node **p = NULL;
	lp->cur = lp->head->next; //#1. cur가 첫 노드 가르키게 함 
	while (lp->cur != lp->tail)
	{
		if (comparePersonName(&lp->cur->data, dataPtr) == 0)
		{	
			(*searchCnt)++;  //*searchCnt++ 하면 안됨! 조심!!!
			p = (Node **)realloc(p, sizeof(Node *)*(*searchCnt));
			p[*searchCnt - 1] = lp->cur;
		}
		lp->cur = lp->cur->next; //#2. 다음 노드로 이동시킴
	}
	return p;
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
	while(lp->cur != lp->tail)
	{
		tp = lp->cur->next;
		free(lp->cur);
		lp->cur = tp;
	}
	free(lp->head);
	free(lp->tail);
	return;
}

void sortList(LinkedList *lp, int(*compare)(DataType *, DataType *))
{
	char s;
	Node *tp;
	DataType temp;
	system("cls");
	printf("# 이름 Sort(n,N) / 나이 sort(a,A) : ");
	scanf("%c", &s);
	lp->cur = lp->head->next; //#1. cur가 첫 노드 가르키게 함 
	while (lp->cur != lp->tail->prev)
	{
		tp = lp->cur->next;
		while (tp != lp->tail)
		{
			if (s == 'n' || s == 'N')
			{
				if (comparePersonName(&lp->cur->data, &tp->data) == 1)
				{
					temp = tp->data;
					tp->data = lp->cur->data;
					lp->cur->data = temp;
				}
			}
			else if (s == 'a' || s == 'A')
			{
				if (comparePersonAge(&lp->cur->data, &tp->data) == 1)
				{
					temp = tp->data;
					tp->data = lp->cur->data;
					lp->cur->data = temp;
				}
			}
			tp = tp->next;
		}
		lp->cur = lp->cur->next; //#2. 다음 노드로 이동시킴
	}
	return;
}

