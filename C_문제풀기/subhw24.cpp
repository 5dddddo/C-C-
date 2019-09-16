#pragma warning (disable : 4996)
#include <stdio.h>
int main()
{
	int i, j, sum = 0;
	for (i = 1; i <= 100; i+= 10)
	{
		for (j = i; j <= i + 9; j++)
		{
			sum += j;
		}
		printf("%d ~ %d = %d\n", i, i + 9, sum);
		sum = 0;
	}
	return 0;
}