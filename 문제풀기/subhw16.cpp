#pragma warning(disable : 4996)
#include <stdio.h>
int input(int *,int *);
void output(int,int);
int main()
{
	int n1, n2,num;
	while (1)
	{
		num = input(&n1, &n2);
		if (num < 0)
		{
			break;
		}
		output(n1, n2);
	}
	return 0;
}

int input(int *n1, int *n2)
{
	while (1)
	{
		printf("# 두 개의 정수를 입력하세요 : ");
		if (scanf("%d %d", n1, n2) == 2)
		{
			break;
		}
		else
		{
			return -1;
		}
	}
}

void output(int n1, int n2)
{
	int gap;
	if (n1 >= n2)
	{
		gap = n1 - n2;
		printf("%d - %d = %d\n", n1, n2, gap);
	}
	else
	{
		gap = n2 - n1;
		printf("%d - %d = %d\n", n2, n1, gap);
	}
}