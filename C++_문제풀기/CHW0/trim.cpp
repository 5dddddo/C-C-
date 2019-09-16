#include <stdio.h>
#include <string.h>
void lTrim(char *str);
void rTrim(char *str);
void trim(char *str);
void printStr(char *str, char *changeStr);
int main()
{
	char str[20] = "    Hong G D  ";
	lTrim(str);
	rTrim(str);
	trim(str);
	return 0;
}

void lTrim(char *str)
{
	int i = 0, j = 0;
	char temp[20];
	while (str[i] == ' ')
		i++;
	while (str[i - 1] != NULL)
	{
		temp[j] = str[i];
		i++;
		j++;
	}
	printf("# lTrim #\n");
	printStr(str, temp);
}
void rTrim(char *str)
{
	int i = strlen(str) - 1, j;
	char temp[20];
	while (str[i] == ' ')
		i--;
	for (j = 0; j <= i; j++)
		temp[j] = str[j];
	temp[j] = NULL;
	printf("# rTrim #\n");
	printStr(str, temp);
}
void trim(char *str)
{
	int i = strlen(str) - 1, j = 0, cnt = 0;
	char temp[20];
	for (j = 0; j <= i; j++)
	{
		if (str[j] != ' ')
		{
			temp[cnt] = str[j];
			cnt++;
		}
	}
	temp[cnt] = NULL;
	printf("# Trim #\n");
	printStr(str, temp);
}
void printStr(char *str, char *changeStr)
{
	printf("입력한 string :\"%s\"\n변경된 string :\"%s\"\n\n", str, changeStr);
}