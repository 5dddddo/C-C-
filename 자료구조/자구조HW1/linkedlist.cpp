#include <iostream>
using namespace std;
#include <assert.h>
#include <malloc.h>
#include "linkedlist.h"
#include <string>
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

Node *appendFromTail(LinkedList *lp, DataType *dataPtr)
{
	lp->cur = makeNode(dataPtr, lp->tail->prev, lp->tail); // ( ,prev,next)
	//성공 : 새 노드 주소 return, 실패 : NULL return
	if (lp->cur != NULL) lp->length++; //할당 성공시 length 1 증가
	return lp->cur;
}

void display(LinkedList *lp, void(*print)(DataType *))
{
	lp->cur = lp->head->next; //#1. cur가 첫 노드 가르키게 함 
	while (lp->cur != lp->tail)
	{
		print(&lp->cur->data);
		lp->cur = lp->cur->next; //#2. 다음 노드로 이동시킴
	}
	return;
}

void deleteNode(LinkedList *lp, Node *(&target))
{
	target->prev->next = target->next;
	target->next->prev = target->prev;
	free(target);
	lp->length--;
	return;
}

Node *searchUnique(LinkedList *lp, string newData)
{
	int lenW, lenN = newData.length();
	lp->cur = lp->head->next; //#1. cur가 첫 노드 가르키게 함 
	while (lp->cur != lp->tail)
	{
		lenW = lp->cur->data.getSearchword().length();
		if (lenW == lenN)
		{
			if (lp->cur->data.getSearchword() == newData)
				return lp->cur;
		}
		else
		{
			if (lp->cur->data.getSearchword().find(newData) != string::npos)
				return lp->cur;
		}
		lp->cur = lp->cur->next; //#2. 다음 노드로 이동시킴
	}
	return NULL;
}

Node * searchDuplicate(LinkedList *lp, string newDate, string newInfo)
{
	LinkedList findList;
	create(&findList);
	int  lenOld, lenI, lenD = newDate.length();
	lp->cur = lp->head->next; //#1. cur가 첫 노드 가르키게 함 
	while (lp->cur != lp->tail)
	{
		lenOld = lp->cur->data.getDate().length();
		if (lenOld == lenD)
		{
			if (lp->cur->data.getDate() == newDate)
				appendFromTail(&findList, &lp->cur->data);
		}
		else
		{
			if (lp->cur->data.getDate().find(newDate) != string::npos)
				appendFromTail(&findList, &lp->cur->data);
		}
		lp->cur = lp->cur->next; //#2. 다음 노드로 이동시킴
	}

	//display(&findList, printText);
	lenI = newInfo.length();
	findList.cur = findList.head->next; //#1. cur가 첫 노드 가르키게 함 
	while (findList.cur != findList.tail)
	{
		lenOld = findList.cur->data.getInformation().length();
		if (lenOld == lenI)
		{
			if (findList.cur->data.getInformation() == newInfo)
				return findList.cur;
		}
		else
		{
			if (findList.cur->data.getInformation().find(newInfo) != string::npos)
				return findList.cur;
		}
		findList.cur = findList.cur->next; //#2. 다음 노드로 이동시킴
	}
	return NULL;
}

void insertionSort(LinkedList *lp)
{
	Node *key = lp->head->next->next->next, *insertPos = key->prev;
	DataType tmp;
	while (insertPos != lp->tail)
	{
		lp->cur = insertPos->prev;
		while (lp->cur != lp->head)
		{
			if (insertPos->data.getFrequency() > lp->cur->data.getFrequency())
			{
				tmp = insertPos->data;
				insertPos->data = lp->cur->data;
				lp->cur->data = tmp;
			}
			insertPos = insertPos->prev;
			lp->cur = lp->cur->prev;
		}
		insertPos = key;
		key = key->next;
	}
}

//void bubbleSort(LinkedList *lp)
//{
//	Node *key, *sorted;
//	DataType temp;
//	int i;
//	lp->cur = lp->head->next;
//	key = lp->cur->next;
//	sorted = lp->tail;
//	cout << "\n	< Bubble Sort List >\n" << endl;
//	while (sorted != lp->head->next)
//	{
//		lp->cur = lp->head->next;
//		key = lp->cur->next;
//		while (lp->cur != sorted)
//		{
//			if (lp->cur->data.getFrequency() < key->data.getFrequency())
//			{
//				temp = key->data;
//				key->data = lp->cur->data;
//				lp->cur->data = temp;
//			}
//			lp->cur = lp->cur->next;
//			key = lp->cur->next;
//		}
//		sorted = sorted->prev;
//	}
//}
Node* partition(LinkedList *lp, Node *first, Node *last)
{
	Node* lastSmall(first), *i;

	for (i = first->next; i != last->next; i = i->next)
	{	// loop invariant: a[first+1]...a[lastSmall] <= a[first] &&
		//    a[lastSmall+1]...a[i-1] > a[first]
		if (i->data.getFrequency() <= first->data.getFrequency()) { // key comparison
			last = lastSmall->next;
			swapElements(lp, lastSmall, i);
		}
	}
	swapElements(lp, first, lastSmall); //z put pivot into correct position
	// postcondition: a[first]...a[lastSmall-1] <= a[lastSmall] &&
	//    a[lastSmall+1]...a[last] > a[lastSmall]
	return lastSmall; // this is the final position of the pivot -- the split index
}

void quicksort(LinkedList *lp, Node *first, Node *last)
{
	// precondition: a is an array; 
	//    The portion to be sorted runs from index first to index last inclusive.
	if (first == last) // Base Case -- nothing to sort, so just return
		return;
	// Otherwise, we’re in the recursive case.
	// The partition function uses the item in a[first] as the pivot
	// and returns the position of the pivot -- split -- after the partition.
	Node *split(partition(lp, first, last));

	// Recursively, sort the two partitions.
	quicksort(lp, first, split->prev);
	quicksort(lp, split->next, last);
	// postcondition: a is sorted in ascending order 
	// between first and last inclusive.
}
void swapElements(LinkedList *lp, Node *first, Node *i)
{
	DataType tmp;
	tmp = first->data;
	first->data = i->data;
	i->data = tmp;
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

void printText(DataType *p)
{
	cout << "SearchWord : " << p->getSearchword() << "\nFrequency : " << p->getFrequency()
		<< "\nDate : " << p->getDate() << "\nWebsite : " << p->getWebsite()
		<< "\nInformation : " << p->getInformation() << endl;
	cout << "--------------------------------------------------------------------------------" << endl;
}