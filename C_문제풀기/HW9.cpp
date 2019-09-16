/* 날 수를 입력 받아 그 값을 주와 날수로 변환하는 프로그램 */
#include <stdio.h>
int input(int a);
void output(int a);

int main()
{
	int day = 0;
	printf("날수를 입력하시오 :");
	day = input(day);
	output(day);
	return 0;
}

int input(int d)
{
	scanf_s("%d", &d);
	return d;
}

void output(int d)
{
	int week = 0;
	int dday = 0;
	week = d / 7;
	dday = d - (week * 7);
	printf("%d일은 %d주 %d일 입니다.\n", d, week, dday);
}