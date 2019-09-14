#pragma warning(disable : 4996)
#include <stdio.h>
int inputInt(char *);
double inputDouble(char *);
int calcInt(int, int);
double calcDouble(double, int);
void outputInt(int, int, int);
void outputDouble(double, int, double);
int main()
{
	int iNum, eNum, eDou, res1;
	double iDou, res2;
	iNum = inputInt("정수형 밑을 입력 하시오 :");
	eNum = inputInt("지수승을 입력하시오(정수형) :");
	res1 = calcInt(iNum, eNum);
	outputInt(iNum, eNum, res1);

	iDou = inputDouble("실수형 밑을 입력 하시오 :");
	eDou = inputInt("지수승을 입력하시오(정수형) :");
	res2 = calcDouble(iDou, eDou);
	outputDouble(iDou, eDou, res2);
	return 0;
}

int inputInt(char * m)
{
	int n;
	while (1)
	{
		printf(m);
		if (scanf("%d", &n) == 1)
		{
			if (getchar() == '\n')
			{
				if (n >= 0)
				{
					return n;
				}
				else
				{
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
			fflush(stdin);
		}

	}
}

double inputDouble(char * m)
{
	double n;
	while (1)
	{
		printf(m);
		if (scanf("%lf", &n) == 1)
		{
			if (n >= 0)
			{
				return n;
			}
			else
			{
				fflush(stdin);
			}
		}
		else
		{
			fflush(stdin);
		}
	}
}

int calcInt(int i, int e)
{
	int j = 1, num = 1;
	if (i > 0)
	{
		while (j <= e)
		{
			num *= i;
			j++;
		}
	}
	else if (i == 0)
	{
		num = 0;
	}
	return num;
}

double calcDouble(double i, int e)
{
	int j = 1;
	double num = 1;
	if (i > 0)
	{
		while (j <= e)
		{
			num *= i;
			j++;
		}
	}
	else if (i == 0)
	{
		num = 0;
	}
	return num;
}

void outputInt(int i, int e, int r)
{
	printf("%d의 %d승은 %d입니다.\n", i, e, r);
}

void outputDouble(double i, int e, double r)
{
	printf("%lf의 %d승은 %.2lf입니다.\n", i, e, r);
}
