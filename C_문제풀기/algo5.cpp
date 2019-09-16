#pragma warning(disable : 4996)
#include <stdio.h>
int inputDiceNum();
void findCase(int);
int main()
{
	int num;
	num = inputDiceNum();
	findCase(num);
	return 0;
}

int inputDiceNum()
{
	int n;
	
	while (1)
	{
		printf("정수 입력 :");
		scanf("%d", &n);
		if (n >= 2 && n <= 12)
		{
			break;
		}
		else
		{
			printf("Error\n");
		}
	}
	return n;
}

void findCase(int n)
{
	int i = 1;
	int j;
	while (i <= 6)
	{
		j = 6;
		while (j > 0)
		{
			if (i + j == n)
			{
				printf("%d %d\n", i, j);
			}
			else
			{
				j--;
				continue;
			}
			j--;
		}
		i++;
	}
	return;
}