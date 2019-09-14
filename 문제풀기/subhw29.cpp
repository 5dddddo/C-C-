#pragma warning (disable : 4996)
#include <stdio.h>
#include <ctype.h>
#include <string.h>
void input(char *); 
int tolower(char *);
int palindrome(char *,int);
void output(char *,int);
int main()
{
	char ch[20], temp[20] = { 0 };
	int len, i, n;
	input(ch);
	len = strlen(ch);
	for (i = 0; i < len; i++)
	{
		temp[i] = tolower(ch[i]);
	}
	n = palindrome(temp, len);
	output(temp,n);
	return 0;
}

void input(char *cp)
{
	scanf("%s", cp);
}

int palindrome(char *cp,int len)
{
	int i,j;
	for (i = 0, j = 1; i <= len - j; i++, j++)
	{
		if (cp[i] != cp[len - j])
		{
			return 0;
		}
	}
	return 1;
}

void output(char *cp,int n)
{
	if (n == 1)
	{
		printf("회문입니다.\n");
	}
	else
	{
		printf("회문이 아닙니다.\n");
	}
}