#include <stdio.h>
void printf_age(int a);
void printf_height(double h);
int main()
{
	char name[8] ="OhEunAe";
	int age = 22;
	double height = 161.3;
	printf("�̸� : %s\n", name);
	printf_age(age);
	printf_height(height);
	return 0;
}

void printf_age(int a)
{
	printf("���� : %d��\n", a);
}

void printf_height(double h)
{
	printf("Ű : %lfcm\n", h);
}