#pragma warning (disable : 4996)
#include <stdio.h>
int inputInt(char *);
char inputChar(char *);
void charPrint(char, int, int);
int main()
{
	char ch;
	int num, line;
	while (1)
	{
		ch = inputChar("* ����� ���ڸ� �Է��Ͻÿ� : ");
		if (ch == '#')
		{
			break;
		}
		else
		{
			num = inputInt("* ���ٿ� �ݺ��� ȸ���� �Է��Ͻÿ� : ");
			line = inputInt("* �ݺ� ����� ���� ���� �Է��Ͻÿ� : ");
			charPrint(ch, num, line);
		}
	}
	return 0;
}

char inputChar(char *m)
{
	char ch;
	while (1)
	{
		printf(m);
		if (scanf("%c", &ch) == 1)
		{
			if (getchar() == '\n')
			{
				if (ch >= '0' && ch <= '9')
				{
					fflush(stdin);
				}
				else if (ch == '#')
				{
					break;
				}
				else
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
	return ch;
}

int inputInt(char *m)
{
	int n;
	while (1)
	{
		printf(m);
		if (scanf("%d", &n) == 1)
		{
			if (getchar() == '\n')
			{
				if (n > 0)
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
	return n;
}

void charPrint(char ch, int num, int line)
{
	int i, j;
	for (i = 1; i <= line; i++)
	{
		for (j = 1; j <= num; j++)
		{
			printf("%c", ch);
		}
		printf("\n");
	}
}