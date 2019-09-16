#pragma warning(disable : 4996)
#include <stdio.h>
int menu();
int income(int);
int withdraw(int);

int main()
{
	int money = 0;
	char c = 0;
 
	printf("현재 잔액은 0원입니다.\n");
	while (1)
	{	
		c = menu();
		if (c == 'i')
		{
			money = income(money);
		}
		else if (c == 'o')
		{	
			money = withdraw(money);
			
		}
		else if (c == 'q')
		{
			break;
		}
		else
		{
			printf("잘못 입력하셨습니다.\n");
			fflush(stdin);
		}
	}
}

int menu()
{
	char c;
	while (1)
	{
		printf("# 메뉴를 선택하시오(i-입금, o-출금, q-종료) : ");
		if (scanf("%c", &c) == 1)
		{
			if (c >= '48' && c <= '57')
			{
				fflush(stdin);
			}
			else
			{
				break;
			}
		}
		else 
		{
			fflush(stdin);
		}
	}
	return c;
}

int income(int money)
{
	int m = 0;
	printf("# 입금액을 입력하세요 : ");
	while (1)
	{
		if (scanf("%d", &m) == 1)
		{
			if (getchar() == '\n')
			{
				if (m > 0)
				{
					money += m;
					printf("현재 잔액은 %d원 입니다.\n", money);
					return money;
				}
				else
				{
					printf("잘못 입력하셨습니다. 다시 입력하십시오1 : ");
					fflush(stdin);
				}
			}
			else
			{
				fflush(stdin);
			}
		}
		else
		{
			printf("잘못 입력하셨습니다. 다시 입력하십시오2 : ");
			fflush(stdin);
		}
	}

}

int withdraw(int money)
{
	int m = 0;
	printf("# 출금액을 입력하세요 : ");
	while (1)
	{
		if (scanf("%d", &m) == 1)
		{
			if (getchar() == '\n')
			{
				if (m > 0)
				{
					if (money >= m)
					{
						money -= m;
						printf("현재 잔액은 %d원 입니다.\n", money);
						return money;
					}
					else
					{
						printf("잔액이 부족합니다.\n");
						printf("현재 잔액은 %d원 입니다.\n", money);
						return money;
					}
				}
				else
				{
					printf("잘못 입력하셨습니다. 다시 입력하십시오 : ");
					fflush(stdin);
				}
			}
			else
			{
				fflush(stdin);
			}
		}
		else
		{
			printf("잘못 입력하셨습니다. 다시 입력하십시오 : ");
			fflush(stdin);
		}
	}
}
