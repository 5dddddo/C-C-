/* ������ �������� �Է� �޾� ����ϴ� ���α׷� */
#include <stdio.h>
#include <string.h>
int main()
{
	char name[20];
	int a = 0;
	printf("�̸��� �Է��ϼ��� :");
	gets_s(name);
	a = strlen(name) * 1.5;

	printf("\"%s\"\n", name);
	printf("\"% *s\"\n", a, name);
	printf("\"%-*s\"\n", a, name);
	return 0;
}