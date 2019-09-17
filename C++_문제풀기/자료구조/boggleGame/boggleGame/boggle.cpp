#pragma warning (disable: 4996)
#include <stdio.h>
#include <assert.h>
#include <string.h>
#define TRUE (1)
#define FALSE (0)
#define MAX_BSIZE 1000

typedef struct
{
	int x;
	int y;
}RCoordinate;

int initBoard(FILE *fp);
int boggleGame(const char *searchWord);
int hasWord(int y, int x, const char *word);
int inRange(int y, int x);

int maxX;
int maxY;

RCoordinate RCXY[8] = { { -1, -1 }, { -1, 0 }, { -1, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }, { 0, -1 }, { 0, 1 } };

char board[MAX_BSIZE][MAX_BSIZE + 2];

int main()
{
	FILE *fp;
	int res;
	char *searchWord[] = { "PRETTY", "LGE", "ASDVX" };
	int count = 0;

	fp = fopen("c:\\data\\boggleGameData.txt", "rt");
	assert(fp != NULL);
	while (initBoard(fp))
	{
		res = boggleGame(searchWord[count]);
		if (res == TRUE)
			printf("+ Existence!!(%s)\n", searchWord[count]);
		else
			printf("-Nonexistence!!(%s)\n", searchWord[count]);
		++count;
	}
	fclose(fp);
}


int initBoard(FILE *fp)
{
	int i;
	fscanf(fp, "%d %d\n", &maxY, &maxX);
	if (maxY == 0 || maxX == 0) return FALSE;
	for (i = 0; i < maxY; i++)
	{
		fgets(board[i], maxX + 2, fp);
		board[i][maxX] = '\0';
		puts(board[i]);
	}
	return TRUE;
}
int boggleGame(const char *searchWord)
{
	int i, j;
	int res;
	for (i = 0; i < maxY; i++)
	{
		for (j = 0; j < maxX; j++)
		{
			res = hasWord(i, j, searchWord);
			if (res == TRUE)
				return TRUE;
		}
	}
	return FALSE;
}

int inRange(int y, int x)
{
	if (y >= 0 && y < maxY && x> 0 && x < maxX)
		return TRUE;
	else
		return FALSE;

}

int hasWord(int y, int x, const char *word)
{
	int tempx, tempy;
	if (*word == '\0') return TRUE;
	if (inRange(y, x))
	{
		if (*word == board[y][x])
		{
			for (int i = 0; i < 8; i++)
			{
				tempx = x + RCXY[i].x;
				tempy = y + RCXY[i].y;
				if (hasWord(tempy, tempx, word + 1) == TRUE)
					return TRUE;
			}
		}	
	}
	return FALSE;
}
