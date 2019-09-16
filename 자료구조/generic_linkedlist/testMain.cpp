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
	Person ary[10] = { { "���ٻ�", 25, "010-9898-2846" }, { "������", 21, "010-1234-5678" }, { "�󸶹�", 24, "010-7657-1785" },
	{ "������", 28, "010-5965-2913" }, { "�ٻ��", 26, "010-3454-6745" }, { "�����", 27, "010-1454-9568" },
	{ "����ī", 29, "010-7877-1216" }, { "��īŸ", 30, "010-9432-7654" }, { "���ٶ�", 22, "010-1111-2222" }, { "�ٶ�", 23, "010-4345-5565" } };
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
			printf("# �ƹ� Ű�� ������ �� �޴��� ���ư��ϴ�.\n");
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
			printf("�ٽ� �Է�\n");
		system("cls");
	}
	return 0;
}

int menu()
{
	int n;
	printf("\t\t1. �Է��ϱ�\n");
	printf("\t\t2. ����ϱ�\n");
	printf("\t\t3. �˻��ϱ�\n");
	printf("\t\t4. �����ϱ�\n");
	printf("\t\t5. Sort�ϱ�\n");
	printf("\t\t6. ���߰˻�\n");
	printf("\t\t7. ���߻���\n");
	printf("\t\t8. �����ϱ�\n");

	while (1)
	{
		printf("# �޴��� �����ϼ��� : ");
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
		printf("# �Է��� ����� �̸� : ");
		dataPtr->name = (char *)calloc(1, sizeof(char[20]));
		scanf("%s", dataPtr->name);
		if (strcmp(dataPtr->name, "��") == 0) break;
		printf("# �Է��� ����� ���� : ");
		scanf("%d", &dataPtr->age);
		printf("# �Է��� ����� ��ȣ : ");
		scanf("%s", dataPtr->phoneNumber);
		printf("# Head Node ��(h,H) / Tail Node ��(t,T) : ");
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
		printf("# �˻��� �̸� �Է� : ");
		temp.name = (char *)calloc(1, sizeof(char[20]));
		scanf("%s", temp.name);

		if (strcmp(temp.name, "��") == 0) break; //"��"�Է½� ����
		res = linearSearchUnique(lp, &temp, personNameCompare); //���� : ã�� ��� �ּ�, ���� : NULL return
		if (res != NULL) // ��带 ã��
			personPrint(res + 1);
		else
			printf("# �˻� ����\n");
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
		printf("#������ �̸� �Է� : ");
		temp.name = (char *)calloc(1, sizeof(char[20]));
		scanf("%s", temp.name);
		if (strcmp(temp.name, "��") == 0) break; //"��"�Է½� ����
		res = linearSearchUnique(lp, &temp, personNameCompare); //���� : ã�� ��� �ּ�, ���� : NULL return
		if (res != NULL) // ��带 ã��
			deleteNode(lp, res, personClear);
		else
			printf("#���� ����\n");
		free(temp.name);
	}
}

void mySort(LinkedList *lp)
{
	char s;
	system("cls");
	printf("# �̸� Sort(n,N) / ���� Sort(a,A) : ");
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
		printf("# ���� �˻��� �̸� �Է� : ");
		temp.name = (char *)calloc(1, sizeof(char[20]));
		scanf("%s", temp.name);
		if (strcmp(temp.name, "��") == 0) break; //"��"�Է½� ����
		res = linearSearchDuplicate(lp, &temp, &cnt, personNameCompare); //���� : ã�� ��� �ּ�, ���� : NULL return
		if (res != NULL) // ��带 ã��
		{
			for (i = 0; i < cnt; i++)
				personPrint(res[i] + 1);
		}
		else
			printf("# �˻� ����\n");
		free(temp.name);
		free(res); //res�� �ѵ��!
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
		printf("# ���� ������ �̸� �Է� : ");
		temp.name = (char *)calloc(1, sizeof(char[20]));
		scanf("%s", temp.name);
		if (strcmp(temp.name, "��") == 0) break; //"��"�Է½� ����
		res = linearSearchDuplicate(lp, &temp, &cnt, personNameCompare); //���� : ã�� ��� �ּ�, ���� : NULL return
		if (res != NULL) // ��带 ã��
		{
			for (i = 0; i < cnt; i++)
				deleteNode(lp, res[i], personClear);
		}
		else
			printf("# ���� ����\n");
		free(temp.name);
	}
}