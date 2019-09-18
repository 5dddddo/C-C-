#pragma warning(disable:4996)
#include<stdio.h>
#include<assert.h>
#include<windows.h>
#define NL printf("\n")
#define PAUSE system("pause")

typedef struct tunnel_info {
	int number;  /* �� ��ȣ */
	int size;    /* �� ũ�� */
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


int map[MAX_SIZE + 1][MAX_SIZE + 1];  /* �δ��� ���� ���� ����(0��, 0�� ��� ����) */
TunnelInfo tunnelInfo[MAX_SIZE * 2 + 1];    /* �δ��� ���� ũ�� ����(2�� �� ���ĺ��� ���) */
int n;  /* map�� ����(row), ����(colum)�� ũ�� ���� ���� */
int tunnelNumber;  /* �δ����� ��ȣ */
/*-------------------------------------------------------------------------------------
�Լ��� �� ���  main() : �׷����� �����ϰ� DFS Ž���� �ǽ��Ѵ�.
------------------------------------------------------------------------------------*/
int main()
{
	char *fileName[] = { "c:\\data\\�δ�����1.txt" , "c:\\data\\�δ�����2.txt", "c:\\data\\�δ�����3.txt" };
	for (int i = 0; i < sizeof(fileName) / sizeof(fileName[0]); ++i) {
		tunnelNumber = 1; /* �δ����� ��ȣ(1�� �ͳ��� ������ �ǹ��ϹǷ� 2�� ���� ���) */
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
�Լ��� �� ���  dataLoad() : ������ ���Ͽ��� �˻��� �����͸� �Է� �޾� map�� �����ϴ� �Լ�
��������        char *fileName : �δ��� ���� ������ ����� ������ ���ϸ�
���ϰ�          ���� �бⰡ �����ϸ� TRUE ����, �����ϸ� FALSE ����
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
�Լ��� �� ���  initTunnelInfo() : ���� ������ ������ ����ü �ʱ�ȭ �Լ�
��������        ����
���ϰ�          ����
--------------------------------------------------------------------------------------*/
void initTunnelInfo()
{
	int i;
	for (i = 0; i <= MAX_SIZE * 2; ++i) {
		tunnelInfo[i].number = i;
		tunnelInfo[i].size = 0;  /* extern���� ����� �迭�� ����̹Ƿ� ���ص� �� */
	}
}
/*--------------------------------------------------------------------------------------
�Լ��� �� ���  solve() : �δ��� ���� ����, ũ�⸦ ����ϴ� �Լ�(���ȣ�� ������ dfs�� �̿��� Ǯ��)
��������        ����
���ϰ�          ����
--------------------------------------------------------------------------------------*/
void solve()
{
	int i, j;
	initTunnelInfo();
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n; ++j) {
			if (map[i][j] == 1) {  /* �ͳ��� �߰ߵǸ� */
				++tunnelNumber;
				dfs(i, j, tunnelNumber);  /* ���̿켱Ž�� ���� */
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
	printf("�δ��� �� ���� : %d\n", tunnelNumber - 1);
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

