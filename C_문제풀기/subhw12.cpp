#pragma warning(disable : 4996)
#include <stdio.h>
double input(int);
void output(double);
int main()
{
	double height = 0;
	int i = 1;
	while (i <= 5)
	{
		height += input(i);
		i++;
	}
	output(height);
	return 0;
}
double input(int i)
{
	double n;
	while (1)
	{
		printf("%d�� �л���Ű��? ",i);
		if (scanf("%lf", &n) == 1)
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

void output(double h)
{
	double mean;
	mean = h / 5.0;
	printf("�ټ����� ��� Ű�� %.1lfcm�Դϴ�.\n", mean);
}