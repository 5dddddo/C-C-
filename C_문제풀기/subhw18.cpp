#pragma warning (disable : 4996)
#include <stdio.h>
int input();
void output(int);
int main()
{
	int num, sum = 0;
	while (1)
	{
		num = input();
		if (num >= 0)
		{
			sum += num;
		}
		else
		{
			break;
		}
		output(sum);
	}
}

int input()
{
	int n;
	printf("양수를 입력하세요 : ");
	while (1)
	{
		if (scanf("%d", &n) == 1)
		{
			if (getchar() == '\n')
			{
				if (n >= 0)
				{
					return n;
				}
				else
				{
					return -1;
				}
			}
		}
		else
		{
			printf("다시 입력하시오 :");
			fflush(stdin);
		}
	}
}

void output(int sum)
{
	printf("지금까지 입력된 값의 합 : %d\n",sum);
}