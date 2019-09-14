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
#include<stdio.h> 
#include<windows.h>
#include <conio.h>
#pragma warning (disable : 4996)
void textcolor(int foreground, int background);
void outputBase();
void gotoxy(int, int);
void outputCalendar(int, int);
int calDate(int, int, int);
int yearCheck(int);
int input();
int checkDate(int, int, int);
int main()
{
	int year = 2015, month = 7, key;
	outputBase();
	outputCalendar(year, month);
	while (1)
	{
		gotoxy(1, 1);
		key = input();
		switch (key)
		{
		case 97:
			if (month == 1)
			{
				if (year != 1)
				{
					month = 12;
					year--;
				}
			}
			else
			{
				month--;
			}
			break;
		case 115:
			if (year != 1)
			{
				year++;
			}
			break;
		case 100:
			if (month == 12)
			{
				month = 1;
				year++;
			}
			else
			{
				month++;
			}
			break;
		case 119:
			year--;
			break;
		default:
			return 0;
			break;
		}
		outputBase();
		outputCalendar(year,month);
	}
	return 0;
}
void outputCalendar(int year, int month)
{
	int i, res, total, day;
	int x = 22, y = 7;
	textcolor(BLACK, WHITE);
	gotoxy(x, y);
	printf("%12s[	%4d %4d	]%12s", " ", year, month, " ");
	textcolor(LIGHTRED, WHITE);
	gotoxy(28, 9);
	printf("%4s", "일");
	textcolor(BLACK, WHITE);
	gotoxy(33, 9);
	printf("%4s %4s %4s %4s %4s","월","화","수","목","금");
	gotoxy(58, 9);
	textcolor(LIGHTBLUE, WHITE);
	printf("%4s", "토");
	textcolor(BLACK, WHITE);
	gotoxy(28, 10);
	printf("%28s", "  --------------------------------");
	x = 28;
	y = 11;	
	for (i = 1; i <= 31; i++)
	{
		res = checkDate(year, month, i);
		if (res == 0)
		{
			break;
		}
		total = calDate(year, month, i);
		day = total % 7;
		switch (day)
		{
		case 0:
			textcolor(LIGHTRED, WHITE);
			gotoxy(x + day * 5, y);
			printf("%4d", i);
			textcolor(BLACK, WHITE);
			break;
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			gotoxy(x + day * 5, y);
			printf("%4d", i);
			break;
		case 6:
			textcolor(LIGHTBLUE, WHITE);
			gotoxy(x + day * 5, y);
			printf("%4d", i);
			textcolor(BLACK, WHITE);
			y++;
			break;
		default:
			break;
		}
	}
}
void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
int calDate(int y, int m, int d)
{
	int monthArray[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int i, total = 0;
	total = (y - 1) * 365 + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;
	if (m > 2 && yearCheck(y))
	{
		monthArray[1]++;
	}
	for(i = 0; i < m - 1; i++)
	{
		total += monthArray[i];

	}
	total += d;
	return total;
}
int yearCheck(int y)
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int input()
{
	char k;
	while (1)
	{	
		k = getch();
		if (k == 97 || k == 100 || k == 115 || k == 119 || k == 27)
		{
			break;
		}
	}
	return k;
}
int checkDate(int y, int m, int d)
{
	int res = 1;
	if (y <= 0 || m <= 00 || d <= 0)
	{
		res = 0;
	}
	else
	{
		switch (m)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if (d > 31)
			{
				res = 0;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (d > 30)
			{
				res = 0;
			}
			break;
		case 2:
			if (yearCheck(y))
			{
				if (d > 29)
				{
					res = 0;
				}
			}
			else
			{
				if (d > 28)
				{
					res = 0;
				}

			}
			break;
		default:
			printf("입력오류\n");
			res = 0;
		}
	}
	return res;
}

void outputBase()
{
	int x = 22, y = 7, i;
	for (i = 0; i < 11; i++)
	{
		textcolor(WHITE, WHITE);
		gotoxy(x, y+i);
		printf("%48d\n");
		gotoxy(x, y);
	}
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
