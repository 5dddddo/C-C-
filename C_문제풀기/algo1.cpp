/* 강의시간 15분전 시간을 출력해주는 프로그램 */
#pragma warning(disable : 4996)
#include <stdio.h>
void output(int, int);
int main()
{
	int hour, min;
	printf("강의시간(hh mm) :");
	scanf("%d", &hour);
	scanf("%d", &min);

	if (min >= 00 && min < 15)
	{
		min = 60 - (15 - min);
		if (hour == 00)
		{
			hour = 23;
		}
		else
		{
			hour = hour - 1;
		}
	}
	else if (min >= 15 && min <= 59)
	{
		min = min - 15;
	}
	output(hour, min);
	return 0;
}

void output(int hour, int min)
{
	printf("입실시간 : %.2d시 %.2d분\n", hour, min);
}