/* 8진수와 16진수로 출력하는 프로그램 */
#pragma warning(disable : 4996)
#include <stdio.h>
int input(int n);
void output(int n);
int main()
{
	int num = 0;
	printf("정수값을 입력하세요 :");
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
	printf("입력된 값은 8진수로 %#o입니다.\n", n);
	printf("입력된 값은 16진수로 %#x입니다.\n", n);
}