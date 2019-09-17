// linkedlist class ����
#pragma once
#pragma warning (disable : 4996)
#include "SearchHistory.h"

typedef class searchHistory DataType;

// *** linkedlist�� struct Node 
// �� node�� ����Ű�� Node *prev,
// �� node�� ����Ű�� Node *next��
// data�� ������
typedef struct _node Node;
struct _node{
	Node *prev;
	DataType data;
	Node *next;
};
// *** linkedlist�� �����ϱ� ���� struct LinkedList
// linkedlist�� �� ó�� Node�� head,
// linkedlist�� �� ������ Node�� tail,
// ���� Node�� ����Ű�� cur,
// linkedlist�� �� Node ���� count�ϴ� length�� ����

typedef struct _linkedList{
	Node *head;
	Node *cur;
	Node *tail;
	int length;
}LinkedList;

void create(LinkedList *lp);
// Precondition : ����Ǿ� �ִ� Node�� �������� �ʰ� LinkedList�� ����� �־�� ��. 
//
// Linked List �� ���� ����ų Head Node�� �����Ҵ��ϰ� head Node�� prev�� Head Node �ڱ��ڽ��� ����Ű�� ��.
// ����������, Linked List �� �ڸ� ����ų Tail Node�� �����Ҵ��ϰ� Tail Node�� next�� Tail Node �ڱ��ڽ��� ����Ű�� ��.
// Postcondition : Head Node�� Tail Node�� ����Ǿ��� cur�� NULL pointer��, length�� 0���� �ʱ�ȭ ��. 

Node *makeNode(DataType *dataPtr, Node *prev, Node *next);
// Precondition : DataType(=searchHistory)�� ������ ���� ����Ǿ� �־�� �ϰ�,
// �� ��带 LinkedList �� �������� �߰��� ���̱� ������
// tail�� tail->prev�� ��ġ �ʿ�.
// 
// Node�� �����Ҵ��ϰ� tail->prev�� tail���̿� ���ο� Node�� ������ �� data �Է�.
// Postcondition : ���ο� Node�� tail�տ� �߰���. 
// return : �߰��� �� Node�� ����Ŵ.

Node *appendFromTail(LinkedList *lp, DataType *dataPtr);
// Precondition : ���Ӱ� �߰��� ������ DataType�� Data �ʿ�.
//
// makeNode�Լ� ���� ���� Ȯ��.
// Postcondition : �� Node�� �߰��Ǿ����� length�� ���� 1 ������Ŵ.
// return : LinkedList Node �� ���� ����Ű�� �ִ� Node return.

void display(LinkedList *lp, void(*print)(DataType *));
// Precondition : LinkedList�� ����Ű�� �־�� �ϸ�
// linkedlist Node�� data�� ����� �Լ��� �����ؾ� ��.
//
// Postcondition : Head Node�� ���� Node���� Tail Node�� �� Node���� ��ü data ���.

void deleteNode(LinkedList *lp, Node *(&target));
// Precondition : 1�� �̻��� data�� ���� Node�� �����ؾ���.
//
// target Node�� �� Node�� target Node�� �� Node�� �����ϰ� �����Ҵ� �� target Node�� free��.
// Postcondition : length�� 1 ����.

Node *searchUnique(LinkedList *lp, string newData);
// Precondition :  1�� �̻��� data�� ���� Node�� �����ؾ� ��.
//
// ã������ newData�� ���̰� ���Ϸ��� LinkedList data�� ���̺��� ��� ���� Node�� �̵��ϰ�
// �� data�� ���̰� ������ ���ϰ� 
// ���̰� �ٸ��� string�� find �Լ��� ����.
// Postcondition : lp->cur�� ã�� Node�� ����Ŵ.
// return : newData�� ���� ���� ���� ���� Node�� ã�� return.
//			LinkedList�� ������ ���� ��� ã�� data�� ������ NULL return.

Node *searchDuplicate(LinkedList *lp, string newDate, string newInfo);
// Precondition : 1�� �̻��� data�� ���� Node�� �����ؾ� ��.
//
// Postcondition :
// return :

void insertionSort(LinkedList *lp);
// Precondition : 
//
// Postcondition :

Node* partition(LinkedList *lp, Node *fisrt, Node *last);
	//int lastSmall(first), i;

	//for (i = first + 1; i <= last; i++)
	//	// loop invariant: a[first+1]...a[lastSmall] <= a[first] &&
	//	//    a[lastSmall+1]...a[i-1] > a[first]
	//if (a[i] <= a[first]) { // key comparison
	//	++lastSmall;
	//	swapElements(a, lastSmall, i);
	//}

	//swapElements(a, first, lastSmall); // put pivot into correct position
	//// postcondition: a[first]...a[lastSmall-1] <= a[lastSmall] &&
	////    a[lastSmall+1]...a[last] > a[lastSmall]
	//return lastSmall; // this is the final position of the pivot -- the split index


void quicksort(LinkedList *lp, Node *first, Node *last);
//	// precondition: a is an array; 
//	//    The portion to be sorted runs from index first to index last inclusive.
//	if (first >= last) // Base Case -- nothing to sort, so just return
//		return;
//	// Otherwise, we��re in the recursive case.
//	// The partition function uses the item in a[first] as the pivot
//	// and returns the position of the pivot -- split -- after the partition.
//	int split(partition(a, first, last));
//
//	// Recursively, sort the two partitions.
//	quicksort(a, first, split - 1);
//	quicksort(a, split + 1, last);
//	// postcondition: a is sorted in ascending order 
//	// between first and last inclusive.

void swapElements(LinkedList *lp, Node *first, Node *i);

//void quickSort(LinkedList *lp);
//void bubbleSort(LinkedList *lp);

void destroy(LinkedList *lp);
// Precondition : 
//
// Postcondition : 

void printText(DataType *p);
// Precondition : 
//
// Postcondition : 