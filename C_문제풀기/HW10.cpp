/* 성명을 영문으로 입력 받아 출력하는 프로그램 */
#include <stdio.h>
#include <string.h>
int main()
{
	char name[20];
	int a = 0;
	printf("이름을 입력하세요 :");
	gets_s(name);
	a = strlen(name) * 1.5;

	printf("\"%s\"\n", name);
	printf("\"% *s\"\n", a, name);
	printf("\"%-*s\"\n", a, name);
	return 0;
}