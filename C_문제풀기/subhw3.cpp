/* �� ������ ������ ������ ����� �����ִ� ���α׷� */
#pragma warning(disable : 4996)
#include <stdio.h>
void output(int,double);
int main()
{	
	double mean = 0.0;
	int sub1, sub2, sub3, sum = 0;
	
	printf("����, ����, ���� ������ �Է��ϼ��� :");
	scanf("%d", &sub1);
	scanf("%d", &sub2);
	scanf("%d", &sub3);
	sum = sub1 + sub2 + sub3;
	mean = (sub1 + sub2 + sub3) / 3.0;
	output(sum,mean);
	return 0;
}

void output(int s, double m)
{
	printf("������ %d�̰� ����� %lf�Դϴ�.\n", s, m);
}