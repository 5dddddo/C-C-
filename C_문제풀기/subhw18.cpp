#pragma warning (disable : 4996)
#include <stdio.h>
int input();
void output(int);
int main()
{
	int num, sum = 0;
	while (1)
	{
		num = input();
		if (num >= 0)
		{
			sum += num;
		}
		else
		{
			break;
		}
		output(sum);
	}
}

int input()
{
	int n;
	printf("����� �Է��ϼ��� : ");
	while (1)
	{
		if (scanf("%d", &n) == 1)
		{
			if (getchar() == '\n')
			{
				if (n >= 0)
				{
					return n;
				}
				else
				{
					return -1;
				}
			}
		}
		else
		{
			printf("�ٽ� �Է��Ͻÿ� :");
			fflush(stdin);
		}
	}
}

void output(int sum)
{
	printf("���ݱ��� �Էµ� ���� �� : %d\n",sum);
}