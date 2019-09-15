#pragma warning(disable : 4996)
#include <stdio.h>
int main()
{
	int i, j = 1;
	for (i = 1; i <= 100; )
	{
		if (j <= 10)
		{
			if (i % 3 == 0 && i % 5 == 0)
			{
				printf("%d	", i);
			}
			else if (i % 3 == 0)
			{
				printf("*	");
			}
			else if (i % 5 == 0)
			{
				printf("#	");
			}	
			else
			{
				printf("%d	", i);
			}
			i++;
			j++;
		}
		else if (j == 11)
		{
			printf("\n");
			j = 1;
		}
	}
	return 0;
}