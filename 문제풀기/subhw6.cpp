/* ��ü��������(BMI)�� ���� �� �񸸵��� ������ִ� ���α׷� */
#pragma warning(disable : 4996)
#include <stdio.h>
int inputW(int);
double inputH(double);
double bmi(int, double);
void output(double);

int main()
{
	int weight = 0;
	double  height = 0.0, b = 0.0;
	weight = inputW(weight);
	height = inputH(height);
	b = bmi(weight, height);
	output(b);
	return 0;

}

int inputW(int w)
{
	printf("�����Ը� �Է��ϼ���(kg) : ");
	scanf("%d", &w);
	return w;
}

double inputH(double h)
{
	printf("Ű�� �Է��ϼ���(m) : ");
	scanf("%lf", &h);
	return h;
}

double bmi(int w, double h)
{
	double b;
	b = w / (h * h);
	return b;
}

void output(double b)
{
	if (b >= 40.0)
	{
		printf("����� BMI�� %.1lf���� ��ü���Դϴ�\n", b);
	}
	else if (b >= 30.0)
	{
		printf("����� BMI�� %.1lf���� ���Դϴ�\n", b);
	}
	else if (b >= 25.0)
	{
		printf("����� BMI�� %.1lf���� ��ü���Դϴ�\n", b);
	}
	else if (b >= 18.5)
	{
		printf("����� BMI�� %.1lf���� ����ü���Դϴ�\n", b);
	}
	else
	{
		printf("����� BMI�� %.1lf���� ��ü���Դϴ�\n", b);
	}
}