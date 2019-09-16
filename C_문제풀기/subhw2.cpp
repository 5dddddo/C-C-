/* 전기 사용량을 kw단위로 입력하면 사용 요금을 계산해주는 프로그램 */
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
	printf("전기 사용량을 입력하세요(kw) :");
	scanf("%d", &f);
	return f;
}

void output(int f)
{
	double charge = 0.0;
	double money = 0.0;
	charge = 660 + (f * 88.5);
	money = charge + charge * 0.09;
	printf("전기 사용요금은 %lf원입니다\n", money);

}