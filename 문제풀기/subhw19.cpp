#pragma warning (disable : 4996)
#include <stdio.h>
int input();
int main()
{
	int i = 1, num = 0, sum = 0;
	for (i = 1; i <= 5;)
	{
		printf("0���� ū ���� �Է��Ͻÿ�(%d��°) : ", i);
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
	printf("�Էµ� ���� �� �� : %d\n", sum);
}
