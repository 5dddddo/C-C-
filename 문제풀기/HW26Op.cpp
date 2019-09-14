#pragma warning (disable : 4996)
#include <stdio.h>
int main()
{
	int i, j, k;
	for (i = 2; i <= 9; i+=4)
	{
		for (j = 1; j <= 9; j++)
		{
			for (k = i; k <= i + 3; k++)
			{
				printf("%d * %d = %2d	", k, j, k*j);
			}
			printf("\n");
		}
		printf("\n");
	}
}
