#include <stdio.h>
#include <conio.h>
#include <windows.h> 
void gotoxy(int x, int y);
void main(void)
{
	char c = 0;
	int i, j;
	char star[3][4] = { { '*', '*', '*', '*' }, { '*', ' ', ' ', '*' }, { '*', '*', '*', '*' } };
	int x = 38, y = 11;
	while (c != 27)
	{
		for (i = 0; i < 3; i++)
		{		
			gotoxy(x, y + i);
			for (j = 0; j < 4; j++)
			{
				printf("%c", star[i][j]);
			}
		}
		gotoxy(x, y);
		c = _getch();
		switch (c)
		{
		case 'w': y--;	break;
		case 'a': x--;	break;
		case 'd': x++;  break;
		case 's': y++;  break;
		default: break;
		}
		system("cls");
		(x > 80) ? x = 1 : x;
		(x < 1) ? x = 80 : x;
		(y > 23) ? y = 1 : y;
		(y < 1) ? y = 23 : y;
	}
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
