/* ���ǽð� 15�� �ĸ� ����ϴ� ���α׷� */
#pragma warning(disable : 4996)
#include <stdio.h>
void output(int, int);
int main()
{
	int hour, min;
	printf("���ǽð�(hh mm) :");
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
	printf("�Խǽð� : %.2d�� %.2d��\n", hour, min);
}