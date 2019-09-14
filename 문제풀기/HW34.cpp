#pragma warning (disable : 4996)
#include <stdio.h>
void inputArray(int *,int);
void ascendingSort(int *, int);
void descendingSort(int *, int);
void outputArray(int *, int);
int main()
{
	int ary[10];
	inputArray(ary,sizeof(ary)/sizeof(ary[0]));
	ascendingSort(ary, sizeof(ary) / sizeof(ary[0]));
	outputArray(ary, sizeof(ary) / sizeof(ary[0]));
	printf("\n");
	descendingSort(ary, sizeof(ary) / sizeof(ary[0]));
	outputArray(ary, sizeof(ary) / sizeof(ary[0]));
	printf("\n");
	return 0;
}

void inputArray(int *ip, int count)
{
	int i;
	for (i = 0; i < count; i++)
	{
		printf("정수를 입력하시오(%d개) : ", i + 1);
		scanf("%d", &ip[i]);
	}
}

void ascendingSort(int *ip, int count)
{
	int i, j, temp;
	printf("오름차순 정렬 : ");
	for (i = 0; i < count - 1; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if (*(ip + i) > *(ip + j))
			{
				temp = *(ip + i);
				*(ip + i) = *(ip + j);
				*(ip + j) = temp;
			}
		}
	}
}

void descendingSort(int *ip, int count)
{
	int i, j, temp;
	printf("내림차순 정렬 : ");
	for (i = 0; i < count - 1; i++)
	{
		for (j = i + 1; j < count; j++)
		{
			if (*(ip + i) < *(ip + j))
			{
				temp = *(ip + i);
				*(ip + i) = *(ip + j);
				*(ip + j) = temp;
			}
		}
	}
	
}

void outputArray(int *ip, int count)
{
	int i;
	for (i = 0; i < count; i++)
	{
		printf("%d ", *(ip + i));
	}
}
