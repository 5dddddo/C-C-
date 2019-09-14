#pragma warning (disable : 4996)
#include <stdio.h>
int input();
void output(int *);
int main()
{
	int str[10], num, i = 0, j = 9, count;
	for (count = 0; count < 10; count++)
	{
		num = input();
		if (num % 2 == 1)
		{
			str[i] = num;
			i++;
		}
		else
		{
			str[j] = num;
			j--;
		}
	}
	output(str);
	return 0;
}

int input()
{
	int num;
	while (1)
	{
		printf("정수를 입력하시오 : ");
		if (scanf("%d", &num) == 1)
		{
			if (getchar() == '\n')
			{
				if (num > 0)
				{
					break;
				}
			}
		}
		else
		{
			fflush(stdin);
		}
	}
	return num;
}

void output(int *str)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", str[i]);
	}
}