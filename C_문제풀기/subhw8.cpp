#pragma warning(disable : 4996)
#include <stdio.h>
int inputintNum();
int inputMoney();
void outputFee(int);
void outputChange(int);


int main()
{
	int num, fee, money, change;
	num = inputintNum();
	fee = 500 * num*1.1;
	outputFee(fee);
	money = inputMoney();
	change = money - fee;
	outputChange(change);
	return 0;
}

int inputintNum()
{
	int n;
	printf("����ī�� ����� �Ÿ��� KM ������ �Է��ϼ��� :");
	scanf("%d", &n);
	return n;
}

int inputMoney()
{
	int m;
	printf("�̿�� ������ ���� ������ �ݾ��� �������� �Է��ϼ��� : ");
	scanf("%d", &m);
	return m;
}

void outputFee(int f)
{
	printf("�� �̿�� : %d��\n", f);
	return;
}
void outputChange(int c)
{
	printf("�Ž����� : %d��\n", c);
	return;
}