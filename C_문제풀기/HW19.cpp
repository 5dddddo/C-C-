#pragma warning (disable : 4996)
#include <stdio.h>
short input();
void output(short);
int main()
{
	short num;
	num = input();
	output(num);
	return 0;
}

short input()
{
	short n;
	printf("* 10진수 정수를 입력하시오 : ");
	scanf("%hd", &n);
	return n;
}

void output(short num)
{
	int i;
	printf("%d(10) = ",num);
	for (i = 0; i < 16; i++)
	{
		if (num & 0x8000)
		{
			printf("1");
		}
		else
		{
			printf("0");
		}
		num <<= 1;
	}
	printf("(2)\n");
}