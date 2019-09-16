#pragma warning(disable : 4996)
#include <stdio.h>
int main()
{
	int n1, n2, n3, n4, n5, d1, d2, r1,r2;
	printf("수열입력 : ");
	scanf(" %d %d %d %d", &n1, &n2, &n3, &n4);

	d1 = n2 - n1;
	d2 = n3 - n2;

	r1 = n2 / n1;
	r2 = n3 / n2;

	if (d1 == d2)
	{
		n5 = n4 + d1;
		printf("등차수열 : %d %d %d %d %d ...\n", n1, n2, n3, n4, n5);
	}
	else if (r1 == r2)
	{
		n5 = n4 * r1;
		printf("등비수열 : %d %d %d %d %d ...\n", n1, n2, n3, n4, n5);
	}
	return 0;
}
