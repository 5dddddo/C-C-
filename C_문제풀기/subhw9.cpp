#pragma warning(disable : 4996)
#include <stdio.h>
int inputintNum();
int inputUnit();
void output(int, int, int);

int main()
{
	int num, unit, set, res;
	num = inputintNum();
	unit = inputUnit();
	set = num / unit;
	res = num - (unit * set);
	output(unit, set, res);
	return 0;
}

int inputintNum()
{
	int n;
	printf("���� ����� ��� ������ ���� :");
	scanf("%d", &n);
	return n;
}

int inputUnit()
{
	int u;
	printf("���� ��û�� ���� ���� : ");
	scanf("%d", &u);
	return u;
}

void output(int u, int s, int r)
{
	printf("���� ����� ��� ������ %d�� ������ �����ϸ� �� %d���� ������ ����� %d���� ������ ������ �����ϴ�.\n", u, s, r);
	return;
}