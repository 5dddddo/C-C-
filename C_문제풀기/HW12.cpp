/* 문자열을 입력받아 문자열을 앞에서부터 반만 출력하는 프로그램 */
#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
int main()
{
	char name[20];
	int a, b;
	printf("문자를 입력하시오 :");
	scanf("%s", name);
	a = strlen(name) ;
	b = a / 2;
	printf("[%*.*s...]\n", a, b, name);
	return 0;
}