#include <stdio.h>
void printf_age(int a);
void printf_height(double h);
int main()
{
	char name[8] ="OhEunAe";
	int age = 22;
	double height = 161.3;
	printf("이름 : %s\n", name);
	printf_age(age);
	printf_height(height);
	return 0;
}

void printf_age(int a)
{
	printf("나이 : %d살\n", a);
}

void printf_height(double h)
{
	printf("키 : %lfcm\n", h);
}