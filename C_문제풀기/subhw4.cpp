/* 화씨온도를 섭씨온도로 계산하여 출력하는 프로그램 */
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
	printf("화씨 온도를 입력하세요 :");
	scanf("%d", &f);
	return f;
}

void output(int f)
{
	double c = 0.0;
	c = 5.0 / 9 * (f - 32);
	printf("섭씨 온도는 %.1lf도 입니다\n", c);
}

