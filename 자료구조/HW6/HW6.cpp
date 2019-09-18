#include <stdio.h>
#pragma warning (disable : 4996)
int dataInput(int *);
int SearchMin(int *, int);
int SearchMax(int *, int);
void printInt(int *, int, int);
int main()
{
	int ary[100] = {};
	int cnt, min, max;
	while ((cnt = dataInput(ary)) != -1)
	{
		min = SearchMin(ary, cnt);
		max = SearchMax(ary, cnt);
		printInt(ary, min, max);
	}
	return 0;
}

int dataInput(int *ary)
{
	int data, cnt = 0;
	printf("정수 입력 : ");
	while (1)
	{
		if (scanf("%d", &data))
		{
			if (data != 0)
			{
				ary[cnt] = data;
				cnt++;
			}
			else return cnt;
		}
		else
			return -1;
	}
}

int SearchMin(int *ary, int cnt)
{
	int i, min = 0;
	for (i = 1; i < cnt; i++)
	{
		if (ary[min] > ary[i])
			min = i;
	}
	return min;
}

int SearchMax(int *ary, int cnt)
{
	int i, max = 0;
	for (i = 1; i < cnt; i++)
	{
		if (ary[max] < ary[i])
			max = i;
	}
	return max;
}

void printInt(int *ary, int min, int max)
{
	printf("최대값 : %d(indax:%d) / 최소값 : %d(index:%d)\n", ary[max], max, ary[min], min);
	return;
}