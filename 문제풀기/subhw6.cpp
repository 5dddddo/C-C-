/* 신체질량지수(BMI)를 구한 후 비만도를 출력해주는 프로그램 */
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
	printf("몸무게를 입력하세요(kg) : ");
	scanf("%d", &w);
	return w;
}

double inputH(double h)
{
	printf("키를 입력하세요(m) : ");
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
		printf("당신의 BMI는 %.1lf으로 과체중입니다\n", b);
	}
	else if (b >= 30.0)
	{
		printf("당신의 BMI는 %.1lf으로 비만입니다\n", b);
	}
	else if (b >= 25.0)
	{
		printf("당신의 BMI는 %.1lf으로 과체중입니다\n", b);
	}
	else if (b >= 18.5)
	{
		printf("당신의 BMI는 %.1lf으로 정상체중입니다\n", b);
	}
	else
	{
		printf("당신의 BMI는 %.1lf으로 저체중입니다\n", b);
	}
}