/* ���ڿ��� �Է¹޾� ���ڿ��� �տ������� �ݸ� ����ϴ� ���α׷� */
#pragma warning(disable : 4996)
#include <stdio.h>
#include <string.h>
int main()
{
	char name[20];
	int a, b;
	printf("���ڸ� �Է��Ͻÿ� :");
	scanf("%s", name);
	a = strlen(name) ;
	b = a / 2;
	printf("[%*.*s...]\n", a, b, name);
	return 0;
}