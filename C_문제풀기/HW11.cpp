/* ���� �̸��� �Է� �޾� �Էµ� �̸��� ����ϰ� ���� ���ο� ���� �̸��� ���� ���� ���� ���� �̸� ���ڸ��� ���߾� ����ϴ� ���α׷� */
#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
int main()
{
	char last[10];
	char name[20];
	int a,b;
	printf("���� �Է��ϼ��� :");
	scanf("%s", last);
	a = strlen(last);
	printf("�̸��� �Է��ϼ��� :");
	scanf("%s", name);
	b = strlen(name);

	printf("%s %s\n", last, name);
	printf("%*d %*d\n", a, a, b, b);

	return 0;

}