#include<stdio.h>
#include<windows.h>
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
void textcolor(int foreground, int background);
int main()
{
    textcolor(LIGHTRED, BLACK);
    printf("MT가자\n");
    textcolor(YELLOW, BLACK);
    printf("그래 가자~\n");
    textcolor(BLACK, LIGHTRED);
    printf("어디로 갈까?\n");
    textcolor(LIGHTCYAN, GREEN);
    printf("언제 갈까?\n");
    getchar();
    return 0;
}
void textcolor(int foreground, int background)
{
    int color=foreground+background*16;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
