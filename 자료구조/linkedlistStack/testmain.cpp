#include "stack.h"
#include "datatype.h"
#include <stdio.h>
#pragma warning (disable: 4996)
int menu(char **, int);
void myFlush();
void input(Stack *);
void myDelete(Stack *);

int main()
{
	Stack stk;
	char *menuList[] = { "입력하기", "삭제하기", "출력하기", "종료" };
	int menuCnt;
	int menuNum;

	initStack(&stk);
	menuCnt = sizeof(menuList) / sizeof(menuList[0]);
	while (1)
	{
		menuNum = menu(menuList, menuCnt);
		if (menuNum == menuCnt) break;
		switch (menuNum)
		{
		case 1: input(&stk); break;
		case 2: myDelete(&stk); break;
		case 3: printStack(&stk, printInt);	printf("\n"); break;
		}
	}
	destroyStack(&stk);
	return 0;
}

void input(Stack *sPtr)
{
	int data;
	while (1)
	{
		printf("Push할 정수형 데이터를 입력하시오(문자나 EOF 입력시 종료) :");
		if (scanf("%d", &data) != 1)
		{
			myFlush();
			break;
		}
		push(sPtr, data);
	}
}

void myDelete(Stack *sPtr)
{
	int i;
	int cnt;
	int popData;
	int res;

	printf("Stack에서 데이터를 pop할 횟수를 입력하시오 : ");
	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++)
	{
		res = pop(sPtr, &popData);
		if (res == 1)
			printf("pop 데이터 : %5d\n", popData);
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
			myFlush();
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
	printf("%5d", *p);

}
