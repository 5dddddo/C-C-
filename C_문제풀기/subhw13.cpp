#pragma warning(disable : 4996)
#include <stdio.h>
int inputNum(char *);
int inputChar(char *);
void output(int,char);
int main()
{
	int num;
	char ch;
	num = inputNum("# �ݺ�ȸ���� �Է��Ͻÿ� : ");
	ch = inputChar("# �ݺ����ڸ� �Է��Ͻÿ� : ");
	output(num, ch);
	return 0;
}

int inputNum(char *m)
{
	int n;
	while (1)
	{
		printf(m);
		if (scanf("%d", &n) == 1)
		{
			if (getchar() == '\n')
			{
				break;
			}
			else
			{
				fflush(stdin);
			}
		}
		else
		{
			fflush(stdin);
		}
	}
	return n;
}

int inputChar(char *m)
{
	char c;
	while (1)
	{
		printf(m);
		if (scanf("%c", &c) == 1)
		{
			if (getchar() == '\n')
			{
				break;
			}
		}
		else
		{
			fflush(stdin);
		}
	}
	return c;
}

void output(int n, char c)
{
	int i = 1;
	while (i <= n)
	{
		printf("%c", c);
		i++;
	}
	printf("\n");
}