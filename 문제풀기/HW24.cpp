#pragma warning (disable : 4996)
#include <stdio.h>
int input();
void output(int);
int main()
{
	int num;
	while (1)
	{
		num = input();
		if (num != -1)
		{
			output(num);
		}
		else
		{
			break;
		}
	}
	return 0;
}

int input()
{
	int n;
	while (1)
	{
		printf("��� ���μ��� �Է��Ͻÿ� : ");
		if (scanf("%d", &n) == 1)
		{
			if (getchar() == '\n')
			{
				if (n > 0)
				{
					break;
				}
			}
			else
			{
				printf("�ٽ��Է��Ͻÿ�.\n");
				fflush(stdin);
			}
		}
		else
		{
			return -1;
		}
	}
	return n;
}

void output(int num)
{
	int i, j;
	for (i = 1; i <= num; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%c",'*');
		}
		for (j = (num  + 1 - i)*2; j >= 1; j--)
		{
			printf("%c", ' ');
		}
		for (j = 1; j <= i; j++)
		{
			printf("%c", '*');
		}
		printf("\n");
	}

}