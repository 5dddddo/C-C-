#pragma warning (disable : 4996)
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <malloc.h>
#include "linkedlist.h"
#include "datatype.h"
FILE *fp1, *fp2, *fp3;
int check[100] = {};
void selectWinner(LinkedList *, int, int, int, int);
void readFile();
int main()
{
	int winner, cnt1, cnt2, cnt3;
	cnt1 = cnt2 = cnt3 = 0;
	LinkedList list;
	DataType temp;

	srand((unsigned int)time(NULL));
	create(&list);
	
	fp1 = fopen("c:\\data\\grade1.txt", "rt");
	assert(fp1 != NULL);
	while (fgets(temp.name, sizeof(temp.name), fp1) != NULL)
	{
		cnt1++;
		temp.name[strlen(temp.name) - 1] = NULL;
		fgets(temp.birthDate, sizeof(temp.birthDate), fp1);
		temp.birthDate[strlen(temp.birthDate) - 1] = NULL;
		fgets(temp.number, sizeof(temp.number), fp1);
		temp.number[strlen(temp.number) - 1] = NULL;

		appendFromTail(&list, &temp);
	}
	fclose(fp1);

	fp2 = fopen("c:\\data\\grade2.txt", "rt");
	assert(fp2 != NULL);
	while (fgets(temp.name, sizeof(temp.name), fp2) != NULL)
	{
		cnt2++;
		temp.name[strlen(temp.name) - 1] = NULL;
		fgets(temp.birthDate, sizeof(temp.birthDate), fp2);
		temp.birthDate[strlen(temp.birthDate) - 1] = NULL;
		fgets(temp.number, sizeof(temp.number), fp2);
		temp.number[strlen(temp.number) - 1] = NULL;

		appendFromTail(&list, &temp);
	}
	fclose(fp2);

	fp3 = fopen("c:\\data\\grade3.txt", "rt");
	assert(fp3 != NULL);
	while (fgets(temp.name, sizeof(temp.name), fp3) != NULL)
	{
		cnt3++;
		temp.name[strlen(temp.name) - 1] = NULL;
		fgets(temp.birthDate, sizeof(temp.birthDate), fp3);
		temp.birthDate[strlen(temp.birthDate) - 1] = NULL;
		fgets(temp.number, sizeof(temp.number), fp3);
		temp.number[strlen(temp.number) - 1] = NULL;

		appendFromTail(&list, &temp);
	}

	fclose(fp3);
	while (1)
	{
		printf("추첨자 명수를 입력하세요 : ");
		if (scanf("%d", &winner) == 1)
		{
			if (getchar() == '\n')
				break;
		}
		else
			fflush(stdin);
	}
	selectWinner(&list, winner, cnt1, cnt2, cnt3);
	readFile();
	destroy(&list);
	return 0;
}

