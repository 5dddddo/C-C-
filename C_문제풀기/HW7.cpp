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
	printf("�� ���� ������ �Է��Ͻÿ� : \n");
	scanf_s("%d", &a);
	return a;
}

int output_n(int a)
{
	printf("%d�� 2��� => %d\n", a, a * 2);
	printf("%d�� ���� => %d\n", a, a * a);
	return 0;
}