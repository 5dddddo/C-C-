#pragma warning (disable : 4996)
#include <stdio.h>
int menu();
int input();
int calcmoney(int,int);
void output(int,int,int);

int main()
{
	int money, num, amount;
	while (1)
	{
		num = menu();
		if (num == 4)
		{
			break;
		}
		amount = input();
		money = calcmoney(num,amount);
		output(num,amount,money);
	}
	return 0;
}

int menu()
{
	int n;
	printf("* ����� �ڵ带 �Է��Ͻÿ�(1:������/ 2:�����/ 3:������/ 4:����) : ");
	while (1)
	{
		if (scanf("%d", &n) == 1)
		{
			if (getchar() == '\n')
			{
				if (n >= 1 && n <= 4)
				{
					return n;
				}
				else
				{
					printf("�ٽ� �Է��ϼ��� : ");
					fflush(stdin);
				}
			}
			else
			{
				printf("�ٽ� �Է��ϼ��� : ");
				fflush(stdin);
			}
		}
		else
		{
			printf("�ٽ� �Է��ϼ��� : ");
			fflush(stdin);
		}
	}
	
}

int input()
{
	int a;
	printf("* ��뷮�� �Է��Ͻÿ�(ton����) : ");
	while (1)
	{
		if (scanf("%d", &a) == 1)
		{
			if (getchar() == '\n')
			{
				if (a > 0)
				{
					break;
				}
			}
		}
		else
		{ 
			printf("�ٽ� �Է��ϼ��� : ");
			fflush(stdin);
		}
	}
	return a;
}

int calcmoney(int n, int a)
{
	int money;
	switch (n)
	{
	case 1:money = a * 50 + a * 50 * 5 / 100; break;
	case 2:money = a * 45 + a * 45 * 5 / 100; break;
	case 3:money = a * 30 + a * 30 * 5 / 100; break;
	case 4:break;
	}
	return money;
}

void output(int n, int a, int m)
{
	switch (n)
	{
	case 1: printf("* ������ڵ�: 1(������)\n"); break;
	case 2: printf("* ������ڵ�: 2(�����)\n"); break;
	case 3: printf("* ������ڵ�: 3(������)\n"); break;
	}
	printf("* ��뷮 : %dton\n", a);
	printf("* �Ѽ������ : %d��\n", m);
}