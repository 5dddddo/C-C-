#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
void input(char *, char *);
int strCheck(char *, char);
void output(char *, char, int);
int main()
{
	char ch[20], c;
	int count;
	input(ch, &c);
	count = strCheck(ch,c);
	output(ch, c, count);
	return 0;
}

void input(char *ch, char *c)
{
	printf("#���ڿ��� �Է��Ͻÿ� : ");
	scanf("%s", ch);
	printf("#���ڸ� �Է��Ͻÿ� : ");
	scanf(" %c", c);

}

int strCheck(char *ch, char c)
{
	int i, len, count = 1;
	len = strlen(ch);
	for (i = 0; i < len; i++, count++)
	{
		if (ch[i] == c)
		{
			return count;
		}
	}
	if (ch[len - 2] != c)
		{
			return -1;
		}
}

void output(char *ch, char c, int count)
{
	if (count != -1)
	{
		printf("\"%s\" ���ڿ� �ȿ� '%c' ���ڴ� %d��° �����Դϴ�.\n", ch, c, count);
	}
	else
	{
		printf("\"%s\" ���ڿ� �ȿ� '%c' ���ڴ� �������� �ʽ��ϴ�.\n", ch, c);
	}
}