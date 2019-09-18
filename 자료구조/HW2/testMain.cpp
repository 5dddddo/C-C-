#include "linkedlist.h"
#include "datatype.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <conio.h>
void menu(LinkedList *,char(*)[100],int);
void bitPrint(LinkedList *, char(*)[100], int, int);
int main()
{
	FILE *fp;
	LinkedList list;
	char bit[3][100];
	fp = fopen("c:\\data\\patternData.txt", "rt");
	assert(fp != NULL);
	fscanf(fp, "%s%s%s", bit[0], bit[1], bit[2]);
	fclose(fp);
	menu(&list,bit,sizeof(bit)/sizeof(bit[100]));
	destroy(&list);
	return 0;
}

void menu(LinkedList *lp, char(*bp)[100], int size)
{
	int n;
	while (1)
	{
		printf("* 검사할 패턴의 길이를 입력하시오 : ");
		if (scanf("%d", &n) == 1)
		{
			if (n >= 1 && n <= 7)
				bitPrint(lp, bp, n, size);
			else
				fflush(stdin);
		}
		else
			break;
	}
	return;
}

void bitPrint(LinkedList *lp, char(*bp)[100], int n, int size)
{
	int i, j;

	for (i = 0; i < size; i++)
	{
		create(lp);
		printf("**비트열 : [%s]의 검사 결과**\n", &bp[i]);
		DataType newPattern[3];
		newPattern[0].cnt = newPattern[1].cnt = newPattern[2].cnt = 1;
		for (j = 0; newPattern[i].pattern[n - 1] != NULL; j++)
		{
			Node *res;
			strncpy(newPattern[i].pattern, &bp[i][j], n);
			if (strlen(newPattern[i].pattern) != n-1)
			{
				newPattern[i].pattern[n] = NULL;
				res = searchUnique(lp, &newPattern[i], comparePatternPattern);
				if (res != NULL) // 노드를 찾음
					res->data.cnt++;
				else
					appendFromTail(lp, &newPattern[i]);
			}
		}
		sortList(lp,comparePatternPattern);
		display(lp, printPattern);
		destroy(lp);
	}
}