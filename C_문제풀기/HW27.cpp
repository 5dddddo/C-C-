#pragma warning (disable : 4996)
#include <stdio.h> 
int input();
int primeNumber(int);
int main()
{
	int i, j = 0, num, count = 0;
	num = input();
	printf("1~%d������ �Ҽ����� ������ �����ϴ�.\n", num);
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
	printf("1~%d������ �� �Ҽ��� %d�� �Դϴ�.\n",num,j);
	
	return 0;
}

int input()
{
	int n;
	while (1)
	{
		printf("* ������ �ϳ��� �Է��Ͻÿ�: ");
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
			printf("�ٽ��Է��Ͻÿ�.\n");
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