#pragma warning (disable : 4996)
#include <stdio.h>
int main()
{
	int money=0;
	int i, j, k;
	printf("���� ����� �����ϰ� �ִ� �ݾ� : ");
	scanf("%d", &money);
	for (i = 1; i * 500 < money; i++)
	{
		for (j = 1; j * 700 < money; j++)
		{
			for (k = 1; k * 400 < money; k++)
			{
				if ((i * 500 + j * 700 + k * 400) == money)
				{
					printf("ũ����(%d��), �����(%d����), �ݶ�(%d��)\n", i, j, k);
				}
			}
		}
	}
	printf("��� �����Ͻðڽ��ϱ�?\n");
	return 0;
}