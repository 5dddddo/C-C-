#pragma warning (disable:4996)
#include <stdio.h>
#define CHECK (1)
#define MAX_CNT 15
int columnChk[MAX_CNT + 1];
int incDiagonalLineChk[MAX_CNT * 2 + 1];
int decDiagonalLineChk[MAX_CNT * 2 + 1];
int placementCnt;
int n;
void nQueen(int row);
int main()
{
	while (1)
	{
		printf("퀸의 개수를 입력하시오 : ");
		scanf("%d", &n);
		if (n > 0 && n <= MAX_CNT)
			break;
	}
	nQueen(1);
	printf("배치 가능한 경우의 수 : %d\n\n", placementCnt);
	return 0;
}

void nQueen(int row)
{
	if (row > n)
	{
		placementCnt++;
		return;
	}

	for (int i = 1; i <= n; i++)
	{ 
		if ((columnChk[i] == 0) && (incDiagonalLineChk[row + i] == 0) && (decDiagonalLineChk[n + (row - i)] == 0))
		{
			columnChk[i] = 1;
			incDiagonalLineChk[row + i] = 1;
			decDiagonalLineChk[n + (row - i)] = 1;

			nQueen(row + 1);

			columnChk[i] = 0;
			incDiagonalLineChk[row + i] = 0;
			decDiagonalLineChk[n + (row - i)] = 0;
		}
	}
}