// color��� ���� 
#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 

#pragma warning(disable : 4996)
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <string.h>
void menu(char (*)[7],int,int,int,int *,int *);
int mDirection(char *);
void mInput(char(*)[80], int, int *);
void mOutput(char(*)[80], int, int);
void mSearch(char(*)[80], int, int);
void mDelete(char(*)[80], int, int *);
void gotoxy(int x, int y);
void textcolor(int foreground, int background);

int main()
{
	char menuList[][7] = { "Input", "Output", "Search", "Quit" };
	int menuCnt = 4, size, wordcount = 0, direction, position, x, y;
	char word[20][80] = { 0 };
	char ch = 0;
	size = sizeof(word) / sizeof(word[0]);

	direction = mDirection("�޴� ������ �����ϼ���.(1-����,2-����) : ");
	position = mDirection("�޴� ��ġ�� �����ϼ��� : ");
	menu(menuList, menuCnt, direction, position, &x, &y);

	while (ch != 27)
	{
		gotoxy(x, y);
		ch = _getch();
		switch (ch)
		{
		case 'w': y--;  break;
		case 'a': x--; break;
		case 'd': x++;  break;
		case 's': y++;  break;
		default: break;
		}
		system("cls");
		(x > 80) ? x = 1 : x;
		(x < 1) ? x = 80 : x;
		(y > 24) ? y = 1 : y;
		(y < 1) ? y = 24 : y;
	}
	/*while (1)
	{
		
		if (num == 1)
		{
			mInput(word, size, &wordcount);
		}
		else if (num == 2)
		{
			mOutput(word, size, wordcount);
		}
		else if (num == 3)
		{
			mSearch(word, size, wordcount);
		}
		else if (num == 4)
		{
			break;
		}
		system("cls");
	}*/
	return 0;
}
void menu(char(*mList)[7], int mCnt, int d, int p, int *x, int *y)
{
	int i;
	system("cls");
	if (d == 1)
	{
		if (p == 1)
		{
			*x = 1;
			*y = 2;
		}
		else
		{
			*x = 1;
			*y = 21;
		}
		gotoxy(*x, *y);
		for (i = 0; i < mCnt; i++)
		{
			printf("%s ", mList[i]);
		}
	}
	else
	{
		if (p == 1)
		{
			*x = 1;
			*y = 2;
			gotoxy(*x, *y);
			for (i = 0; i < mCnt; i++)
			{
				printf("%s\n", mList[i]);
			}
		}
		else
		{
			*x = 70;
			*y = 2;
			for (i = 0; i < mCnt; i++)
			{
				gotoxy(*x, *y + i);
				printf("%s\n", mList[i]);
			}
		}
	}
	printf("\n");
}
int mDirection(char *m)
{
	int num;
	printf(m);
	while (1)
	{
		if (scanf("%d", &num) == 1)
		{
			if (getchar() == '\n')
			{
				if (num >= 1 && num <= 2)
				{
					break;
				}
			}
		}
		else
		{
			fflush(stdin);
		}
	}
	return num;
}
void mInput(char(*p)[80], int size, int *wc)
{
	char temp[80];
	system("cls");
	printf("\t\t1�� �Է��ϱ� �޴��Դϴ�.\n");
	while (*wc < 20)
	{
		printf("# ���� �ܾ �Է��ϼ���(%d) : ", *wc);
		scanf("%s", temp);
		if (strcmp(temp, "end") != 0)
		{
			strcpy(p[*wc], temp);
			*wc += 1;
		}
		else
		{
			break;
		}
	}
}
void mOutput(char(*p)[80], int size, int wordcount)
{
	//char a;
	int i;
	system("cls");
	printf("\t\t2�� ����ϱ� �޴��Դϴ�.\n");
	for (i = 0; i < size; i++)
	{
		printf("�ܾ� %d : %s\n", i + 1, p[i]);
		if ((i + 1) % 10 == 0)
		{
			getch();
		}
	}
	printf("# �ƹ� Ű�� ������ �� �޴��� ���ư��ϴ�.\n");
	getch();
}
void mSearch(char(*p)[80], int size, int wordcount)
{
	int i, j = 0;
	char temp[80];
	system("cls");
	printf("\t\t3�� �˻��ϱ� �޴��Դϴ�.\n");
	while (1)
	{
		printf("# ã�� �ܾ �Է��ϼ��� : ");
		scanf("%s", temp);
		if (strcmp(temp, "end") != 0)
		{
			for (i = 0; i < wordcount; i++)
			{
				if (strcmp(p[i], temp) == 0)
				{
					printf("@ %s ���ڿ� %d��° ���ڿ��Դϴ�.\n", temp, i + 1);
					break;
				}
				if (i == wordcount - 1)
				{
					if (strcmp(p[wordcount - 1], temp) != 0)
					{
						printf("@ %s ���ڿ��� �������� �ʽ��ϴ�.\n", temp);
					}
				}
			}
		}
		else
		{
			break;
		}
	}
}
void mDelete(char(*p)[80], int size, int *wc)
{
	int i, j;
	char temp[80], a;

	system("cls");
	printf("\t\t4�� �����ϱ� �޴��Դϴ�.\n");
	while (1)
	{
		printf("# ������ �ܾ �Է��ϼ��� : ");
		scanf("%s", temp);
		if (strcmp(temp, "end") != 0)
		{
			for (i = 0; i < *wc; i++)
			{
				if (strcmp(p[i], temp) == 0)
				{
					printf("# ������ �����Ͻðڽ��ϱ�? (Y/N) : ");
					scanf("%c", &a);
					if (getchar() == 'y' || getchar() == 'Y')
					{
						for (j = i; j < *wc; j++)
						{
							strcpy(p[j], p[j + 1]);
						}

						printf("@ �����Ǿ����ϴ�.\n");
						*wc -= 1;
						break;
					}
					else
					{
						printf("������ ��ҵǾ����ϴ�.\n");
					}
				}
				if (i == *wc - 1)
				{
					if (strcmp(p[*wc - 1], temp) != 0)
					{
						printf("@ %s ���ڿ��� �������� �ʽ��ϴ�.\n", temp);
					}
				}
			}
		}
		else
		{
			break;
		}
	}
}
void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}