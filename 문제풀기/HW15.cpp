#pragma warning(disable : 4996)
#include <stdio.h>
int input(char *);
int totalIncome(int);
int calcTax(int);
void output(int, int);
int main()
{
	int hour, money, fee;
	
	while (1)
	{
		hour = input("1주일간의 근무시간을 입력하시오 :");
		if (hour < 0)
		{
			break;
		}
		money = totalIncome(hour);
		fee = calcTax(money);
		output(money, fee);
	}
	return 0;
}

int input(char * message)
{
	int hour;
	
	while (1)
	{
		printf(message);
		if (scanf("%d", &hour) == 1)
		{
			if (getchar() == '\n')
			{
				if (hour >= 0)
				{
					return hour;
				}
				else
				{
					return -1;
				}
			}
		}
		else
		{
			printf("Input Error!\n");
			fflush(stdin);
		}
	}
}

int totalIncome(int hour)
{
	int money;
	if (hour >= 40)
	{
		money = 40 * 3000 + (hour - 40) * 3000 * 15 / 10;
	}
	else
	{
		money = hour * 3000;
	}
	return money;
}

int calcTax(int money)
{
	int fee;
	if (money <= 100000)
	{
		fee = money * 15 / 100;
	}
	else
	{
		fee = 100000 * 15 / 100 + (money - 100000) * 25 / 100;
	}
	return fee;
}

void output(int money, int fee)
{
	int income;
	income = money - fee;
	printf("# 총수입 : %d원\n", money);
	printf("# 세  금 : %d원\n", fee);
	printf("# 실수입 : %d원\n", income);

}