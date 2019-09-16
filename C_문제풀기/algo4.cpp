#pragma warning(disable : 4996)
#include <stdio.h>
int inputInt();
void findDivisor(int);
int main()
{
	int num;
	num = inputInt();
	findDivisor(num);
	return 0;
}

int inputInt()
{
	int n;
	while (1)
	{
		printf("정수 입력 : ");
		scanf("%d", &n);
		if (getchar() == '\n')
		{
			break;
		}
		else
		{
			printf("Input Error\n");
			fflush(stdin);
		}
	}
	return n;
}

void findDivisor(int n)
{
	int count = 0;
	int d = 1;
	printf("약수 출력 :");
	while (d <= n)
	{
		if ((n%d) == 0)
		{
			printf(" %d", d);
			count++;
		}
		d++;
	}
	printf("\n약수 개수 : %d\n", count);
	return;
}