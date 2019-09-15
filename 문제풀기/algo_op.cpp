/* 강의시간 15분 후를 출력하는 프로그램 */
#pragma warning(disable : 4996)
#include <stdio.h>
void output(int, int);
int main()
{
	int hour, min;
	printf("강의시간(hh mm) :");
	scanf("%d", &hour);
	scanf("%d", &min);

	if (min >= 45 && min < 60)
	{
		min = (min + 15) - 60;
		if (hour == 23)
		{
			hour = 00;
		}
		else
		{
			hour = hour + 1;
		}
	}
	else if (min >= 00 && min <= 44)
	{
		min = min + 15;
	}
	output(hour, min);
	return 0;
}

void output(int hour, int min)
{
	printf("입실시간 : %.2d시 %.2d분\n", hour, min);
}