#pragma warning (disable : 4996)
#include <stdio.h>
int main()
{
	int money = 3500;
	int i, j, k;
	printf("현재 당신이 소유하고 있는 금액 : %d원\n", money);
	for (i = 1; i < 5; i++)
	{
		for (j = 1; j < 4; j++)
		{
			for (k = 1; k < 6; k++)
			{
				if ((i * 5 + j * 7 + k * 4) % 35 == 0)
				{
					printf("크림빵(%d개), 새우깡(%d봉지), 콜라(%d병)\n", i, j, k);
				}
			}
		}
	}
	printf("어떻게 구입하시겠습니까?\n");
	return 0;
}