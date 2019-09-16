#include <stdio.h>
#include <string.h>
#include<windows.h>
#include <conio.h>
#pragma warning (disable : 4996)

int input(char *, int *, int *); int yearCheck(int); int allday(int, int, int); void output(int, int, int, int);
void textcolor(int foreground, int background); void gotoxy(int x, int y);
int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };//이프로그램에서는 month 배열을 전역변수로 사용하는게 좋다고 하셔서..
//방향키 대신 w a s d 를 사용했습니다~
int main()
{
	int year, mon, day=1, week, temp = 1;
	char ch = ' ';
	temp = input("* 년 월을 입력하시오 : ", &year, &mon);//현재 년 월이 아닌 hw29번을 응용해서 년 월을 입력받게 했습니다. 설마 감점..?
	if (temp == 0) { return 0; }		
	
	while (ch != 27)
	{	
		week = allday(year, mon, day);
		if (week == 0) { return 0; }
		output(year, mon, day, week);
		ch = getch();
		system("cls");
		if (ch == 'a') 
		{
			mon--; 
			if (mon == 0){ mon = 12, year--; }
		}
		else if (ch == 'd')
		{ 
			mon++; 
			if (mon == 13) { mon = 1, year++; }
		}
		else if (ch == 'w') { year++; }
		else if (ch == 's') { year--; }
		}
}

int input(char *ms, int *y, int *m)
{
	int temp = 1, res;

	while (1)
	{
		printf(ms);
		res = scanf("%d  %d", y, m);
		if (res != 2 || getchar() != '\n'){ return 0; }
		else if (*y <= 0 || *m <= 0 || *m > 12 )
		{
			printf("잘못입력하셨습니다. 다시 입력해주세요.\n"); fflush(stdin);
		}
		else { break; }
	}
	return temp;
}

int yearCheck(int n)
{
	if (n % 4 != 0)
	{ return 0; }
	else
	{
		if (n % 100 == 0)
		{
			if (n % 400 == 0) { return 1; }
			else { return 0; }
		}
		else { return 1;}
	}
}

int allday(int year, int mon, int day)
{
	int res, i, totYear = 0, totMon = 0, totDay = 0;


	if (yearCheck(year) == 1 && (month[3] < day || month[5] < day || month[8] < day || month[10] < day))
	{
		printf("잘못입력하셨습니다. 다시 입력해주세요.\n"); fflush(stdin); return 0;
	}
	else if (yearCheck(year) == 1);
	else if (month[mon - 1] < day)
	{
		printf("잘못입력하셨습니다. 다시 입력해주세요.\n"); fflush(stdin); return 0;
	}

	for (i = 1; i <= year - 1; i++)
	{
		res = yearCheck(i);
		if (res == 1)
		{ totYear += 366; }
		else
		{ totYear += 365;}
	}
	for (i = 0; i < mon - 1; i++)
	{ totMon += month[i]; }

	totDay = totYear + totMon + day;

	if (res == 1 && mon >= 3)
	{ totDay++; }
	
	return totDay;
}

void output(int year, int mon, int day, int week)
{
	system("cls");
	int i,j;
	textcolor(0,15);
	for (j = 1; j <= 24; j++)
	{
		gotoxy(1, j);
		printf("\t\t\t\t\t\t\t\t\t\t");
	}
	gotoxy(39, 3); 
	textcolor(13, 15); printf("%d.%d\n", year, mon); textcolor(0, 15);
	gotoxy(17, 4);
	printf("---------------------------------------------------\n");
	gotoxy(17, 6);
	printf("Sun     Mon     Tus     Wed     Thu     Fri     Sat\n");
	
	switch (week % 7)
	{
	case 0:gotoxy(11, 8); break;
	case 1:gotoxy(19, 8); break;
	case 2:gotoxy(27, 8); break;
	case 3:gotoxy(35, 8); break;
	case 4:gotoxy(43, 8); break;
	case 5:gotoxy(51, 8); break;
	case 6:gotoxy(59, 8); break;
	}
	if (yearCheck(year)==1) { month[1] = 29; }
	else { month[1] = 28; }

	for (i = 1; i <= month[mon - 1]; i++)
	{
		switch (week % 7)
		{
		case 0:if (i % 7 == 0){ textcolor(9, 15); printf("%8d", i); textcolor(0, 15); printf("\n\n\t  "); }
			   else if (i % 7 == 1) { textcolor(12, 15); printf("%8d", i); textcolor(0, 15); }
			   else{ printf("%8d", i); } { break; }
		case 1:if (i % 7 == 6){ textcolor(9, 15); printf("%8d", i); textcolor(0, 15); printf("\n\n\t  "); }
			   else if (i % 7 == 0) { textcolor(12, 15); printf("%8d", i); textcolor(0, 15); }
			   else{ printf("%8d", i); } { break; }
		case 2:if (i % 7 == 5){ textcolor(9, 15); printf("%8d", i); textcolor(0, 15); printf("\n\n\t  "); }
			   else if (i % 7 == 6) { textcolor(12, 15); printf("%8d", i); textcolor(0, 15); }
			   else{ printf("%8d", i); } { break; }
		case 3:if (i % 7 == 4){ textcolor(9, 15); printf("%8d", i); textcolor(0, 15); printf("\n\n\t  "); }
			   else if (i % 7 == 5) { textcolor(12, 15); printf("%8d", i); textcolor(0, 15); }
			   else{ printf("%8d", i); } { break; }
		case 4:if (i % 7 == 3){ textcolor(9, 15); printf("%8d", i); textcolor(0, 15); printf("\n\n\t  "); }
			   else if (i % 7 == 4) { textcolor(12, 15); printf("%8d", i); textcolor(0, 15); }
			   else{ printf("%8d", i); } { break; }
		case 5:if (i % 7 == 2){ textcolor(9, 15); printf("%8d", i); textcolor(0, 15); printf("\n\n\t  "); }
			   else if (i % 7 == 3) { textcolor(12, 15); printf("%8d", i); textcolor(0, 15); }
			   else{ printf("%8d", i); } { break; }
		case 6:if (i % 7 == 1){ textcolor(9, 15); printf("%8d", i); textcolor(0, 15); printf("\n\n\t  "); }
			   else if (i % 7 == 2) { textcolor(12, 15); printf("%8d", i); textcolor(0, 15); }
			   else{ printf("%8d", i); } { break; }
		}
	}
	gotoxy(17, 20);
	printf("---------------------------------------------------\n");
	printf("\n\n\n\n");
}

void textcolor(int foreground, int background)
{
	int color = foreground + background * 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
	COORD Pos = { x - 1, y - 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
