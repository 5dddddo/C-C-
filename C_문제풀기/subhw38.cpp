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
#pragma warning (disable:4996)
#include<stdio.h> 
#include<windows.h> 
#include<string.h>
#include<conio.h>
void textcolor(int foreground, int background);
void gotoxy(int x, int y);
int input(char(*)[80], char(*)[7], int *, int, int *, int *);
void menu(char(*)[80], char(*)[7], int);

int main()
{
	char word[20][80] = { "����Ʈ��",0 };
	char pointWord[][7] = { "������", "���Ƹ�", "����", "�����", "ȣ����" };
	int i, score = 0, x = 15, y = 3;
	for (i = 1; i < 21; i++)
	{
		menu(word, pointWord, score);
		i = input(word, pointWord, &score, i, &x, &y);
	}
	return 0;
}
void menu(char(*w)[80], char(*p)[7], int score)
{
	gotoxy(3, 2);
	printf("[�����ձ� ����]");
	gotoxy(3, 3);
	printf("����Ʈ�� -> ");
	gotoxy(10, 16);
	printf("* ����Ʈ �ܾ� *\n");
	gotoxy(10, 17);
	printf("1. ������\n");
	gotoxy(10, 18);
	printf("2. ���Ƹ�\n");
	gotoxy(10, 19);
	printf("3. ����\n");
	gotoxy(10, 20);
	printf("4. �����\n");
	gotoxy(10, 21);
	printf("5. ȣ����\n");
	gotoxy(50, 19);
	printf("���� : %d��", score);
	gotoxy(28, 10);
	printf("%s", "                                                            ");

}
int input(char(*w)[80], char(*p)[7], int *s, int i, int *x, int *y)
{
	char pointWord[][7] = { "������", "���Ƹ�", "����", "�����", "ȣ����" };
	int j, len1;
	len1 = strlen(w[i - 1]);
	while (1)
	{
		gotoxy(20, 10);
		printf("�ܾ� �Է� : ");
		scanf("%s", w[i]);
		if ((w[i - 1][len1 - 2] == w[i][0]) && (w[i - 1][len1 - 1] == w[i][1]))
		{
			gotoxy(*x, *y);
			*x += strlen(w[i]) + 4;
			if (*x > 80)
			{
				*x = 3;
				gotoxy(*x, ++*y);
			}
			if (i != 20)
			{
				printf("%s -> ", w[i]);
			}
			else
			{
				printf("%s", w[i]);
			}
			for (j = 0; j < 5; j++)
			{
				if (strcmp(pointWord[j], w[i]) == 0)
				{
					*s += 20;

					break;
				}
			}
			gotoxy(20, 11);
			printf("%s", "                                                            ");
		}
		else
		{
			gotoxy(20, 11);
			printf("�߸� �Է��ϼ̽��ϴ�.\n");
			--i;
			fflush(stdin);

		}
		return i;
		break;
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