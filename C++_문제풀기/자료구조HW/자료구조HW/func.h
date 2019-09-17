#include "searchHistory.h"
#include <string>
#pragma once
void initHistoryList(searchHistory **firstHistory, searchHistory **secondHistory);
// Precondition : firstHistory,secondHistory�� searchHistory �迭�� ����Ű�� pointer
//
// Postcondition : firstHistory[0] ...firstHistory[9]���� ������� ��� �ʱ�ȭ ��
//				   secondHistory[0]...secondHistory[9]���� ������� ��� �ʱ�ȭ ��
// return : ����
void deleteHistoryList(searchHistory **firstHistory, searchHistory **secondHistory);
// Precondition : firstHistory,secondHistory�� searchHistory �迭�� ����Ű�� pointer
// 
// Postcondition : firstHistory,secondHistory�� ����Ű�� pointer�迭�� �����Ҵ� �� ���� delete. 
// return : ����
void display(searchHistory *sp);
// Precondition : sp�� �����Ҵ�� searchHistory�� ����Ű�� �־�� ��
// 
// Postcondition : sp�� ����Ű�� �ִ� searchHistory�� �˻���,��¥,������Ʈ,����,�󵵼��� ���
// return : ����
void display(searchHistory **sp);
// Precondition : sp�� searchHistory Pointer �迭�� ����Ű�� �־�� ��
// 
// ��, sp[i]�� ����Ű�� ���� NULL�̸�
// ����� ������ ���� ������ ���� index�� �Ѿ.
// sp[i]�� ����Ű�� ���� NULL�� �ƴϸ� ���� ���.
// Postcondition : i = 0~9���� sp[i]�� ����Ű�� searchHistory�� �˻���,��¥,������Ʈ,����,�󵵼��� ���
// return : ����
int searchOneField(searchHistory **sp, string newData);
// Precondition : sp�� searchHistory Pointer �迭�� ����Ű�� �־�� �ϰ�,
//				  newData ������ ã������ ������ ����Ǿ� �־�� ��.
// sp[i]�� ����Ű�� ���� NULL�� �ƴϸ�
// sp[i]�� ����Լ� getSearchword()�� ȣ���� searchword�� �ҷ�����,
// string�� ����Լ� find�� ȣ���� newData�� ���� �ܾ �ִ� index�� ã��.
//
// Postcondition : sp�� ����Ű�� �迭 ���� newData�� ���� ������ �ִ��� �� �� ����.
// return : newData�� �迭 ���� ������ �� �迭�� index�� return�ϰ� ������ -1 return.
searchHistory* searchTwoField(searchHistory **sp, string newDate, string newInfo);
// Precondition : sp�� searchHistory Pointer �迭�� ����Ű�� �־�� �ϰ�,
//				  newDate ������ newInfo ������ ã������ ������ ����Ǿ� �־�� ��.
// sp[i]�� ����Լ� getSearchDate()�� ȣ���� date�� �ҷ���.
// string�� ����Լ� find�� ȣ���� newDate�� ���� �ܾ ������
// searchHistory pointer�迭 tmp�� searchHistory�� �����Ҵ��ϰ� �������� ����.
// newInfo�� tmp�迭���� �˻��ϰ�
// ��ġ�ϴ� searchHistory�� return��.
// Postcondition : sp�� ����Ű�� �迭 ���� newData�� ���� ������ �ִ��� �� �� ����.
// return : newDate&&newInfo�� pointer�迭 ���� ������ �� �迭�� return�ϰ� ������ NULL return.
void insertNextItem(searchHistory **sp, int i);
// Precondition :  sp is sorted from 0 to i-1
// 
// Postcondition : Postcondition: array a is sorted from 0 to i
// return : ����
void insertionSort(searchHistory **sp, int n = 10);
// Precondition : sp is an array with subscripts ranging from 0 to n-1
// 
// Postcondition :  Postcondition: array a is sorted
// return : ����
void quicksort(searchHistory **sp, int first, int last);
// Precondition : sp�� searchHistory pointer�迭�� ����Ű�� pointer.
// 
// Postcondition : sp�� ����Ű�� searchHistory pointer�迭�� ���ĵ�.
// return : ����
void swapElements(searchHistory **sp, int first, int last);
// Precondition :  sp�� searchHistory pointer�迭�� ����Ű�� pointer.
// 
// Postcondition : sp[first]�� sp[last]�� swap ��
// return : ����
int partition(searchHistory **sp, int first, int last);
// Precondition : sp�� searchHistory pointer�迭�� ����Ű�� pointer.
// 
// Postcondition :  a[first]...a[lastSmall-1] <= a[lastSmall] &&
//				    a[lastSmall+1]...a[last] > a[lastSmall]
// return : this is the final position of the pivot -- the split index