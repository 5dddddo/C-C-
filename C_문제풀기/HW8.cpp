/* ASCII code���� �Է� �޾� ASCII code�� �ش��ϴ� ���ڸ� ����ϴ� ���α׷� */
#include <stdio.h>
int input(int a);
void output(int a);

int main()
{
	int a = 0;
	printf("ASCII code���� �Է��Ͻÿ� :");
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
	printf("%d�� '%c'�� ASCII code �Դϴ�.\n", a, a);
}
