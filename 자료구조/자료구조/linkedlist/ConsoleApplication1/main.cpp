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
	Person ary[10] = { { "ȫ�浿", 30 }, { "������", 23 }, { "�����", 27 },
	{ "������", 21 }, { "��ȭ��", 21 }, { "������", 21 }, { "������", 22 },
	{ "������", 23 }, { "������", 23 }, { "������", 23 } };
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
	printf("\t\t1. �Է��ϱ�\n");
	printf("\t\t2. ����ϱ�\n");
	printf("\t\t3. �˻��ϱ�\n");
	printf("\t\t4. �����ϱ�\n");
	printf("\t\t5. Sort�ϱ�\n");
	printf("\t\t6. �����ϱ�\n");
	while (1)
	{
		printf("# �޴��� �����ϼ��� : ");
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
		printf("#�˻��� �̸� �Է� : ");
		scanf("%s", temp.name);
		if (strcmp(temp.name, "��") == 0) break; //"��"�Է½� ����
		res = searchUnique(lp, &temp, comparePersonName); //���� : ã�� ��� �ּ�, ���� : NULL return
		if (res != NULL) // ��带 ã��
		{
			printPerson(&res->data);
			printf("\n");
		}
		else
			printf("#�˻� ����\n");
	}
}
void myDelete(LinkedList *lp)
{
	Node *res;
	Person temp = { "", 0 };
	system("cls");
	while (1)
	{
		printf("#������ �̸� �Է� : ");
		scanf("%s", temp.name);
		if (strcmp(temp.name, "��") == 0) break; //"��"�Է½� ����
		res = searchUnique(lp, &temp, comparePersonName); //���� : ã�� ��� �ּ�, ���� : NULL return
		if (res != NULL) // ��带 ã��
			deleteNode(lp, res);
		else
			printf("#���� ����\n");
	}
}