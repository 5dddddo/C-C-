#include "datatype.h"
#include "linkedlist.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>
void myInput(DataType *dataPtr, LinkedList *lp);
void mySearch(LinkedList *lp);
void myDelete(LinkedList *lp);
void mySearchDuplicate(LinkedList *lp);
void myDeleteDuplicate(LinkedList *lp);
int menu();
int main()
{
	Person ary[10] = { { "홍길동", 30 }, { "오은애", 23 }, { "김재웅", 27 },
	{ "조윤영", 21 }, { "장화진", 21 }, { "송지연", 21 }, { "김유나", 22 },
	{ "김혜서", 23 }, { "이유주", 23 }, { "유가영", 23 } };
	int i, num;
	LinkedList list;
	DataType person = { "", 0 };
	create(&list);
	for (i = 0; i < sizeof(ary) / sizeof(ary[0]); i++)
	{
		appendFromTail(&list, &ary[i]);
	}

	while (1)
	{
		num = menu();
		if (num == 1)
			myInput(&person,&list);
		else if (num == 2)
			display(&list, printPerson);
		else if (num == 3)
			mySearch(&list);
		else if (num == 4)
			myDelete(&list);
		else if (num == 5)
			sortList(&list, comparePersonName);
		else if (num == 6)
			mySearchDuplicate(&list);
		else if (num == 7)
			myDeleteDuplicate(&list);
		else if (num == 8)
		{
			destroy(&list);
			break;
		}
		else
			printf("다시 입력\n");
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
	printf("\t\t6. 다중검색\n");
	printf("\t\t7. 다중삭제\n");
	printf("\t\t8. 종료하기\n");

	while (1)
	{
		printf("# 메뉴를 선택하세요 : ");
		if (scanf("%d", &n) == 1)
		{
			if (getchar() == '\n')
			{
				if (n >= 1 && n <= 8)
					return n;
			}
		}
		else
			fflush(stdin);
	}
}

void myInput(DataType *dataPtr, LinkedList *lp)
{
	char n;
	system("cls");
	while (1)
	{
		printf("# 입력할 사람의 이름 : ");
		scanf("%s", dataPtr->name);
		if (strcmp(dataPtr->name, "끝") == 0) break;
		printf("# 입력한 사람의 나이 : ");
		scanf("%d", &dataPtr->age);
		printf("# Head Node 뒤(h,H) / Tail Node 앞(t,T) : ");
		scanf(" %c", &n);
		if (n == 'h' || n == 'H')
			appendFromHead(lp, dataPtr);
		else if (n == 't' || n == 'T')
			appendFromTail(lp, dataPtr);
		lp->length++;
	}
	return;
}
void mySearch(LinkedList *lp)
{
	Node *res;
	Person temp = { "", 0 };
	system("cls");
	while (1)
	{
		printf("# 검색할 이름 입력 : ");
		scanf("%s", temp.name);
		if (strcmp(temp.name, "끝") == 0) break; //"끝"입력시 종료
		res = searchUnique(lp, &temp, comparePersonName); //성공 : 찾은 노드 주소, 실패 : NULL return
		if (res != NULL) // 노드를 찾음
		{
			printPerson(&res->data);
			printf("\n");
		}
		else
			printf("# 검색 실패\n");
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
void mySearchDuplicate(LinkedList *lp)
{
	int i, cnt;
	Node **res;
	system("cls");
	while (1)
	{
		Person temp = { "", 0 };
		printf("# 다중 검색할 이름 입력 : ");
		scanf("%s", temp.name);
		if (strcmp(temp.name, "끝") == 0) break; //"끝"입력시 종료
		res = searchDuplicate(lp, &cnt, &temp, comparePersonName); //성공 : 찾은 노드 주소, 실패 : NULL return
		if (res != NULL) // 노드를 찾음
		{
			for (i = 0; i < cnt; i++)
				printf("%s : %d\n", res[i]->data.name,res[i]->data.age);
		}	
		else
			printf("# 검색 실패\n");
		free(res); //res는 한덩어리!
	}


}
void myDeleteDuplicate(LinkedList *lp)
{
	int i, cnt;
	Node **res;
	Person temp = { "", 0 };
	system("cls");
	while (1)
	{
		printf("# 다중 삭제할 이름 입력 : ");
		scanf("%s", temp.name);
		if (strcmp(temp.name, "끝") == 0) break; //"끝"입력시 종료
		res = searchDuplicate(lp, &cnt, &temp, comparePersonName); //성공 : 찾은 노드 주소, 실패 : NULL return
		if (res != NULL) // 노드를 찾음
		{
			for (i = 0; i < cnt; i++)
				deleteNode(lp,res[i]);
		}
		else
			printf("# 삭제 실패\n");
	}
}