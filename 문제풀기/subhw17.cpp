#pragma warning(disable : 4996)
#include <stdio.h>
int menu();
int income(int);
int withdraw(int);

int main()
{
	int money = 0;
	char c = 0;
 
	printf("���� �ܾ��� 0���Դϴ�.\n");
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
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			fflush(stdin);
		}
	}
}

int menu()
{
	char c;
	while (1)
	{
		printf("# �޴��� �����Ͻÿ�(i-�Ա�, o-���, q-����) : ");
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
	printf("# �Աݾ��� �Է��ϼ��� : ");
	while (1)
	{
		if (scanf("%d", &m) == 1)
		{
			if (getchar() == '\n')
			{
				if (m > 0)
				{
					money += m;
					printf("���� �ܾ��� %d�� �Դϴ�.\n", money);
					return money;
				}
				else
				{
					printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ�1 : ");
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
			printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ�2 : ");
			fflush(stdin);
		}
	}

}

int withdraw(int money)
{
	int m = 0;
	printf("# ��ݾ��� �Է��ϼ��� : ");
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
						printf("���� �ܾ��� %d�� �Դϴ�.\n", money);
						return money;
					}
					else
					{
						printf("�ܾ��� �����մϴ�.\n");
						printf("���� �ܾ��� %d�� �Դϴ�.\n", money);
						return money;
					}
				}
				else
				{
					printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");
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
			printf("�߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : ");
			fflush(stdin);
		}
	}
}
