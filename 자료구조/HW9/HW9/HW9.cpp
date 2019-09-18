#pragma warning (disable : 4996)
#include <stdio.h>
int main()
{
	int i, num[7]  , maybeWin;
	int check1[10] = {}, check2[10] = {};
	int card[6] = {};
	while (1)
	{
		for(i = 0 ; i <10 ; i++)
		{	
			check1[i] = 0;;
			check2[i] = 0;
		}
		maybeWin = 0;

		printf("# 0~9 사이의 숫자 6개를 입력하시오 :");

		if (scanf("%d %d %d %d %d %d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5]))
		{
			
			for (i = 0; i < 6; i++)
			{
				card[i] = num[i];
				check1[card[i]] += 1;
			}
		}
		else break;

		for (i = 0; i < 4; i++)
		{
			if ((check1[i] > 0) && (check1[i + 1] > 0) && (check1[i + 2] > 0))
				maybeWin++;
		}

		for (i = 0; i < 6; i++)
		{
			check2[card[i]] += 1;
			if (check2[card[i]] >= 3)
				maybeWin++;
		}

		for (i = 0; i < 6; i++)
			printf(" %d ", card[i]);
		if (maybeWin > 0)
			printf("는 Maybe Win 입니다.\n");
		else
			printf("는 Maybe Win 이 아닙니다.\n");

	}
	return 0;
}