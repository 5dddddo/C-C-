#pragma warning (disable : 4996)
#include <stdio.h>
void input(char *, int *);
int calcNum(int,int,int);
void output(int);
int main()
{
	int a, r, num,n;
	input("초항 입력 : ", &a);
	input("공비 입력 : ", &r);
	input("임의의 수 입력 : ", &num);
	n = calcNum(a,r,num);
	output(n);
	return 0;
}

void input(char *message, int *n)
{
	while (1)
	{
		printf(message);
		if (scanf("%d", n) == 1)
		{
			if (getchar() == '\n')
			{
				if (*n > 0)
				{
					break;
				}
			}
		}
		else
		{
			printf("다시입력.\n");
			fflush(stdin);
		}
	}
}

int calcNum(int a, int r, int num)
{
	int n = 1;
	int res;
	res = a;

	while(1)
	{
		res *= r;
		n++;
		if (num == res)
		{
			break;
		}
		else if (num < res)
		{
			return 0;
		}
		
	}
	return n;
}

void output(int n)
{
	if (n != 0)
	{
		printf("%d번째 항입니다.\n",n);
	}
	else
	{
		printf("수열에 포함되어 있지 않습니다.\n");
	}
}