#pragma warning (disable : 4996)
#include <stdio.h>
int main()
{
	int money = 3500;
	int i, j, k;
	printf("���� ����� �����ϰ� �ִ� �ݾ� : %d��\n", money);
	for (i = 1; i < 5; i++)
	{
		for (j = 1; j < 4; j++)
		{
			for (k = 1; k < 6; k++)
			{
				if ((i * 5 + j * 7 + k * 4) % 35 == 0)
				{
					printf("ũ����(%d��), �����(%d����), �ݶ�(%d��)\n", i, j, k);
				}
			}
		}
	}
	printf("��� �����Ͻðڽ��ϱ�?\n");
	return 0;
}