#include <stdio.h>
#include <conio.h>
#include <windows.h> 
void gotoxy(int x, int y);
void main(void)
{
	char c = 0;
	int x = 40, y = 12;
	while (c != 27)
	{
		gotoxy(x, y);
		printf("*");
		c = _getch();
		switch (c)
		{
		case 'w': y--;  break;
		case 'a': x--; break;
		case 's': x++;  break;
		case 'x': y++;  break;
		default: break;
		}
		system("cls");
		(x > 80) ? x = 1 : x;
		(x < 1) ? x = 80 : x;
		(y > 24) ? y = 1 : y;
		(y < 1) ? y = 24 : y;
	}
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
