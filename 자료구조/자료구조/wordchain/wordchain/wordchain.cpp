#include "linkedlist.h"
#include "wordchain.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
void mySort(char(*pw)[10], int size)
{
	int i, j;
	char temp[100];
	for (i = 0; i < size; i++)
	{
		for (j = i + 1; j < size + 1; j++)
		{
			if (strcmp((pw[i]), (pw[j])) > 0)
			{
				strcpy(temp, pw[i]);
				strcpy(pw[i], pw[j]);
				strcpy(pw[j], temp);
			}
		}
	}
}

void menu(int *pCnt, char(*pw)[10], LinkedList *lp, char *dataPtr)
{
	int i, cnt = 1;
	while (1)
	{
		if (*pCnt != 0)
		{
			printf("\n* 포인트단어:");
			for (i = 0; i < *pCnt; i++)
				printf(" %s /", pw[i]);
			printf("\n* 사용자 입력 단어: ");
			display(lp, printWord);
			printf("\n끝말잇기 단어 입력(%d회차) : ", cnt);
			scanf("%s", dataPtr);
			compareWord(lp, pw, dataPtr, &cnt, pCnt);
		}
		else
		{
			printf("**포인트 단어를 모두 맞췄습니다. 게임을 종료합니다.\n");
			break;
		}
	}
}

Node * compareWord(LinkedList *lp, char(*pw)[10], char *dataPtr, int *cnt, int *pCnt)
{
	int i = 0, j, len;
	len = strlen(lp->cur->prev->data);
	if (lp->cur->prev->data[len - 1] == dataPtr[0])
	{
		for (i = 0; i <= *pCnt; i++)
		{
			if (strcmp(pw[i], dataPtr) == 0)
			{
				(*pCnt)--;
				if (i != *pCnt)
				{
					for (j = i; j != *pCnt; j++)
						strcpy(pw[j], pw[j + 1]);
				}
			}
		}
		(*cnt)++;
		appendFromTail(lp, dataPtr);
	}
	else
	{
		printf("잘못 입력하셨습니다.\n");
	}
	return NULL;
}
