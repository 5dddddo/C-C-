#include "person.h"
#include "genericLinkedlist.h"
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <conio.h>
void myInput(Person *dataPtr, LinkedList *lp);
void mySearch(LinkedList *lp);
void myDelete(LinkedList *lp);
void mySort(LinkedList *lp);
void mySearchDuplicate(LinkedList *lp);
void myDeleteDuplicate(LinkedList *lp);
int menu();
int main()
{
	Person ary[10] = { { "마바사", 25, "010-9898-2846" }, { "가나다", 21, "010-1234-5678" }, { "라마바", 24, "010-7657-1785" },
	{ "아자차", 28, "010-5965-2913" }, { "바사아", 26, "010-3454-6745" }, { "사아자", 27, "010-1454-9568" },
	{ "자차카", 29, "010-7877-1216" }, { "차카타", 30, "010-9432-7654" }, { "나다라", 22, "010-1111-2222" }, { "다라마", 23, "010-4345-5565" } };
	int i, num;
	LinkedList list;
	Person person = { NULL, 0, "" };
	create(&list);
	for (i = 0; i < sizeof(ary) / sizeof(ary[0]); i++)
	{
		appendFromTail(&list, &ary[i], sizeof(Person), personMemCpy);
	}

	while (1)
	{
		num = menu();
		if (num == 1)
			myInput(&person, &list);
		else if (num == 2)
		{
			display(&list, personPrint);
			printf("# 아무 키나 누르면 주 메뉴로 돌아갑니다.\n");
			getch();
		}

		else if (num == 3)
			mySearch(&list);
		else if (num == 4)
			myDelete(&list);
		else if (num == 5)
			mySort(&list);
		else if (num == 6)
			mySearchDuplicate(&list);
		else if (num == 7)
			myDeleteDuplicate(&list);
		else if (num == 8)
		{
			destroy(&list, personClear);
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

void myInput(Person *dataPtr, LinkedList *lp)
{
	char n;
	system("cls");
	while (1)
	{
		printf("# 입력할 사람의 이름 : ");
		dataPtr->name = (char *)calloc(1, sizeof(char[20]));
		scanf("%s", dataPtr->name);
		if (strcmp(dataPtr->name, "끝") == 0) break;
		printf("# 입력한 사람의 나이 : ");
		scanf("%d", &dataPtr->age);
		printf("# 입력한 사람의 번호 : ");
		scanf("%s", dataPtr->phoneNumber);
		printf("# Head Node 뒤(h,H) / Tail Node 앞(t,T) : ");
		scanf(" %c", &n);
		if (n == 'h' || n == 'H')
			appendFromHead(lp, dataPtr, sizeof(Person), personMemCpy);
		else if (n == 't' || n == 'T')
			appendFromTail(lp, dataPtr, sizeof(Person), personMemCpy);
		lp->length++;
		free(dataPtr->name);
	}
	return;
}
void mySearch(LinkedList *lp)
{
	Node *res;
	Person temp = { NULL, 0, "" };
	system("cls");
	while (1)
	{
		printf("# 검색할 이름 입력 : ");
		temp.name = (char *)calloc(1, sizeof(char[20]));
		scanf("%s", temp.name);

		if (strcmp(temp.name, "끝") == 0) break; //"끝"입력시 종료
		res = linearSearchUnique(lp, &temp, personNameCompare); //성공 : 찾은 노드 주소, 실패 : NULL return
		if (res != NULL) // 노드를 찾음
			personPrint(res + 1);
		else
			printf("# 검색 실패\n");
		free(temp.name);
	}
}
void myDelete(LinkedList *lp)
{
	Node *res;
	Person temp = { NULL, 0, "" };
	system("cls");
	while (1)
	{
		printf("#삭제할 이름 입력 : ");
		temp.name = (char *)calloc(1, sizeof(char[20]));
		scanf("%s", temp.name);
		if (strcmp(temp.name, "끝") == 0) break; //"끝"입력시 종료
		res = linearSearchUnique(lp, &temp, personNameCompare); //성공 : 찾은 노드 주소, 실패 : NULL return
		if (res != NULL) // 노드를 찾음
			deleteNode(lp, res, personClear);
		else
			printf("#삭제 실패\n");
		free(temp.name);
	}
}

void mySort(LinkedList *lp)
{
	char s;
	system("cls");
	printf("# 이름 Sort(n,N) / 나이 Sort(a,A) : ");
	scanf("%c", &s);
	if (s == 'n' || s == 'N')
		sortList(lp, sizeof(Person), personNameCompare, personMemCpy, personClear);
	else if (s == 'a' || s == 'A')
		sortList(lp, sizeof(Person), personAgeCompare, personMemCpy, personClear);
}
void mySearchDuplicate(LinkedList *lp)
{
	int i, cnt;
	Node **res;
	system("cls");
	while (1)
	{
		Person temp = { NULL, 0, "" };
		printf("# 다중 검색할 이름 입력 : ");
		temp.name = (char *)calloc(1, sizeof(char[20]));
		scanf("%s", temp.name);
		if (strcmp(temp.name, "끝") == 0) break; //"끝"입력시 종료
		res = linearSearchDuplicate(lp, &temp, &cnt, personNameCompare); //성공 : 찾은 노드 주소, 실패 : NULL return
		if (res != NULL) // 노드를 찾음
		{
			for (i = 0; i < cnt; i++)
				personPrint(res[i] + 1);
		}
		else
			printf("# 검색 실패\n");
		free(temp.name);
		free(res); //res는 한덩어리!
	}
}
void myDeleteDuplicate(LinkedList *lp)
{
	int i, cnt;
	Node **res;
	Person temp = { NULL, 0, "" };
	system("cls");
	while (1)
	{
		printf("# 다중 삭제할 이름 입력 : ");
		temp.name = (char *)calloc(1, sizeof(char[20]));
		scanf("%s", temp.name);
		if (strcmp(temp.name, "끝") == 0) break; //"끝"입력시 종료
		res = linearSearchDuplicate(lp, &temp, &cnt, personNameCompare); //성공 : 찾은 노드 주소, 실패 : NULL return
		if (res != NULL) // 노드를 찾음
		{
			for (i = 0; i < cnt; i++)
				deleteNode(lp, res[i], personClear);
		}
		else
			printf("# 삭제 실패\n");
		free(temp.name);
	}
}