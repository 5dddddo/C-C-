#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
void input(char *);
int numCheck(char *);
void output(int);
int main()
{
	char temp[100];
	int sum;
	input(temp);
	sum = numCheck(temp);
	output(sum);
	return 0;
}

void input(char *cp)
{
	printf("# ���ڿ��� �Է��Ͻÿ� : ");
	gets(cp);
}

int numCheck(char *cp)
{
	int len, sum = 0, i;
	len = strlen(cp);
	for (i = 0; i < len; i++)
	{
		if (cp[i] >= '0' && cp[i] <= '9')
		{
			sum += cp[i] - '0';
		}
	}
	return sum;
}

void output(int sum)
{
	printf("���ڿ� �ȿ� �����ϴ� ���ڵ��� �� �� : %d\n", sum);
}
