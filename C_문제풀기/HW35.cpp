#pragma warning (disable : 4996)
#include <stdio.h>
void input(int(*)[4],int);
void output(int(*)[4],int);
int main()
{
	int num[3][4], row;
	row = sizeof(num) / sizeof(num[0]);
	input(num,row);
	output(num,row);
	return 0;
}

void input(int(*p)[4],int row)
{
	int i,j;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("num[%d][%d] : ", i, j);
			while (1)
			{
				if (scanf("%d", &p[i][j]) == 1)
				{
					if (getchar() == '\n')
					{
						if (p[i][j] > 0)
						{
							break;
						}
					}
				}
				else
				{
					fflush(stdin);
				}
			}
		}
	}
}

void output(int(*p)[4], int row)
{
	int i,j,sum = 0;
	
	for (i = 0; i < row; i++)
	{
		printf("	%d행 : ",i);
		for (j = 0; j < 4; j++)
		{	
			printf("%2d ", p[i][j]);
			sum += p[i][j];
		}
		printf("	%d행의 합 : %2d\n ",i, sum);
		sum = 0;
	}

	printf("   열의 합 : ");
	for (j = 0; j < 4; j++)
	{
		for (i = 0; i < row; i++)
		{
			sum += p[i][j];
		}
		printf("%2d ",sum);
		sum = 0;
	}
	printf("\n");

}