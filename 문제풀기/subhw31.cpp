#pragma warning (disable : 4996)
#include <stdio.h>
double input(int);
double maximum(double *);
double minimum(double *);
void output(double,double);
int main()
{
	double str[10], max, min;
	int i;
	for (i = 0; i < 5; i++)
	{
		str[i] = input(i);
	}
	max = maximum(str);
	min = minimum(str);
	output(max, min);
	return 0;
}

double input(int i)
{
	double num;
	while (1)
	{
		printf("%d번 방 값 : ", i);
		if (scanf("%lf", &num) == 1)
		{
			break;
		}
		else
		{
			fflush(stdin);
		}
	}
	return num;
}

double maximum(double *dp)
{
	double max;
	int i;
	max = *dp;
	for (i = 1; i < 5; i++)
	{
		if (max < *(dp+i))
		{
			max = *(dp +i);
		}
	}
	return max;
}

double minimum(double *dp)
{
	double min;
	int i;
	min = *dp;
	for (i = 1; i < 5; i++)
	{
		if (min > *(dp + i))
		{
			min = *(dp + i);
		}
	}
	return min;
}

void output(double max, double min)
{
	printf("가장 큰 값 : %.2lf\n", max);
	printf("가장 작은 값 : %.2lf\n", min);
}