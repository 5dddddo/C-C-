#include <stdio.h>
int iteratorPower2(int power);
int recursivePower2(int power);
int main()
{
	int power = 10;
	printf("2ÀÇ %d½ÂÀÇ °ª = %d\n", power, iteratorPower2(power));
	printf("2ÀÇ %d½ÂÀÇ °ª = %d\n", power, recursivePower2(power));
	return 0;
}

int iteratorPower2(int p)
{
	int res = 1;
	for (int i = 1; i <= p; i++)
		res *= 2;
	return res;
}

int recursivePower2(int p)
{
	if (p == 0) return 1;
	else return recursivePower2(p - 1) * 2;
}