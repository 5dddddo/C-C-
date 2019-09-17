#pragma warning(disable :4996)
#include "datatype.h"
#include "linkedlist.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
int main()
{
	char filename[100], button;
	int count = 0, eCount = 0, finish = 0, lineCnt = 0, blank, length;
	LinkedList list;
	Line newline;
	FILE* fp;

	printf("텍스트 파일 이름을 입력하세요 : ");
	scanf("%s", filename);
	fp = fopen(filename, "r");
	if (fp == NULL) { printf("파일 open 실패\n"); return -1; }
	create(&list);
	while (fgets(newline.str, sizeof(newline.str), fp) != NULL)
	{
		lineCnt++;
		newline.str[strlen(newline.str)] = '\0';
		newline.lineNum = lineCnt;
		appendFromTail(&list, &newline);
	}
	length = strlen(list.cur->data.str);
	list.cur->data.str[length] = '\n';
	list.cur->data.str[length+1] = '\0';
	blank = lineCnt + 1;
	for (int i = lineCnt % 24 + 1; i < 25; i++)
	{
		strcpy(newline.str, "\n");
		newline.lineNum = blank;
		appendFromTail(&list, &newline);
		blank++;
	}
	printOnePage(&list, count);
	while (1)
	{
		button = getch();
		if (button == 's' || button == 'S')
		{
			if (finish != 1)
			{
				if (24 * count < lineCnt)
				{
					count++;
					if (printOnePage(&list, count) == 1)
					{
						finish = 1;
						count--;
					}
				}
			}
		}
		else if (button == 'w' || button == 'W')
		{
			if (finish != 1)
			{
				if (count > 0)
					count--;
			}
			else
				finish = 0;
			printOnePage(&list, count);
		}
		else if (button == 'e' || button == 'E')
			break;
	}
	fclose(fp);
	destroy(&list);
	return 0;
}
