#pragma warning (disable : 4996)
#include <stdio.h>
char input(char *);
void output(char);
int main()
{
	char ch;
	while (1)
	{
		ch = input("* 영문자 대문자 입력('A' ~ 'Z') : ");
		if (ch == -1)
		{
			break;
		}
		else
		{
			output(ch);
		}
	}
	return 0;
}

char input(char *m)
{
	char ch;
	while (1)
	{
		printf(m);
		if (scanf("%c", &ch) == 1)
		{
			if (getchar() == '\n')
			{
				if (ch >= 'A' && ch <= 'Z')
				{
					break;
				}
				else
				{
					return -1;
				}
			}
		}
		else
		{
			break;
		}
	}
	return ch;
}

void output(char ch)
{
	char i, j;
	for (i = ch; i >= 'A' ; i--)
	{
		for (j = ch; j >= i; j--)
		{
			printf("%c", j);
		}
		printf("\n");
	}
}