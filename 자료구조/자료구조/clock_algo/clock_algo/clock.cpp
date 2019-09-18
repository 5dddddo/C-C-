#include<stdio.h>
#include <stdlib.h>
#include <ctime>
#pragma warning(disable : 4996)
void print_array(int *data, int n);
void swap(int *data, int a, int b);
//void selection_sort(int *data, int n);
void selection_sort2(int *data, int n);

int main()
{
	int data[100000];
	int n;
	int startTime, endTime;
	printf("process start time : %d(millisecond)\n", clock());
	srand((unsigned int)time(NULL));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		data[i] = rand();
	}
	startTime = clock();
	printf("소트 알고리즘 시작시간 : %d(millisecond)\n", startTime);
	selection_sort2(data, n);
	endTime = clock();
	printf("소트 알고리즘 종료시간 : %d(millisecond)\n",endTime);
	printf("소트 알고리즘 실행 소요시간 : %d(millisecond)\n", (endTime-startTime));
	return 0;
}

void print_array(int *data, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n");
}

void swap(int *data, int a, int b)
{
	int t = data[a];
	data[a] = data[b];
	data[b] = t;
}

void selection_sort(int *data, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = i + 1; j < n; j++)
			if (data[i] > data[j])
				swap(data, i, j);
	}

}
void selection_sort2(int *data, int n)
{
	int target;
	for (int i = 0; i < n - 1; i++)
	{
		target = i;
		for (int j = i + 1; j < n; j++)
			if (data[target] > data[j])
				target = j;
		swap(data, i, target);
	}

}