/* 윤년,평년 프로그램 */
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
	printf("년도를 입력하세요 :");
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
		printf("%d년은 윤년(Leap year)입니다.\n", y);
	}
	else
	{
		printf("%d년은 평년(Common year)입니다.\n", y);
	}
}