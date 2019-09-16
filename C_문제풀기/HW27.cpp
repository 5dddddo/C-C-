#pragma warning (disable : 4996)
#include <stdio.h> 
int input();
int primeNumber(int);
int main()
{
	int i, j = 0, num, count = 0;
	num = input();
	printf("1~%d까지의 소수값은 다음과 같습니다.\n", num);
	for (i = 0; i <= num; i++)
	{
		if (primeNumber(i))
		{
			printf("%d	", i);
			count++;
			j++;
			if (count == 5)
			{
				printf("\n");
				count = 0;
			}
		}
	}
	printf("\n");
	printf("1~%d까지의 총 소수는 %d개 입니다.\n",num,j);
	
	return 0;
}

int input()
{
	int n;
	while (1)
	{
		printf("* 정수값 하나를 입력하시오: ");
		if (scanf("%d", &n) == 1)
		{
			if (getchar() == '\n')
			{
				if (n > 0)
				{
					break;
				}
			}
		}
		else
		{
			printf("다시입력하시오.\n");
			fflush(stdin);
		}
	}
	return n;
}

int primeNumber(int num)
{
	int i;
	for (i = 2; i < num && num % i; i++);
	if (i == num)
	{
		return 1;
	}
	else
	{
		return 0;
	}
 }