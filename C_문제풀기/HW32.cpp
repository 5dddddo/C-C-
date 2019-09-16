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
	printf("#문자열을 입력하시오 : ");
	scanf("%s", ch);
	printf("#문자를 입력하시오 : ");
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
		printf("\"%s\" 문자열 안에 '%c' 문자는 %d번째 문자입니다.\n", ch, c, count);
	}
	else
	{
		printf("\"%s\" 문자열 안에 '%c' 문자는 존재하지 않습니다.\n", ch, c);
	}
}