/* 1���� ��,��,��,�ʷ� ȯ���ϴ� ���α׷� */
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

	printf("%.4lf���� %d�� %d�ð� %d�� %.2f���Դϴ�.\n", dday, day, hour, min, sec);
	return 0;
}