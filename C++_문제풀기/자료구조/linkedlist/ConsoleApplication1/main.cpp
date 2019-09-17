#include "datatype.h"
#include "linkedlist.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>
void mySearch(LinkedList *lp);
void myDelete(LinkedList *lp);
int menu();
int main()
{
	Person ary[10] = { { "홍길동", 30 }, { "오은애", 23 }, { "김재웅", 27 },
	{ "조윤영", 21 }, { "장화진", 21 }, { "송지연", 21 }, { "김유나", 22 },
	{ "김혜서", 23 }, { "이유주", 23 }, { "유가영", 23 } };
	int i, num;
	LinkedList list;
	create(&list);
	for (i = 0; i < sizeof(ary) / sizeof(ary[0]); i++)
	{
		appendFromTail(&list, &ary[i]);
	}

	while (1)
	{
		num = menu();
		//if (num == 1)
		//	makeNode(dataPtr, lp->tail->prev, lp->tail);
		 if (num == 2)
			display(&list, printPerson);
		else if (num == 3)
			mySearch(&list);
		else if (num == 4)
			myDelete(&list);
		else if (num == 5)
			sortList(&list, comparePersonName);
		else if (num == 6)
		{
			destroy(&list);
			break;
		}
		system("cls");
	}
	return 0;
}

int menu()
{
	int n;
	printf("\t\t1. 입력하기\n");
	printf("\t\t2. 출력하기\n");
	printf("\t\t3. 검색하기\n");
	printf("\t\t4. 삭제하기\n");
	printf("\t\t5. Sort하기\n");
	printf("\t\t6. 종료하기\n");
	while (1)
	{
		printf("# 메뉴를 선택하세요 : ");
		if (scanf("%d", &n) == 1)
		{
			if (getchar() == '\n')
			{
				if (n >= 1 && n <= 6)
					return n;
			}
		}
		else
			fflush(stdin);
	}
}
void mySearch(LinkedList *lp)
{
	Node *res;
	Person temp = { "", 0 };
	system("cls");
	while (1)
	{
		printf("#검색할 이름 입력 : ");
		scanf("%s", temp.name);
		if (strcmp(temp.name, "끝") == 0) break; //"끝"입력시 종료
		res = searchUnique(lp, &temp, comparePersonName); //성공 : 찾은 노드 주소, 실패 : NULL return
		if (res != NULL) // 노드를 찾음
		{
			printPerson(&res->data);
			printf("\n");
		}
		else
			printf("#검색 실패\n");
	}
}
void myDelete(LinkedList *lp)
{
	Node *res;
	Person temp = { "", 0 };
	system("cls");
	while (1)
	{
		printf("#삭제할 이름 입력 : ");
		scanf("%s", temp.name);
		if (strcmp(temp.name, "끝") == 0) break; //"끝"입력시 종료
		res = searchUnique(lp, &temp, comparePersonName); //성공 : 찾은 노드 주소, 실패 : NULL return
		if (res != NULL) // 노드를 찾음
			deleteNode(lp, res);
		else
			printf("#삭제 실패\n");
	}
}