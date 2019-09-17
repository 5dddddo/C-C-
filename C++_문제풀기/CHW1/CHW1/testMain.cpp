#include "word.h"
#include "genericLinkedlist.h"
#include <stdio.h>
#include <string.h>
//#include <conio.h>
int main()
{
	char filename[50], getWord[30];
	Node *res;
	Word newWord = { NULL, 0 };
	LinkedList list;
	FILE *fp;
	printf("파일명을 입력 : ");
	scanf("%s", filename);
	fp = fopen(filename, "r");
	if (fp == NULL) { printf("open 실패\n"); return 0; }
	create(&list);
	while (fscanf(fp, "%s", getWord) == 1)
	{
		getWord[strlen(getWord)] = '\0';
		res = linearSearchUnique(&list, &getWord, wordCompare);
		if (res == NULL)
		{
			newWord.wp = (char *)calloc(1, strlen(getWord) + 1);
			strcpy(newWord.wp, getWord);
			newWord.length = strlen(newWord.wp);
			appendFromTail(&list, &newWord, sizeof(Word), wordMemCpy);
			free(newWord.wp);
		}
	}
	fclose(fp);
	display(&list, wordPrint);
	destroy(&list, wordClear);
	return 0;
}