/* ���� ��뷮�� kw������ �Է��ϸ� ��� ����� ������ִ� ���α׷� */
#pragma warning(disable : 4996)
#include <stdio.h>
int input(int);
void output(int);

int main()
{
	int fee = 0;
	fee = input(fee);
	output(fee);
	return 0;
}

int input(int f)
{
	printf("���� ��뷮�� �Է��ϼ���(kw) :");
	scanf("%d", &f);
	return f;
}

void output(int f)
{
	double charge = 0.0;
	double money = 0.0;
	charge = 660 + (f * 88.5);
	money = charge + charge * 0.09;
	printf("���� ������� %lf���Դϴ�\n", money);

}