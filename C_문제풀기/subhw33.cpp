#pragma warning (disable : 4996)
#include <stdio.h>
int input();
void output(int *, int, int);
int main()
{
	int num, size;
	int ary[] = { 2, 8, 15, 1, 8, 10, 5, 19, 19, 3, 5, 6, 6, 2, 8, 2, 12, 16, 3, 8, 17,
		12, 5, 3, 14, 13, 3, 2, 17, 19, 16, 8, 7, 12, 19, 10, 13, 8, 20,
		16, 15, 4, 12, 3, 14, 14, 5, 2, 12, 14, 9, 8, 5, 3, 18, 18, 20, 4 };
	num = input();
	size = sizeof(ary) / sizeof(ary[0]);
	output(ary, num, size);
	return 0;
}

int input()
{
	int num;
	printf("찾기를 원하는 숫자를 입력하세요(1~20) : ");
	while (1)
	{
		if (scanf("%d", &num) == 1)
		{
			if (getchar() == '\n')
			{
				if (num > 0 && num <= 20)
				{
					break;
				}
			}
		}
		else
		{
			fflush(stdin);
		}
	}
	return num;
}

void output(int *ip, int num,int size)
{
	int i, count = 0;
	for (i = 0; i < size; i++)
	{
		if (num == *(ip + i))
		{
			count++;
		}
	}
	printf("숫자 %d는 배열에 %d개 있습니다.\n", num, count);
}