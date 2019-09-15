#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <assert.h>
void inputString(char **,int);
void mySort(char **,int);
void output(char **,int);
void myfree(char **,int);
int main()
{
	char *p[5] = { 0 };
	inputString(p, sizeof(p) / sizeof(p[0]));
	mySort(p,sizeof(p) / sizeof(p[0]));
	output(p, sizeof(p) / sizeof(p[0]));
	myfree(p, sizeof(p) / sizeof(p[0]));
	return 0;
}

void inputString(char **p, int size)
{
	char temp[100] = { 0 };
	int len, i;
	for (i = 0; i < size; i++)
	{
		printf("# ¹®ÀÚ¿­ %d : ", i + 1);
		scanf("%s", temp);
		len = strlen(temp);
		p[i] = (char *)malloc(sizeof(char) * (len + 1));
		assert(p[i] != NULL);
		strcpy(p[i], temp);
		strcpy(temp, "\0");
	}
}

void mySort(char **p, int size)
{
	int i, j;
	char *temp;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (strcmp(p[i], p[j]) > 0)
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

void output(char **p,int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%d. %s\n", i + 1,p[i]);
	}
}

void myfree(char **p, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		free(p[i]);
	}
}