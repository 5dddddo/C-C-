#pragma warning(disable : 4996)
#include <stdio.h>
int input();
void output(int);
int main()
{
	int num;
	num = input();
	output(num);
	return 0;
}

int input()
{
	int n;

	while (1)
	{
		printf("# 정수값을 입력하시오 : ");
		if (scanf("%d", &n) == 1)
		{
			if (getchar() == '\n')
			{
				if (n > 0)
				{
					break;
				}
				else
				{
					fflush(stdin);
				}
			}
			else
			{
				fflush(stdin);
			}
		}
		else
		{
			fflush(stdin);
		}
	}
	return n;
}

void output(int n)
{
	int i = 1, sum = 0;
	while (i <= n)
	{
		sum += i;
		i++;
	}
	printf("1부터 %d까지의 합은 %d입니다.\n", n, sum);
}