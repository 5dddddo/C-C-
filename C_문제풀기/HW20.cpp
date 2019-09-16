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
	printf("* 사용자 코드를 입력하시오(1:가정용/ 2:상업용/ 3:공업용/ 4:종료) : ");
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
					printf("다시 입력하세요 : ");
					fflush(stdin);
				}
			}
			else
			{
				printf("다시 입력하세요 : ");
				fflush(stdin);
			}
		}
		else
		{
			printf("다시 입력하세요 : ");
			fflush(stdin);
		}
	}
	
}

int input()
{
	int a;
	printf("* 사용량을 입력하시오(ton단위) : ");
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
			printf("다시 입력하세요 : ");
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
	case 1: printf("* 사용자코드: 1(가정용)\n"); break;
	case 2: printf("* 사용자코드: 2(상업용)\n"); break;
	case 3: printf("* 사용자코드: 3(공업용)\n"); break;
	}
	printf("* 사용량 : %dton\n", a);
	printf("* 총수도요금 : %d원\n", m);
}