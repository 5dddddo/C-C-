#include "queue.h"
#include "person.h"
#include <stdio.h>
#include <Windows.h>
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

	initQueue(&que, 5, sizeof(Person));

	menuCnt = sizeof(menuList) / sizeof(menuList[0]);
	while (1)
	{
		menuNum = menu(menuList, menuCnt);
		if (menuNum == menuCnt) break;
		switch (menuNum)
		{
		case 1: input(&que);  break;
		case 2: myDelete(&que);  break;
		case 3: printQueue(&que, sizeof(Person), personPrint); break;
		}
	}
	destroyQueue(&que, sizeof(Person), personClear);
	return 0;
}

void input(Queue *qPtr)
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
		if (scanf("%d", &temp.age) != 1)
			fflush(stdin);
		else
		{
			printf("번호 : ");
			scanf("%s", temp.phoneNumber);
			if (!enqueue(qPtr, &temp, sizeof(Person), personMemCpy))
				printf("put(enqueue) 실패!\n");
		}
		free(temp.name);
	}
}

void myDelete(Queue *qPtr)
{
	int i;
	int cnt;
	Person temp = { NULL, 0, "" };
	int res;
	printf("Queue에서 데이터를 get할 횟수를 입력하시오 : ");
	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++)
	{
		res = dequeue(qPtr, &temp, sizeof(Person), personMemCpy, personClear);
		if (res == 1)
			printf("get 데이터\n 이름 : %s 나이 : %d 번호 : %s\n", temp.name, temp.age, temp.phoneNumber);
		else
			printf("get(dequeue) 실패!\n");
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