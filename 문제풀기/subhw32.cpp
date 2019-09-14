#pragma warning (disable : 4996)
#include <stdio.h>
void input(int *);
void output(int *);

int main()
{
	int ary[10];
	input(ary);
	output(ary);
	return 0;
}

void input(int *ip)
{
	int num,i;
	
	for (i = 0; i < 10;i++)
	{
		printf("숫자를 입력하시오 : ");
		if (scanf("%d", &num) == 1)
		{
			*(ip + i) = num;
		}
		else
		{
			fflush(stdin);
		}
	}
}

void output(int *ip)
{
	int i;
	for (i = 0; i < 10; i++)
	{
		if (*(ip + i) % 2 == 1)
		{
			printf("%d ", *(ip + i));
		}
	}
	for (i = 0; i < 10; i++)
	{
		if (*(ip + i) % 2 == 0)
		{
			printf("%d ", *(ip + i));
		}
	}
	printf("\n");
}