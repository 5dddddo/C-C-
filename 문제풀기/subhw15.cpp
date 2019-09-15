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
		printf("# 정수값을 입력하세요 : ");
		if (scanf("%d", &n) == 1)
		{
			if (getchar() == '\n')
			{
				if (n > 0)
				{
					break;
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
	int i = 1, j = 1;
	char c = '*';
	while (j <= n)
	{
		if (i <= 5)
		{
			printf("%c", c);
			i++;
			j++;
		}
		else if (i = 6)
		{
			printf("\n");
			i = 1;
		}
	}
	printf("\n");
}