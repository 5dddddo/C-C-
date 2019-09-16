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
	printf("오늘 생산된 노란 고무줄의 수량 :");
	scanf("%d", &n);
	return n;
}

int inputUnit()
{
	int u;
	printf("고객이 요청한 묶음 단위 : ");
	scanf("%d", &u);
	return u;
}

void output(int u, int s, int r)
{
	printf("오늘 생산된 노란 고무줄을 %d개 단위로 포장하면 총 %d개의 묶음을 만들고 %d개의 고무줄이 낱개로 남습니다.\n", u, s, r);
	return;
}