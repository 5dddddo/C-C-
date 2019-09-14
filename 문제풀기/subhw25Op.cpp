#pragma warning (disable : 4996)
#include <stdio.h>
int main()
{
	int money=0;
	int i, j, k;
	printf("현재 당신이 소유하고 있는 금액 : ");
	scanf("%d", &money);
	for (i = 1; i * 500 < money; i++)
	{
		for (j = 1; j * 700 < money; j++)
		{
			for (k = 1; k * 400 < money; k++)
			{
				if ((i * 500 + j * 700 + k * 400) == money)
				{
					printf("크림빵(%d개), 새우깡(%d봉지), 콜라(%d병)\n", i, j, k);
				}
			}
		}
	}
	printf("어떻게 구입하시겠습니까?\n");
	return 0;
}