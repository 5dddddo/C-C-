#pragma warning (disable : 4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
void inputNumber(char *);
void transNumber(char *, int *);
void transChar(int);
int main()
{
	int sum = 0;
	char num[13] = {};
	while (1)
	{
		inputNumber(num);
		if (strcmp(num, "0000") == 0)
		{
			transChar(sum);
			break;
		}
		transNumber(num, &sum);
		
	}
	return 0;
}
void inputNumber(char *n)
{
	int len, i, gap;
	*n = NULL;
	printf("금액 입력 : ");
	scanf("%s", n);
	len = strlen(n);
	for (i = 0; i < len; i++)
	{
		gap = n[i] - '0';
		if ((gap < 0 || gap > 9) && (gap != ',' - '0'))
		{
			strcpy(n, "0");
			fflush(stdin);
		}
	}

}
void transNumber(char *n, int *s)
{
	int len, temp;
	len = strlen(n);
	if (len != 1)
	{
		for (int i = len - 1; i >= 0; i--)
		{
			temp = n[i] - '0';
				for (int j = 1; j < len - i; j++)
					temp = (temp * 10);
			*s += temp;
		}
	}
	else *s += n[0] - '0';
}
void transChar(int s)
{
	int point;
	char temp[15] = {}, res[15] = {};
	itoa(s, res, 10);

	point = strlen(res) % 3;
	for (int i = 0; i < strlen(res); i++)
	{
		if ((i % 3 == point) && (i != 0)) 
			printf(",");
		printf("%c", res[i]); 
	}
	printf("\n");

}
