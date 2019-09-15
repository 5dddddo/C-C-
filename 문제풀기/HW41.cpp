#pragma warning (disable : 4996)
#include <stdio.h>
char* ustrcpy(char *, char *);
size_t ustrlen(const char *s);
int ustrcmp(const char *s1, const char *s2);
int main()
{
	char chr[20] = "gogumi", str[20];
	unsigned int len;
	int res;
	ustrcpy(str, chr);
	printf("%s %s\n", str, chr);
	len = ustrlen(chr);
	printf("문자열 길이 : %d\n",len);
	res = ustrcmp("abc", "abcd");
	printf("res = %d\n", res);
	return 0;
}

char* ustrcpy(char *dest, char *src)
{
	int i = 0;
	while (1)
	{
		dest[i] = src[i];
		if (src[i] == 0)
		{
			break;
		}
		i++;
	}
	return dest;
}

size_t ustrlen(const char *s)
{
	int count = 0;
	while (1)
	{
		if (s[count] == 0)
		{
			break;
		}
		count++;
	}
	return count;
}

int ustrcmp(const char *s1, const char *s2)
{
	int count = 0;
	while (s1[count] == s2[count])
	{
		if (s1[count] == 0)
		{
			return 0;
		}
		count++;
	}

	if (s1[count] - s2[count] > 0)
	{
		return -1;
	}
	else if (s1[count] - s2[count] < 0)
	{
		return 1;
	}
}
