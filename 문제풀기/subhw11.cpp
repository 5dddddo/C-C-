#pragma warning(disable : 4996)
#include <stdio.h>
int input(char *);
int calcMoney(int,int);
void output(int,int);
int main()
{
	int age,num,money;
	age = input("입장객의 나이를 입력하시오 :");
	num = input("입장객의 수를 입력하시오 :");
	money = calcMoney(age, num);
	printf("%d\n", money);
	output(num, money);
	return 0;
}

int input(char *m)
{
	int n;
	while (1)
	{
		printf(m);
		if (scanf("%d", &n) == 1)
		{
		
			if (n >= 0)
			{
				break;
			}
		}
		else
		{
			fflush(stdin);
		}
	}
	return n;
}

int calcMoney(int a, int n)
{
	int money;
	if (a <= 7)
	{
		money = n * 500;
	}
	else if (a >= 8 && a <= 13)
	{
		money = n * 700;
	}
	else if (a >= 14 && a <= 19)
	{
		money = n * 1000;
	}
	else if (a >= 20 && a <= 55)
	{
		money = n * 1500;

	}
	else if (a >= 56)
	{
		money = 500 * n;
	}

	return money;
}

void output(int n,int m)
{
	int discount;
	printf("입장료 =>  %d원\n", m);
	if (n >= 5)
	{
		discount = m * 1 / 10;
	}
	else
	{
		discount = 0;
	}
	printf("할인금액 => %d원\n", discount);
	printf("결제금액 => %d원\n", m - discount);
}

