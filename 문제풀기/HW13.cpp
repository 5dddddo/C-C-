/* ����,��� ���α׷� */
#pragma warning(disable : 4996)
#include <stdio.h>
int input(int);
int yearcheck(int);
void output(int,int);

int main()
{
	int year = 0;
	int check = 0;
	year = input(year);
	check = yearcheck(year);
	output(year,check);
	return 0;
}

int input(int y)
{
	printf("�⵵�� �Է��ϼ��� :");
	scanf("%d", &y);
	return y;
}

int yearcheck(int y)
{
	if ((y % 4) == 0)
	{
		if ((y % 100) == 0)
		{
			if ((y % 400) == 0)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}

void output(int y, int c)
{
	if (c == 1)
	{
		printf("%d���� ����(Leap year)�Դϴ�.\n", y);
	}
	else
	{
		printf("%d���� ���(Common year)�Դϴ�.\n", y);
	}
}