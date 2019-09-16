/* 윤년,평년 프로그램 */
#pragma warning(disable : 4996)
#include <stdio.h>
int input(int *, int *, int *,char *);
void datecheck(int *, int);
int sumdate(int, int, int);
void output(int, int, int, int);

int main()
{
	int y, m, d, total;
	char ch;
	
	while (1)
	{
		if (input(&y, &m, &d,&ch) == -1)
		{
			break;
		}
		datecheck(month, y);
		total = sumdate(y, m, d);
		output(total, y, m, d);
	}
	return 0;
}

int input(int *y, int *m, int *d, char *ch)
{
	while (1)
	{
		printf("* 년월일을 입력하시오 : ");
		if (scanf("%d %d %d", y, m, d) == 3)
		{
			if ((*ch = getchar()) == '\n' && *y > 0 && (*m >= 1 && *m <= 12) && *d > 0)
			{
				if (*m == 1 || *m == 3 || *m == 5 || *m == 7 || *m == 8 || *m == 10 || *m == 12)
				{
					if (*d <= 31)
						break;
				}
				else if (*m == 4 || *m == 6 || *m == 9 || *m == 11)
				{
					if (*d <= 30)
						break;
				}
				else
				{
					if (((*y % 4 == 0) && (*y % 100 != 0) || (*y % 400 == 0)) == 1)
					{
						if (*d <= 29)
							break;
					}
					else
					{
						if (*d <= 28)
						break;
					}
				}
			}
			else
			{
				fflush(stdin);
			}
		}
		else
		{
			return -1;
		}
	}
	return 0;
}

void datecheck(int *month,int y)
{
	if (((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0)) == 1)
	{
		month[1] = 29;
	}
}

int sumdate(int y, int m, int d)
{
	int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int total = 0;

	tdtal = (y - 1) * 365 + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;
	for (yeardate = 1; yeardate < y; yeardate++)
	{
		if (((yeardate % 4 == 0) && (yeardate % 100 != 0) || (yeardate % 400 == 0)) == 1)
		{
			yearsum += 366;
		}
		else
		{
			yearsum += 365;
		}
	}
	for (monthdate = 0; monthdate < m - 1; monthdate++)
	{
		monthsum += month[monthdate];
	}
	total = yearsum + monthsum + d;
	return total;
}

void output(int total,int y,int m,int d)
{
	int res ;
	res = total % 7;
	switch (res)
	{
	case 0: printf("%d년 %d월 %d일은 일요일입니다.\n", y, m, d); break;
	case 1: printf("%d년 %d월 %d일은 월요일입니다.\n", y, m, d); break;
	case 2: printf("%d년 %d월 %d일은 화요일입니다.\n", y, m, d); break;
	case 3: printf("%d년 %d월 %d일은 수요일입니다.\n", y, m, d); break;
	case 4: printf("%d년 %d월 %d일은 목요일입니다.\n", y, m, d); break;
	case 5: printf("%d년 %d월 %d일은 금요일입니다.\n", y, m, d); break;
	default: printf("%d년 %d월 %d일은 토요일입니다.\n", y, m, d); break;
	}
}