// linkedlist class 정의
#pragma once
#pragma warning (disable : 4996)
#include "SearchHistory.h"

typedef class searchHistory DataType;

// *** linkedlist의 struct Node 
// 앞 node를 가리키는 Node *prev,
// 뒤 node를 가리키는 Node *next와
// data로 구성됨
typedef struct _node Node;
struct _node{
	Node *prev;
	DataType data;
	Node *next;
};
// *** linkedlist를 관리하기 위한 struct LinkedList
// linkedlist의 맨 처음 Node인 head,
// linkedlist의 맨 마지막 Node인 tail,
// 현재 Node를 가리키는 cur,
// linkedlist의 총 Node 수를 count하는 length로 구성

typedef struct _linkedList{
	Node *head;
	Node *cur;
	Node *tail;
	int length;
}LinkedList;

void create(LinkedList *lp);
// Precondition : 연결되어 있는 Node가 존재하지 않고 LinkedList만 선언돼 있어야 함. 
//
// Linked List 맨 앞을 가리킬 Head Node를 동적할당하고 head Node의 prev가 Head Node 자기자신을 가리키게 함.
// 마찬가지로, Linked List 맨 뒤를 가리킬 Tail Node를 동적할당하고 Tail Node의 next가 Tail Node 자기자신을 가리키게 함.
// Postcondition : Head Node와 Tail Node가 연결되었고 cur은 NULL pointer로, length는 0으로 초기화 됨. 

Node *makeNode(DataType *dataPtr, Node *prev, Node *next);
// Precondition : DataType(=searchHistory)에 적절한 값이 저장되어 있어야 하고,
// 새 노드를 LinkedList 맨 마지막에 추가할 것이기 때문에
// tail과 tail->prev의 위치 필요.
// 
// Node를 동적할당하고 tail->prev와 tail사이에 새로운 Node를 삽입한 후 data 입력.
// Postcondition : 새로운 Node가 tail앞에 추가됨. 
// return : 추가된 새 Node를 가리킴.

Node *appendFromTail(LinkedList *lp, DataType *dataPtr);
// Precondition : 새롭게 추가할 적절한 DataType의 Data 필요.
//
// makeNode함수 성공 여부 확인.
// Postcondition : 새 Node가 추가되었으면 length의 값을 1 증가시킴.
// return : LinkedList Node 중 현재 가리키고 있는 Node return.

void display(LinkedList *lp, void(*print)(DataType *));
// Precondition : LinkedList를 가리키고 있어야 하며
// linkedlist Node의 data를 출력할 함수가 존재해야 함.
//
// Postcondition : Head Node의 다음 Node부터 Tail Node의 앞 Node까지 전체 data 출력.

void deleteNode(LinkedList *lp, Node *(&target));
// Precondition : 1개 이상의 data를 가진 Node가 존재해야함.
//
// target Node의 앞 Node와 target Node의 뒤 Node를 연결하고 동적할당 한 target Node를 free함.
// Postcondition : length값 1 감소.

Node *searchUnique(LinkedList *lp, string newData);
// Precondition :  1개 이상의 data를 가진 Node가 존재해야 함.
//
// 찾으려는 newData의 길이가 비교하려는 LinkedList data의 길이보다 길면 다음 Node로 이동하고
// 두 data의 길이가 같으면 비교하고 
// 길이가 다르면 string의 find 함수로 비교함.
// Postcondition : lp->cur가 찾은 Node를 가리킴.
// return : newData의 값과 같은 값을 가진 Node를 찾아 return.
//			LinkedList의 끝까지 비교한 결과 찾는 data가 없으면 NULL return.

Node *searchDuplicate(LinkedList *lp, string newDate, string newInfo);
// Precondition : 1개 이상의 data를 가진 Node가 존재해야 함.
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
//	// Otherwise, we’re in the recursive case.
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