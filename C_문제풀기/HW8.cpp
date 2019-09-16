/* ASCII code값을 입력 받아 ASCII code에 해당하는 문자를 출력하는 프로그램 */
#include <stdio.h>
int input(int a);
void output(int a);

int main()
{
	int a = 0;
	printf("ASCII code값을 입력하시오 :");
	a = input(a);
	output(a);
	return 0;
}

int input(int a)
{
	scanf_s("%d", &a);
	return a;
}

void output(int a)
{
	printf("%d은 '%c'의 ASCII code 입니다.\n", a, a);
}
