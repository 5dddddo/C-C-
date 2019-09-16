/* 성과 이름을 입력 받아 입력된 이름을 출력하고 다음 라인에 성과 이름의 글자 수를 각각 성과 이름 뒷자리에 맞추어 출력하는 프로그램 */
#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
int main()
{
	char last[10];
	char name[20];
	int a,b;
	printf("성을 입력하세요 :");
	scanf("%s", last);
	a = strlen(last);
	printf("이름을 입력하세요 :");
	scanf("%s", name);
	b = strlen(name);

	printf("%s %s\n", last, name);
	printf("%*d %*d\n", a, a, b, b);

	return 0;

}