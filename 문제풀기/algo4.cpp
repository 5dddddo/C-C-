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
		printf("���� �Է� : ");
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
	printf("��� ��� :");
	while (d <= n)
	{
		if ((n%d) == 0)
		{
			printf(" %d", d);
			count++;
		}
		d++;
	}
	printf("\n��� ���� : %d\n", count);
	return;
}