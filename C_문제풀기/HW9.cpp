/* �� ���� �Է� �޾� �� ���� �ֿ� ������ ��ȯ�ϴ� ���α׷� */
#include <stdio.h>
int input(int a);
void output(int a);

int main()
{
	int day = 0;
	printf("������ �Է��Ͻÿ� :");
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
	printf("%d���� %d�� %d�� �Դϴ�.\n", d, week, dday);
}