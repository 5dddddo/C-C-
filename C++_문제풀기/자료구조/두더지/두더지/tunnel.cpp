#pragma warning(disable:4996)
#include<stdio.h>
#include<assert.h>
#include<windows.h>
#define NL printf("\n")
#define PAUSE system("pause")

typedef struct tunnel_info {
	int number;  /* 굴 번호 */
	int size;    /* 굴 크기 */
}TunnelInfo;
typedef struct
{
	int x;
	int y;
}RCoordinate;

#define MAX_SIZE 30
int dataLoad(char *);
void solve();
void output();
int inRange(int, int);
int dfs(int row, int col, int tNum);
void sort(int start, int end);

RCoordinate RCXY[4] = { { -1, 0 },{ 1, 0 },{ 0, -1 }, { 0, 1 } };


int map[MAX_SIZE + 1][MAX_SIZE + 1];  /* 두더지 굴의 상태 저장(0행, 0열 사용 안함) */
TunnelInfo tunnelInfo[MAX_SIZE * 2 + 1];    /* 두더지 굴의 크기 저장(2번 방 이후부터 사용) */
int n;  /* map의 가로(row), 세로(colum)의 크기 저장 변수 */
int tunnelNumber;  /* 두더지굴 번호 */
/*-------------------------------------------------------------------------------------
함수명 및 기능  main() : 그래프를 구현하고 DFS 탐색을 실시한다.
------------------------------------------------------------------------------------*/
int main()
{
	char *fileName[] = { "c:\\data\\두더지굴1.txt" , "c:\\data\\두더지굴2.txt", "c:\\data\\두더지굴3.txt" };
	for (int i = 0; i < sizeof(fileName) / sizeof(fileName[0]); ++i) {
		tunnelNumber = 1; /* 두더지굴 번호(1은 터널이 있음을 의미하므로 2번 부터 사용) */
		if (dataLoad(fileName[i]) == FALSE) return 0;
		solve();
		output();
		NL;
		printf("===================================================================\n\n");
	}
	PAUSE;
	return 0;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능  dataLoad() : 데이터 파일에서 검사할 데이터를 입력 받아 map에 저장하는 함수
전달인자        char *fileName : 두더지 굴의 정보가 저장된 데이터 파일명
리턴값          파일 읽기가 성공하면 TRUE 리턴, 실패하면 FALSE 리턴
--------------------------------------------------------------------------------------*/
int dataLoad(char *fileName)
{
	FILE *fp;

	int i, j; /* iterator */
	fp = fopen(fileName, "rt");
	if (fp == NULL) {
		printf("file open error!!!\n");
		PAUSE;
		return FALSE;
	}
	if (fscanf(fp, "%d", &n) != 1) return FALSE;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			if (fscanf(fp, "%d", &map[i][j]) != 1) return FALSE;
		}
	}
	fclose(fp);
	return TRUE;
}
/*--------------------------------------------------------------------------------------
함수명 및 기능  initTunnelInfo() : 굴의 정보를 저장할 구조체 초기화 함수
전달인자        없음
리턴값          없음
--------------------------------------------------------------------------------------*/
void initTunnelInfo()
{
	int i;
	for (i = 0; i <= MAX_SIZE * 2; ++i) {
		tunnelInfo[i].number = i;
		tunnelInfo[i].size = 0;  /* extern으로 선언된 배열의 멤버이므로 안해도 됨 */
	}
}
/*--------------------------------------------------------------------------------------
함수명 및 기능  solve() : 두더지 굴의 개수, 크기를 계산하는 함수(재귀호출 형식의 dfs를 이용한 풀이)
전달인자        없음
리턴값          없음
--------------------------------------------------------------------------------------*/
void solve()
{
	int i, j;
	initTunnelInfo();
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			if (map[i][j] == 1) {  /* 터널이 발견되면 */
				++tunnelNumber;
				dfs(i, j, tunnelNumber);  /* 깊이우선탐색 시작 */
			}
		}
	}
	return;
}

int dfs(int row, int col, int tNum)
{
	int tempx, tempy;
	if (inRange(row, col))
	{
		if (map[row][col] == 1)
		{
			map[row][col] = tNum;
			tunnelInfo[tNum].number = tNum;
			tunnelInfo[tNum].size++;
			for (int i = 0; i < 4; i++)
			{
				tempx = row + RCXY[i].x;
				tempy = col + RCXY[i].y;
				if (dfs(tempx, tempy, tNum) == TRUE)
					return TRUE;
			}
		}
	}
}

int inRange(int x, int y)
{
	if (y > 0 && y < MAX_SIZE + 1 && x> 0 && x < MAX_SIZE + 1)
		return TRUE;
	else
		return FALSE;
}

void output()
{
	sort(2, tunnelNumber);
	int i, j;
	printf("두더지 굴 개수 : %d\n", tunnelNumber - 1);
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j) 
			printf(" %d ", map[i][j]);
		printf("\n");
	}
	printf("\n");
	
	for (i = 2; i <= tunnelNumber; ++i)
		printf("size of tunnel %d : %d\n", tunnelInfo[i].number, tunnelInfo[i].size);
}


void sort(int start, int end)
{
	int i,j, target;
	TunnelInfo tmp;
	for (i = start; i < end; i++)
	{
		target = i;
		for (j = i + 1; j <= end; j++)
			if (tunnelInfo[target].size < tunnelInfo[j].size)
				target = j;
		tmp = tunnelInfo[i];
		tunnelInfo[i] = tunnelInfo[target];
		tunnelInfo[target] = tmp;
	}
}

