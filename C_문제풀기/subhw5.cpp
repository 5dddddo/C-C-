/* cm������ �Է¹޾� M������ cm������ ȯ���ϴ� ���α׷� */
#pragma warning(disable : 4996)
#include <stdio.h>
int input(int); 
void output(int);

int main()
{
	int height = 0;
	height = input(height);
	output(height);
	return 0;
}

int input(int h)
{
	printf("cm������ �Է��ϼ��� :");
	scanf("%d", &h);
	return h;
}

void output(int h)
{
	int m, c = 0;
	m = h / 100;
	c = h - m * 100;
	printf("%dcm => %dM %dcm\n", h, m, c);
}