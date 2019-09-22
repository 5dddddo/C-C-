#include "linkedlist.h"
#include "wordchain.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int main()
{
	FILE *fp;
	LinkedList list;
	char pword[5][10];
	int pCnt = 5;
	char word[100] = {};
	char first[100] = { "pointer" };

	fp = fopen("c:\\data\\pointWord.txt", "rt");
	assert(fp!=NULL);
	fscanf(fp, "%s%s%s%s%s%s", pword[0], pword[1],pword[2],pword[3],pword[4]);
	fclose(fp);
	mySort(pword,sizeof(pword)/sizeof(pword[10]));
	create(&list);
	appendFromTail(&list, first);
	menu(&pCnt, pword, &list, word);
	destroy(&list);
	return 0;
}
