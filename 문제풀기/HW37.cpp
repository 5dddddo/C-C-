#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
void input(char(*)[20],int);
int strcmp(char(*)[20], int, int);
void sort(char(*)[20], int, int, int);
void output(char(*)[20],int);
int main()
{
	char str[5][20];
	int row,i,j,n;
	row = sizeof(str) / sizeof(str[0]);
	input(str, row);
	for (i = 0; i < row - 1; i++)
	{
		for (j = i + 1; j < row; j++)
		{
			n = strcmp(str,i,j);
			sort(str, i, j, n);
		}
	}
	output(str, row);
	return 0;
}

void input(char(*p)[20], int row)
{
	int i;
	for (i = 0; i < row; i++)
	{
		printf("# %d번 문자열을 입력하시오 : ", i+1);
		scanf("%s", p[i]);
	}
}

int strcmp(char(*p)[20], int i, int j)
{
	int n;
	n = strcmp(p[i], p[j]);
	return n;
}

void sort(char(*p)[20], int i, int j, int n)
{
	char temp[20];
	if (n > 0)
	{
		strcpy(temp, p[i]);
		strcpy(p[i], p[j]);
		strcpy(p[j], temp);
	}
}

void output(char(*p)[20], int row)
{
	int i, len;
	for (i = 0; i < row; i++)
	{
		len = strlen(p[i]);
		printf("str[%d] = %20s	%c	%c\n", i, p[i], p[i][0], p[i][len - 1]);
	}
}