#include "queue.h"
#include <stdio.h>
#pragma warning (disable: 4996)
int menu(char **, int);
void myFlush();
void input(Queue *);
void myDelete(Queue *);

int main()
{
	Queue que;
	char *menuList[] = { "입력하기", "삭제하기", "출력하기", "종료" };
	int menuCnt;
	int menuNum;

	initQueue(&que,5);

	menuCnt = sizeof(menuList) / sizeof(menuList[0]);
	while (1)
	{
		menuNum = menu(menuList, menuCnt);
		if (menuNum == menuCnt) break;
		switch (menuNum)
		{
		case 1: input(&que); break;
		case 2: myDelete(&que); break;
		case 3: printQueue(&que, printInt);	printf("\n"); break;
		}
	}
	destroyQueue(&que);
	return 0;
}

void input(Queue *qPtr)
{
	int data;
	while (1)
	{
		printf("Put할 정수형 데이터를 입력하시오(문자나 EOF 입력시 종료) :");
		if (scanf("%d", &data) != 1)
		{
			myFlush();
			break;
		}
		if (!enqueue(qPtr, data))
			printf("put(enqueue) 실패!\n");
	}
}

void myDelete(Queue *qPtr)
{
	int i;
	int cnt;
	int getData;
	int res;
	printf("Queue에서 데이터를 get할 횟수를 입력하시오 : ");
	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++)
	{
		res = dequeue(qPtr, &getData);
		if (res == 1)
			printf("get 데이터 : %5d\n", getData);
		else
			printf("get(dequeue) 실패\n");
	}
}

int menu(char **menuList, int menuCnt)
{
	int i;
	int menuNum = 0;
	int res;
	for (i = 0; i < menuCnt; i++)
	{
		printf("%d. %s\n", i + 1, menuList[i]);
	}
	while (menuNum<1 || menuNum > menuCnt)
	{
		printf("# 메뉴번호를 입력하세요 : ");
		res = scanf("%d", &menuNum);
		if (res != 1)
		{
			myFlush();
			continue;
		}
	}
	return menuNum;
}

void myFlush()
{
	while (getchar() != '\n')
	{
		;
	}
}

void printInt(DataType *p)
{
	printf("%4d", *p);

}
