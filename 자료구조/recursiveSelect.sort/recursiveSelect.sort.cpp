#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void swap(int *ary, int a, int b);
void iteratorSelectionSort(int *ary, int n);
void recursiveSelectionSort(int *ary, int);
void initArray(int *ary, int n);
void printArray(int *ary, int n);

int main()
{
	int numberArray[10], arySize;
	arySize = sizeof(numberArray) / sizeof(numberArray[0]);
	srand((unsigned int)time(NULL));

	initArray(numberArray, arySize);
	iteratorSelectionSort(numberArray, arySize);
	printArray(numberArray, arySize);

	initArray(numberArray, arySize);
	recursiveSelectionSort(numberArray, arySize);
	printArray(numberArray, arySize);
	return 0;
}
void swap(int *ary, int a, int b)
{
	int t = ary[a];
	ary[a] = ary[b];
	ary[b] = t;
}
void iteratorSelectionSort(int *ary, int n)
{
	int target;
	for (int i = 0; i < n - 1; i++)
	{
		target = i;
		for (int j = i + 1; j < n; j++)
			if (ary[target]>ary[j])
				target = j;
		swap(ary, i, target);
	}
}
void recursiveSelectionSort(int *ary, int n)
{
	if (n == 1) return;
	int temp, target = 0;
	for (int i = 1; i < n; i++)
		if (ary[target] < ary[i]) 
			target = i;
	temp = ary[target];
	ary[target] = ary[n - 1];
	ary[n - 1] = temp;

	recursiveSelectionSort(ary, n - 1);
}

void initArray(int *ary, int n)
{
	int i;
	for (i = 0; i < n; ++i)
		ary[i] = rand() % 20 + 1;
}
void printArray(int *ary, int n)
{
	int i;
	printf("배열 내용 : ");
	for (i = 0; i < n; ++i)
		printf("%4d", ary[i]);
	printf("\n");
}