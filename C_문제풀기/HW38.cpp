#pragma warning (disable : 4996)
#include <stdio.h>
void output(int(*)[3][4],int);
int main()
{
	int ary[3][3][4] = { { { 1, 2, 3, 4 }, { 2, 3, 4, 5 }, { 3, 4, 5, 6 } }, { { 4, 5, 6, 7 }, { 5, 6, 7, 8 }, { 6, 7, 8, 9 } } };
	int side;
	side = sizeof(ary) / sizeof(ary[0]);
	output(ary,side);
	return 0;
}

void output(int(*p)[3][4], int side)
{
	int i, j, k;
	for (i = 0; i < side - 1; i++)
	{
		printf("(%d¸é)\n",i);
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 4; k++)
			{
				printf("%2d ", p[i][j][k]);
			}
			printf("\n");
		}
	}
	printf("(2¸é)\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%2d ", p[0][i][j] + p[1][i][j]);
		}
		printf("\n");
	}
}
