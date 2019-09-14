#pragma warning (disable : 4996)
#include <stdio.h>
int input();
void output(int);
int main()
{
	int num;
	while (1)
	{
		num = input();
		if (num < 0)
		{
			break;
		}
		output(num);
	}
	return 0;
}

int input()
{
	int n;
	printf("* 정수를 입력하시오 : ");
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
			printf("다시 입력하세요 : ");
			fflush(stdin);
		}
	}
}

void output(int n)
{
	int i;
	for (i = n; i <= n + 10; i++)
	{
		printf("[%d] ", i);
	}
	printf("\n");
}