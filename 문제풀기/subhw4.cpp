/* ȭ���µ��� �����µ��� ����Ͽ� ����ϴ� ���α׷� */
#pragma warning(disable : 4996)
#include <stdio.h>
int input(int);
void output(int);

int main()
{
	int f = 0;
	f = input(f);
	output(f);
	return 0;
}

int input(int f)
{
	printf("ȭ�� �µ��� �Է��ϼ��� :");
	scanf("%d", &f);
	return f;
}

void output(int f)
{
	double c = 0.0;
	c = 5.0 / 9 * (f - 32);
	printf("���� �µ��� %.1lf�� �Դϴ�\n", c);
}

