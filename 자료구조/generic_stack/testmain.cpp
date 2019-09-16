#include "stack.h"
#include <stdio.h>
#include "person.h"
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

	initStack(&stk, 5, sizeof(Person));
	menuCnt = sizeof(menuList) / sizeof(menuList[0]);
	while (1)
	{
		menuNum = menu(menuList, menuCnt);
		if (menuNum == menuCnt) break;
		switch (menuNum)
		{
		case 1: input(&stk); break;
		case 2: myDelete(&stk); break;
		case 3: printStack(&stk, sizeof(Person), personPrint); printf("\n"); break;
		}
	}
	destroyStack(&stk, sizeof(Person), personClear);
	return 0;
}

void input(Stack *sPtr)
{
	Person temp = { NULL, 0, "" };
	char name[20];
	while (1)
	{
		temp.name = (char *)calloc(1, sizeof(name));
		printf("이름 : ");
		scanf("%s", temp.name);
		if (strcmp(temp.name, "끝") == 0) break;
		printf("나이 : ");
		scanf("%d", &temp.age);
		printf("번호 : ");
		scanf("%s", temp.phoneNumber);
		push(sPtr, &temp, sizeof(Person), personMemCpy);
		free(temp.name);
	}
}

void myDelete(Stack *sPtr)
{
	int i;
	int cnt;
	Person temp = { NULL, 0, "" };
	int res;
	printf("Stack에서 데이터를 pop할 횟수를 입력하시오 : ");
	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++)
	{
		res = pop(sPtr, &temp, sizeof(Person), personMemCpy, personClear);
		if (res == 1)
			printf("pop 데이터\n 이름 : %s 나이 : %d 번호 : %s\n", temp.name, temp.age, temp.phoneNumber);
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
