/* 주행거리와 시속을 입력받아 주행시간을 계산하는 프로그램 */
#include <stdio.h>
double input_d(double d);
double input_s(double s);
void output(double d, double s);

int main()
{
	double dis = 0, speed = 0;
	printf("거리를 입력하세요(km단위) :");
	dis = input_d(dis);
	printf("시속을 입력하세요(km/h단위) :"); 
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
	printf("%.3lfkm => %d시간 %d분 %.3lf초 소요됨\n", d, hour, min, sec);
}