#include <stdio.h>
int input_n(int a);
int output_n(int a);
int main()
{
	int num = 3;
	input_n(num);
	output_n(num);
	return 0;
}

int input_n(int a)
{
	printf("한 개의 정수를 입력하시오 : \n");
	scanf_s("%d", &a);
	return a;
}

int output_n(int a)
{
	printf("%d의 2배수 => %d\n", a, a * 2);
	printf("%d의 제곱 => %d\n", a, a * a);
	return 0;
}