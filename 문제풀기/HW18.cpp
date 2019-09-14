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
	printf("\t\t1. 입력하기\n");
	printf("\t\t2. 출력하기\n");
	printf("\t\t3. 검색하기\n");
	printf("\t\t4. 삭제하기\n");
	printf("\t\t5. 종    료\n");

	while (1)
	{
		printf("#메뉴를 선택하세요 : ");
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
	printf("\t\t1번 입력하기 메뉴입니다.\n");
	printf("# 아무 키나 누르면 주 메뉴로 돌아갑니다.\n");
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
	printf("\t\t2번 출력하기 메뉴입니다.\n");
	printf("# 아무 키나 누르면 주 메뉴로 돌아갑니다.\n");
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
	printf("\t\t3번 검색하기 메뉴입니다.\n");
	printf("# 아무 키나 누르면 주 메뉴로 돌아갑니다.\n");
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
	printf("\t\t4번 삭제하기 메뉴입니다.\n");
	printf("# 아무 키나 누르면 주 메뉴로 돌아갑니다.\n");
	getch();
	if (scanf("%c", &a) == 1)
	{
		return;
	}

}
