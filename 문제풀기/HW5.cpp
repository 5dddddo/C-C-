/* 두 정수를 입력받아 합,차,곱,몫의 값을 출력하는 프로그램 */
#include <stdio.h>
int main()
{
	int a = 0, b = 0;
	printf("두개의 정수를 입력하시오 :\n", a, b);
	scanf_s("%d %d", &a, &b);
	printf("%d + %d = %d\n", a, b, a + b);
	printf("%d - %d = %d\n", a, b, a - b);
	printf("%d * %d = %d\n", a, b, a * b);
	printf("%.2lf / %d = %.2lf\n", (double)a, b, (double)a / b);
	return 0;
}
