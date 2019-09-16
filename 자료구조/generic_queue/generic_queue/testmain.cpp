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
	char *menuList[] = { "�Է��ϱ�", "�����ϱ�", "����ϱ�", "����" };
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
		printf("�̸� : ");
		scanf("%s", temp.name);
		if (strcmp(temp.name, "��") == 0) break;
		printf("���� : ");
		if (scanf("%d", &temp.age) != 1)
			fflush(stdin);
		else
		{
			printf("��ȣ : ");
			scanf("%s", temp.phoneNumber);
			if (!enqueue(qPtr, &temp, sizeof(Person), personMemCpy))
				printf("put(enqueue) ����!\n");
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
	printf("Queue���� �����͸� get�� Ƚ���� �Է��Ͻÿ� : ");
	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++)
	{
		res = dequeue(qPtr, &temp, sizeof(Person), personMemCpy, personClear);
		if (res == 1)
			printf("get ������\n �̸� : %s ���� : %d ��ȣ : %s\n", temp.name, temp.age, temp.phoneNumber);
		else
			printf("get(dequeue) ����!\n");
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