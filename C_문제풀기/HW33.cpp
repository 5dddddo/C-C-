#pragma warning (disable : 4996)
#include <stdio.h>
#include <windows.h>
#include <string.h>
void input(char *);
void scroll(char *);
void blink(char *);
void gotoxy(int, int);
int main()
{
	char str[100];
	input(str);
	scroll(str);
	return 0;
}

void input(char *cp)
{
	gets(cp);
}

void scroll(char *cp)
{
	char temp;
	int len, i, j;
	len = strlen(cp);
	for (i = 0, j = 1; i < len; i++, j++)
	{
		temp = cp[i];
		cp[i] = cp[len - j];
		cp[len - j] = temp;
		gotoxy(30, 12);
		printf("%s\n", cp);
		blink(cp);
	}
}

void blink(char *cp)
{
	system("cls");
	Sleep(700);
	gotoxy(30, 12);
	printf("%s\n", cp);
	Sleep(700);
	system("cls");
	Sleep(700);
	gotoxy(30, 12);
	printf("%s\n", cp);
	Sleep(700);
	system("cls");
}

void gotoxy(int x, int y)
{
COORD Pos = { x - 1, y - 1 };
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
