#pragma warning(disable : 4996)
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
int menu();
void mInput();
void mOutput();
void mSearch();
void mDelete();

int main()
{
	int num;
	
	while (1)
	{	
		num = menu();
		if (num == 1)
		{
			mInput();
		}
		else if (num == 2)
		{
			mOutput();
		}
		else if (num == 3)
		{
			mSearch();
		}
		else if (num == 4)
		{
			mDelete();
		}
		else if (num == 5)
		{
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
	printf("\t\t5. ��    ��\n");

	while (1)
	{
		printf("#�޴��� �����ϼ��� : ");
		if (scanf("%d", &n) == 1)
		{
			if (getchar() == '\n')
			{
				if (n >= 1 && n <= 5)
				{		
					return n;
				}
				else
				{
					fflush(stdin);
				}
			}
		}
		else
		{
			fflush(stdin);
		}
	}
}

void mInput()
{
	char a;
	system("cls");
	printf("\t\t1�� �Է��ϱ� �޴��Դϴ�.\n");
	printf("# �ƹ� Ű�� ������ �� �޴��� ���ư��ϴ�.\n");
	getch();

	if (scanf("%c", &a) == 1)
	{
		return;
	}

}
void mOutput()
{
	char a;
	system("cls");
	printf("\t\t2�� ����ϱ� �޴��Դϴ�.\n");
	printf("# �ƹ� Ű�� ������ �� �޴��� ���ư��ϴ�.\n");
	getch();

	if (scanf("%c", &a) == 1)
	{
		return;
	}

}
void mSearch()
{
	char a;
	system("cls");
	printf("\t\t3�� �˻��ϱ� �޴��Դϴ�.\n");
	printf("# �ƹ� Ű�� ������ �� �޴��� ���ư��ϴ�.\n");
	getch();

	if (scanf("%c", &a) == 1)
	{
		return;
	}

}
void mDelete()
{
	char a;
	system("cls");
	printf("\t\t4�� �����ϱ� �޴��Դϴ�.\n");
	printf("# �ƹ� Ű�� ������ �� �޴��� ���ư��ϴ�.\n");
	getch();
	if (scanf("%c", &a) == 1)
	{
		return;
	}

}
