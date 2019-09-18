#pragma warning (disable : 4996)
#include <stdio.h>
#include <malloc.h>
int x = -1, y = 0, cnt = 0;
void inputData(int **, int, int);
int main()
{
	int size, i, j;
	int **matrix;

	printf("# 행/열의 수 입력 : ");
	scanf("%d", &size);
	
	matrix = (int **)calloc(size, sizeof(int *));
	for (i = 0; i < size; i++)
		matrix[i] = (int *)calloc(size, sizeof(int));
	inputData(matrix, size, 1);

/*	while (cnt < size*size)
	{
		for (i = 0; i < size - 1; i++)
		{
			cnt++;
			matrix[0][i] = cnt;
		}
		for (j = 1; j < size - 1; j++)
		{
			cnt++;
			matrix[j][i] = cnt;
		}
		for (j = i - 1; j >= 0; j--)
		{
			cnt++;
			matrix[j][i] = cnt;
		}
		for (i = j - 1; i; i--)
		{
			cnt++;
			matrix[i][j] = cnt;
		}
	}*/
	

	for (int i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
			printf("%2d ", matrix[i][j]);
		printf("\n");
	}
	return 0;
}
void inputData(int **m, int s, int d)
{
	int i;
	if (s == 0) return;
	for (i = 0; i < s * 2 - 1; i++)
	{
		if (i < s)
			x += d;
		else
			y += d;
		cnt++;
		m[y][x] = cnt;
	}
	//재귀호출
	inputData(m, s - 1, d*(-1));
}

