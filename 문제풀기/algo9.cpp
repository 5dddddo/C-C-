#pragma warning (disable : 4996)
#include <stdio.h>
void input(char *,int *);
int calcodd(int);
int maxodd(int, int);
void output(int,int);
int main()
{
	int n1, n2, n3, n4, n5, max = 0, sum = 0;
	input("정수 입력 : ", &n1);
	input("정수 입력 : ", &n2);
	input("정수 입력 : ", &n3);
	input("정수 입력 : ", &n4);
	input("정수 입력 : ", &n5);
	sum += calcodd(n1);
	sum += calcodd(n2);
	sum += calcodd(n3);
	sum += calcodd(n4);
	sum += calcodd(n5);
	max = maxodd(max, n1);
	max = maxodd(max, n2);
	max = maxodd(max, n3);
	max = maxodd(max, n4);
	max = maxodd(max, n5);
	output(sum,max);
	return 0;
}

void input(char *m, int *n)
{
	while (1)
	{
		printf(m);
		if (scanf("%d", n) == 1)
		{
			if (getchar() == '\n')
			{
				if (*n > 0)
				{
					break;
				}
				else
				{
					printf("다시입력.\n");
					fflush(stdin);
				}
			}
			else
			{
				printf("다시입력.\n");
				fflush(stdin);
			}
		}
		else
		{
			printf("다시입력.\n");
			fflush(stdin);
		}
	}
}

int calcodd(int n)
{
	int sum = 0;
	if (n % 2 == 1)
	{
		sum = n;
		return sum;
	}
}

int maxodd(int max,int n)
{
	if (n % 2 == 1)
	{
		if (n >= max)
		{
			return n;
		}
		else
		{
			return max;
		}
	}
	return max;
}
void output(int sum,int max)
{
	if (sum != 0)
	{
		printf("합 : %d\n", sum);
		printf("최대값 : %d\n", max);
	}
	else
	{
		printf("홀수가 입력되지 않았습니다.\n");
	}
}