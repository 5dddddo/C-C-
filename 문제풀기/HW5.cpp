/* �� ������ �Է¹޾� ��,��,��,���� ���� ����ϴ� ���α׷� */
#include <stdio.h>
int main()
{
	int a = 0, b = 0;
	printf("�ΰ��� ������ �Է��Ͻÿ� :\n", a, b);
	scanf_s("%d %d", &a, &b);
	printf("%d + %d = %d\n", a, b, a + b);
	printf("%d - %d = %d\n", a, b, a - b);
	printf("%d * %d = %d\n", a, b, a * b);
	printf("%.2lf / %d = %.2lf\n", (double)a, b, (double)a / b);
	return 0;
}
