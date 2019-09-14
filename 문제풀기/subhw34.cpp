#pragma warning (disable : 4996)
#include <stdio.h>
void output(int *, int);
int main()
{
	int size;
	int ary[] = { 2, 8, 15, 1, 8, 10, 5, 19, 19, 3, 5, 6, 6, 2, 8, 2, 12, 16, 3, 8, 17,
		12, 5, 3, 14, 13, 3, 2, 17, 19, 16, 8, 7, 12, 19, 10, 13, 8, 20,
		16, 15, 4, 12, 3, 14, 14, 5, 2, 12, 14, 9, 8, 5, 3, 18, 18, 20, 4 };
	size = sizeof(ary) / sizeof(ary[0]);
	output(ary, size);
	return 0;
}

void output(int *ip, int size)
{
	int i, j, count[20] = { 0 };
	for (i = 0; i < size; i++)
	{
		for (j = 1; j <= 20; j++)
		{
			if (j == *(ip + i))
			{
				count[j-1]++;
			}
		}
	}
	for (i = 0; i < 20; i++)
	{
		printf("%d - %d°³\n", i + 1, count[i]);
	}
}