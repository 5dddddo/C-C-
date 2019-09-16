#pragma warnig(disable : 4996)
#include <stdio.h>
void output(int, int);
int main()
{
	int i = 1;
	int oddSum = 0;
	int evenSum = 0;

	while (i <= 100)
	{
		if ((i % 2) != 0)
		{
			oddSum += i;
		}
		else
		{
			evenSum += i;
		}
		i++;
	}
	output(oddSum, evenSum);
	return 0;
}

void output(int o, int e)
{
	printf("oddSum : %d\n", o);
	printf("evenSum : %d\n", e);
	return;
}