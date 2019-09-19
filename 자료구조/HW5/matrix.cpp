#include <stdio.h>
void multiMatrix(int(*)[4], int(*)[4], int(*)[4]);
void printMatrix(int(*)[4], int(*)[4], int(*)[4]);
int main()
{
	int A[4][4] = { { 0, 1, 2, 3, }, { 1, -2, 1, 2 }, { 2, 5, -3, 2 }, { 0, -3, 1, 4 } },
		B[4][4] = { { 1, -1, 2, 0 }, { 1, -1, 1, 2 }, { -1, 0, 3, 1 }, { 2, -1, 2, 8 } },
		C[4][4] = { };

	multiMatrix(A, B, C);
	printMatrix(A, B, C);
	return 0;
}

void multiMatrix(int(*ap)[4], int(*bp)[4], int(*cp)[4])
{
	int i, j, k, res;
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{	
			res = 0;
			for (k = 0; k < 4; k++)
				res += ap[j][k] * bp[k][i];
			cp[j][i] = res;
		}
	}
	return;
}
void printMatrix(int(*ap)[4], int(*bp)[4], int(*cp)[4])
{
	int i, j;
	printf(" [Matrix A]	 [Matrix B]	 [Matrix C]\n");
	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
			printf("%2d ", ap[i][j]);
		printf("\t");
		for (j = 0; j < 4; j++)
			printf("%2d ", bp[i][j]);
		printf("\t");
		for (j = 0; j < 4; j++)
			printf("%2d ", cp[i][j]);
		printf("\n");
	}
	return;
}