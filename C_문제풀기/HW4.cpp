/* 1년을 일,시,분,초로 환산하는 프로그램 */
#include <stdio.h>
int main()
{
	double dday = 365.2422;
	int day, hour, min;
	double sec, res1, res2;
	
	day = (int)dday;
	res1 = (dday - day) * 24;
	hour = (int)res1;
	res2 = (res1 - hour) * 60;
	min = (int)res2;
	sec = (res2 - min) * 60;

	printf("%.4lf일은 %d일 %d시간 %d분 %.2f초입니다.\n", dday, day, hour, min, sec);
	return 0;
}