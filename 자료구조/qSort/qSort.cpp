#include <stdio.h>
#pragma warning (disable : 4996)
void quickSort(int *ary, int size);
int binarySearch(int *ary, int leftIndex, int rightIndex, int key);
void output(int *ary, int size);
int main()
{
	int ary[10] = { 11, 3, 25, 7, 19, 10, 13, 35, 8, 19 };
	int size = sizeof(ary) / sizeof(ary[0]);
	int key;
	int index;
	int res;
	quickSort(ary, size);
	output(ary, size);

	while (1)
	{
		printf("검색할 숫자 입력(문자입력 시 종료) : ");
		res = scanf("%d", &key);
		if (res != 1) { break; }
		if ((index = binarySearch(ary, 0, size - 1, key)) != -1)
			printf("%d는 %d번방 데이터입니다. \n", key, index);
		else
			printf("%d는 존재하지 않습니다. \n", key);
	}
	return 0;
}

/*int binarySearch(int *ary, int leftIndex, int rightIndex, int key) ////////비재귀 binarySearch
{
	int size, mid;
	size = rightIndex - leftIndex;
	while (size > 0)
	{	
		size = rightIndex - leftIndex;
		mid = (leftIndex + rightIndex) / 2;
		if (key == ary[mid])
			return mid;
		else if (key > ary[mid])
			leftIndex = mid + 1;
		else
			rightIndex = mid - 1;
	}
	return -1;
}
*/

int binarySearch(int *ary, int leftIndex, int rightIndex, int key) ////////재귀 binarySearch
{
	int size, mid;
	size = rightIndex - leftIndex;
	mid = (leftIndex + rightIndex) / 2;
	if (size < 0) return -1;
	if (key == ary[mid])
		return mid;
	else if (key > ary[mid])
		binarySearch(ary, mid + 1, rightIndex, key);
	else
		binarySearch(ary, leftIndex, mid - 1, key);
}
void quickSort(int *ary, int size)
{
	int pivot, temp;
	int i = -1;
	int j = size - 1;
	if (size <= 1) return;
	pivot = ary[size - 1];
	while (1)
	{
		while (ary[++i] < pivot);
		while (j > 0 && ary[--j] > pivot);
		if (i >= j) break;
		temp = ary[i];
		ary[i] = ary[j];
		ary[j] = temp;

	}
	temp = ary[i];
	ary[i] = ary[size-1];
	ary[size-1] = temp;

	quickSort(ary, i);
	quickSort(ary + i + 1, size - i - 1);
}

void output(int *ary, int size)
{
	for (int i = 0; i < size; i++)
		printf(" %d ", ary[i]);
	printf("\n");

}