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
	Person ary[10] = { { "ȫ�浿", 30 }, { "������", 23 }, { "�����", 27 },
	{ "������", 21 }, { "��ȭ��", 21 }, { "������", 21 }, { "������", 22 },
	{ "������", 23 }, { "������", 23 }, { "������", 23 } };
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

void myInput(DataType *dataPtr, LinkedList *lp)
{
	char n;
	system("cls");
	while (1)
	{
		printf("# �Է��� ����� �̸� : ");
		scanf("%s", dataPtr->name);
		if (strcmp(dataPtr->name, "��") == 0) break;
		printf("# �Է��� ����� ���� : ");
		scanf("%d", &dataPtr->age);
		printf("# Head Node ��(h,H) / Tail Node ��(t,T) : ");
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
		printf("# �˻��� �̸� �Է� : ");
		scanf("%s", temp.name);
		if (strcmp(temp.name, "��") == 0) break; //"��"�Է½� ����
		res = searchUnique(lp, &temp, comparePersonName); //���� : ã�� ��� �ּ�, ���� : NULL return
		if (res != NULL) // ��带 ã��
		{
			printPerson(&res->data);
			printf("\n");
		}
		else
			printf("# �˻� ����\n");
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
void mySearchDuplicate(LinkedList *lp)
{
	int i, cnt;
	Node **res;
	system("cls");
	while (1)
	{
		Person temp = { "", 0 };
		printf("# ���� �˻��� �̸� �Է� : ");
		scanf("%s", temp.name);
		if (strcmp(temp.name, "��") == 0) break; //"��"�Է½� ����
		res = searchDuplicate(lp, &cnt, &temp, comparePersonName); //���� : ã�� ��� �ּ�, ���� : NULL return
		if (res != NULL) // ��带 ã��
		{
			for (i = 0; i < cnt; i++)
				printf("%s : %d\n", res[i]->data.name,res[i]->data.age);
		}	
		else
			printf("# �˻� ����\n");
		free(res); //res�� �ѵ��!
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
		printf("# ���� ������ �̸� �Է� : ");
		scanf("%s", temp.name);
		if (strcmp(temp.name, "��") == 0) break; //"��"�Է½� ����
		res = searchDuplicate(lp, &cnt, &temp, comparePersonName); //���� : ã�� ��� �ּ�, ���� : NULL return
		if (res != NULL) // ��带 ã��
		{
			for (i = 0; i < cnt; i++)
				deleteNode(lp,res[i]);
		}
		else
			printf("# ���� ����\n");
	}
}