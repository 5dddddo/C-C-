#pragma warning (disable : 4996)
#include <stdio.h>
int calculateSum();
void output(int);
int main()
{
	int sum = 0;
	sum = calculateSum();
	output(sum);
	return 0;
}

int calculateSum()
{
	int i,sum = 0;
	for (i = 1; i <= 100;)
	{
		if (i % 3 == 0 || i % 7 == 0)
		{
			i++;
		}
		else
		{
			sum += i;
			i++;
		}
	}
	return sum;
}

void output(int sum)
{
	printf("수행결과 : %d\n", sum);
}