void selectWinner(LinkedList *lp, int win, int cnt1, int cnt2, int cnt3)
{
	int i, j, random;
	DataType temp;
	//char str[100];
//	char * res;
	FILE *ofp;
	ofp = fopen("c:\\data\\win.txt", "wt");
	assert(ofp != NULL);
	
	if (win <= cnt1)
	{
		for (i = 0; i < win; i++)
		{
			lp->cur = lp->head->next;
			random = rand() % (cnt1);
			if (check[random] == 0)
			{
				for (j = 0; j != random; j++)
					lp->cur = lp->cur->next;
				check[random] = 1;
				fprintf(ofp,"%15s	%10s-*******	%15s\n",lp->cur->data.name, lp->cur->data.birthDate, lp->cur->data.number);
			}
			else i--;
		}
	}
	else if (win > cnt1 && win <= cnt1 + cnt2)
	{
		fp1 = fopen("c:\\data\\grade1.txt", "rt");
		assert(fp1 != NULL);
		while (fgets(temp.name, sizeof(temp.name), fp1) != NULL)
		{
			temp.name[strlen(temp.name) - 1] = NULL;
			fgets(temp.birthDate, sizeof(temp.birthDate), fp1);
			temp.birthDate[strlen(temp.birthDate) - 1] = NULL;
			fgets(temp.number, sizeof(temp.number), fp1);
			temp.number[strlen(temp.number) - 1] = NULL;
			fprintf(ofp, "%15s	%10s-*******	%15s\n", temp.name, temp.birthDate, temp.number);
		}
	
		for (i = 0; i < win - cnt1; i++)
		{
			lp->cur = lp->head->next;
			random = rand() % (cnt2)+cnt1;
			if (check[random] == 0)
			{
				for (j = 0; j != random; j++)
					lp->cur = lp->cur->next;
				check[random] = 1;
				fprintf(ofp, "%15s	%10s-*******	%15s\n", lp->cur->data.name, lp->cur->data.birthDate, lp->cur->data.number);
			}
			else i--;
		}
	}
	else if (win > cnt1 + cnt2 && win <= cnt1 + cnt2 + cnt3)
	{
		fp1 = fopen("c:\\data\\grade1.txt", "rt");
		assert(fp1 != NULL);
		while (fgets(temp.name, sizeof(temp.name), fp1) != NULL)
		{
			temp.name[strlen(temp.name) - 1] = NULL;
			fgets(temp.birthDate, sizeof(temp.birthDate), fp1);
			temp.birthDate[strlen(temp.birthDate) - 1] = NULL;
			fgets(temp.number, sizeof(temp.number), fp1);
			temp.number[strlen(temp.number) - 1] = NULL;
			fprintf(ofp, "%15s	%10s-*******	%15s\n", temp.name, temp.birthDate, temp.number);
		}
		fclose(fp1);

		fp2 = fopen("c:\\data\\grade2.txt", "rt");
		assert(fp2 != NULL);
		while (fgets(temp.name, sizeof(temp.name), fp2) != NULL)
		{
			temp.name[strlen(temp.name) - 1] = NULL;
			fgets(temp.birthDate, sizeof(temp.birthDate), fp2);
			temp.birthDate[strlen(temp.birthDate) - 1] = NULL;
			fgets(temp.number, sizeof(temp.number), fp2);
			temp.number[strlen(temp.number) - 1] = NULL;
			fprintf(ofp, "%15s	%10s-*******	%15s\n", temp.name, temp.birthDate, temp.number);
		}
		fclose(fp2);

		for (i = 0; i < win - cnt1 - cnt2; i++)
		{
			lp->cur = lp->head->next;
			random = rand() % (cnt3)+(cnt1 + cnt2);
			if (check[random] == 0)
			{
				for (j = 0; j != random; j++)
					lp->cur = lp->cur->next;
				check[random] = 1;
				fprintf(ofp, "%15s	%10s-*******	%15s\n", lp->cur->data.name, lp->cur->data.birthDate, lp->cur->data.number);
			}
			else i--;
		}
	}
	else
	{
		fp1 = fopen("c:\\data\\grade1.txt", "rt");
		assert(fp1 != NULL);
		while (fgets(temp.name, sizeof(temp.name), fp1) != NULL)
		{
			temp.name[strlen(temp.name) - 1] = NULL;
			fgets(temp.birthDate, sizeof(temp.birthDate), fp1);
			temp.birthDate[strlen(temp.birthDate) - 1] = NULL;
			fgets(temp.number, sizeof(temp.number), fp1);
			temp.number[strlen(temp.number) - 1] = NULL;
			fprintf(ofp, "%15s	%10s-*******	%15s\n", temp.name, temp.birthDate, temp.number);
		}
		fclose(fp1);

		fp2 = fopen("c:\\data\\grade2.txt", "rt");
		assert(fp2 != NULL);
		while (fgets(temp.name, sizeof(temp.name), fp2) != NULL)
		{
			temp.name[strlen(temp.name) - 1] = NULL;
			fgets(temp.birthDate, sizeof(temp.birthDate), fp2);
			temp.birthDate[strlen(temp.birthDate) - 1] = NULL;
			fgets(temp.number, sizeof(temp.number), fp2);
			temp.number[strlen(temp.number) - 1] = NULL;
			fprintf(ofp, "%15s	%10s-*******	%15s\n", temp.name, temp.birthDate, temp.number);
		}
		fclose(fp2);

		fp3 = fopen("c:\\data\\grade3.txt", "rt");
		assert(fp3 != NULL);
		while (fgets(temp.name, sizeof(temp.name), fp3) != NULL)
		{
			temp.name[strlen(temp.name) - 1] = NULL;
			fgets(temp.birthDate, sizeof(temp.birthDate), fp3);
			temp.birthDate[strlen(temp.birthDate) - 1] = NULL;
			fgets(temp.number, sizeof(temp.number), fp3);
			temp.number[strlen(temp.number) - 1] = NULL;
			fprintf(ofp, "%15s	%10s-*******	%15s\n", temp.name, temp.birthDate, temp.number);
		}
		fclose(fp3);

	}
	
	fclose(ofp);
	fclose(fp1);
	fclose(fp2);
	fclose(fp3);
}

void readFile()
{
	FILE *P;
	int i = 0;
	char *res;
	char str[100];
	P = fopen("c:\\data\\win.txt", "rt");
	assert(P != NULL);
	
	printf("[No.	   당첨자명		주민번호	      연락처     ]\n");
	while (1)
	{
		i++;
		res = fgets(str, sizeof(str), P);
		if (res == NULL) break;
		str[strlen(str) - 1] = '\0';
		printf("%2d. %s\n",i, str);
	}
	fclose(P);
}