#include "stack.h"
#include "datatype.h"
#include <stdio.h>
#include <string.h>
#pragma warning (disable: 4996)
int menu(char **, int);
void myFlush();
void input(Stack *);
void myDelete(Stack *);

int main()
{
	Stack stk;
	char *menuList[] = { "�Է��ϱ�", "�����ϱ�", "����ϱ�", "����" };
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
		case 3: printStack(&stk, printPerson);	printf("\n"); break;
		}
	}
	destroyStack(&stk);
	return 0;
}

void input(Stack *sPtr)
{
	DataType n = { "", 0 };
	while (1)
	{
		printf("Push�� ����� �̸��� �Է��Ͻÿ�(�� �Է½� ����) :");
		scanf("%s", n.name);
		if (strcmp(n.name, "��") == 0) break;
		printf("Push�� ����� ���̸� �Է��Ͻÿ�(���ڳ� EOF �Է½� ����) :");
		if (scanf("%d", &n.age) != 1)
		{
			myFlush();
			break;
		}
		push(sPtr, n);
	}
}

void myDelete(Stack *sPtr)
{
	int i;
	int cnt;
	DataType popData;
	int res;

	printf("Stack���� �����͸� pop�� Ƚ���� �Է��Ͻÿ� : ");
	scanf("%d", &cnt);
	for (i = 0; i < cnt; i++)
	{
		res = pop(sPtr, &popData);
		if (res == 1)
			printf("pop ������ : %s %5d�� \n", popData.name, popData.age);
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
