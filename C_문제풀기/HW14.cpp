/* Family ���α׷� */
#pragma warning(disable : 4996)
#include <stdio.h>
int input(int);
void output(int);
int main()
{
	char c = 0;
	c = input(c);
	output(c); 
	return 0;
}

int input(int c)
{
	printf("�ϳ��� ���ڸ� �Է��ϼ��� :");
	scanf("%c", &c);
	return c;
}

void output(int c)
{
	if (c == 'f' || c == 'F')
	{
		printf("Father\n");
	}
	else if (c == 'm' || c == 'M')
	{
		printf("Mother\n");
	}
	else if (c == 'b' || c == 'B')
	{
		printf("Brother\n");
	}
	else if (c == 's' || c == 'S')
	{
		printf("Sister\n");
	}
	else
	{
		printf("Input Error!!!\n");
	}
}
