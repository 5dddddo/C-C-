#pragma warning (disable : 4996)
#include <stdio.h>
int input();
int main()
{
	int i = 1, num = 0, sum = 0;
	for (i = 1; i <= 5;)
	{
		printf("0보다 큰 수를 입력하시오(%d번째) : ", i);
		if (scanf("%d", &num) == 1)
		{
			if (getchar() == '\n')
			{
				if (num > 0)
				{
					i++;
					sum += num;
				}
		}
		else
		{
			fflush(stdin);
		}
	}
	printf("입력된 값의 총 합 : %d\n", sum);
}
