/* ����Ÿ��� �ü��� �Է¹޾� ����ð��� ����ϴ� ���α׷� */
#include <stdio.h>
double input_d(double d);
double input_s(double s);
void output(double d, double s);

int main()
{
	double dis = 0, speed = 0;
	printf("�Ÿ��� �Է��ϼ���(km����) :");
	dis = input_d(dis);
	printf("�ü��� �Է��ϼ���(km/h����) :"); 
	speed = input_s(speed);
	output(dis,speed);
	return 0;
}

double input_d(double d)
{
	scanf_s("%lf", &d);
	return d;
}

double input_s(double s)
{
	scanf_s("%lf", &s);
	return s;
}

void output(double d, double s)
{
	int hour, min;
	double sec;
	hour = d / s;
	min = (d / s - hour) * 60;
	sec = ((d / s - hour) * 60 - min) * 60;
	printf("%.3lfkm => %d�ð� %d�� %.3lf�� �ҿ��\n", d, hour, min, sec);
}