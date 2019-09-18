#include "searchHistory.h"
#include <string>
#pragma once
void initHistoryList(searchHistory **firstHistory, searchHistory **secondHistory);
// Precondition : firstHistory,secondHistory는 searchHistory 배열을 가리키는 pointer
//
// Postcondition : firstHistory[0] ...firstHistory[9]까지 멤버변수 모두 초기화 됨
//				   secondHistory[0]...secondHistory[9]까지 멤버변수 모두 초기화 됨
// return : 없음
void deleteHistoryList(searchHistory **firstHistory, searchHistory **secondHistory);
// Precondition : firstHistory,secondHistory는 searchHistory 배열을 가리키는 pointer
// 
// Postcondition : firstHistory,secondHistory가 가리키는 pointer배열에 동적할당 된 공간 delete. 
// return : 없음
void display(searchHistory *sp);
// Precondition : sp는 동적할당된 searchHistory를 가리키고 있어야 함
// 
// Postcondition : sp가 가리키고 있는 searchHistory의 검색어,날짜,웹사이트,정보,빈도수를 출력
// return : 없음
void display(searchHistory **sp);
// Precondition : sp는 searchHistory Pointer 배열을 가리키고 있어야 함
// 
// 단, sp[i]가 가리키는 값이 NULL이면
// 출력할 정보가 없기 때문에 다음 index로 넘어감.
// sp[i]가 가리키는 값이 NULL이 아니면 정보 출력.
// Postcondition : i = 0~9까지 sp[i]가 가리키는 searchHistory의 검색어,날짜,웹사이트,정보,빈도수를 출력
// return : 없음
int searchOneField(searchHistory **sp, string newData);
// Precondition : sp는 searchHistory Pointer 배열을 가리키고 있어야 하고,
//				  newData 변수에 찾으려는 정보가 저장되어 있어야 함.
// sp[i]가 가리키는 값이 NULL이 아니면
// sp[i]의 멤버함수 getSearchword()를 호출해 searchword를 불러오고,
// string의 멤버함수 find를 호출해 newData와 같은 단어가 있는 index를 찾음.
//
// Postcondition : sp가 가리키는 배열 내에 newData와 같은 정보가 있는지 알 수 있음.
// return : newData가 배열 내에 있으면 그 배열의 index를 return하고 없으면 -1 return.
searchHistory* searchTwoField(searchHistory **sp, string newDate, string newInfo);
// Precondition : sp는 searchHistory Pointer 배열을 가리키고 있어야 하고,
//				  newDate 변수와 newInfo 변수에 찾으려는 정보가 저장되어 있어야 함.
// sp[i]의 멤버함수 getSearchDate()를 호출해 date를 불러옴.
// string의 멤버함수 find를 호출해 newDate와 같은 단어가 있으면
// searchHistory pointer배열 tmp에 searchHistory를 동적할당하고 정보들을 저장.
// newInfo는 tmp배열에서 검색하고
// 일치하는 searchHistory를 return함.
// Postcondition : sp가 가리키는 배열 내에 newData와 같은 정보가 있는지 알 수 있음.
// return : newDate&&newInfo가 pointer배열 내에 있으면 그 배열을 return하고 없으면 NULL return.
void insertNextItem(searchHistory **sp, int i);
// Precondition :  sp is sorted from 0 to i-1
// 
// Postcondition : Postcondition: array a is sorted from 0 to i
// return : 없음
void insertionSort(searchHistory **sp, int n = 10);
// Precondition : sp is an array with subscripts ranging from 0 to n-1
// 
// Postcondition :  Postcondition: array a is sorted
// return : 없음
void quicksort(searchHistory **sp, int first, int last);
// Precondition : sp는 searchHistory pointer배열을 가리키는 pointer.
// 
// Postcondition : sp가 가리키는 searchHistory pointer배열이 정렬됨.
// return : 없음
void swapElements(searchHistory **sp, int first, int last);
// Precondition :  sp는 searchHistory pointer배열을 가리키는 pointer.
// 
// Postcondition : sp[first]와 sp[last]가 swap 됨
// return : 없음
int partition(searchHistory **sp, int first, int last);
// Precondition : sp는 searchHistory pointer배열을 가리키는 pointer.
// 
// Postcondition :  a[first]...a[lastSmall-1] <= a[lastSmall] &&
//				    a[lastSmall+1]...a[last] > a[lastSmall]
// return : this is the final position of the pivot -- the split index