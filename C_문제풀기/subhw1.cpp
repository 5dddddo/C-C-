/* 8������ 16������ ����ϴ� ���α׷� */
#pragma warning(disable : 4996)
#include <stdio.h>
int input(int n);
void output(int n);
int main()
{
	int num = 0;
	printf("�������� �Է��ϼ��� :");
	num = input(num);
	output(num);
	return 0;

}

int input(int n)
{
	scanf("%d", &n);
	return n;
}

void output(int n)
{
	printf("�Էµ� ���� 8������ %#o�Դϴ�.\n", n);
	printf("�Էµ� ���� 16������ %#x�Դϴ�.\n", n);
}