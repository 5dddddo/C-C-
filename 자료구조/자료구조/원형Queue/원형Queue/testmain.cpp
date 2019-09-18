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
	char *menuList[] = { "�Է��ϱ�", "�����ϱ�", "����ϱ�", "����" };
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
		printf("Put�� ������ �����͸� �Է��Ͻÿ�(���ڳ� EOF �Է½� ����) :");
		if (scanf("%d", &data) != 1)
		{
			myFlush();
			break;
		}
		if (!enqueue(qPtr, data))
			printf("put(enqueue) ����!\n");
	}
}

void myDelete(Queue *qPtr)
{
	int i;
	int cnt;
	int getData;
	int res;
	printf("Queue���� �����͸� get�� Ƚ���� �Է��Ͻÿ� : ");
	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++)
	{
		res = dequeue(qPtr, &getData);
		if (res == 1)
			printf("get ������ : %5d\n", getData);
		else
			printf("get(dequeue) ����\n");
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
		printf("# �޴���ȣ�� �Է��ϼ��� : ");
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
