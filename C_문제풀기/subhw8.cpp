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
	printf("레저카를 사용한 거리를 KM 단위로 입력하세요 :");
	scanf("%d", &n);
	return n;
}

int inputMoney()
{
	int m;
	printf("이용료 정산을 위해 지불한 금액을 원단위로 입력하세요 : ");
	scanf("%d", &m);
	return m;
}

void outputFee(int f)
{
	printf("총 이용료 : %d원\n", f);
	return;
}
void outputChange(int c)
{
	printf("거스름돈 : %d원\n", c);
	return;
}