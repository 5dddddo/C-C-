#pragma warning (disable :4996)
#include <stdio.h>
int input();
void output(int);
int main()
{
	int i,egg;
	for (i = 0; i < 10;)
	{
		egg = input();
		if (egg >= 150 && egg <= 500)
		{
			i++;
		}
		output(i);
	}
	printf("***달걀 포장이 끝났습니다.\n\n");
	return 0;
}

int input()
{
	int e, i = 1;
	while (1)
	{
		printf("# 계란의 무게를 입력하세요(단위 : g) : ");
		if (scanf("%d", &e) == 1)
		{
			if (getchar() == '\n')
			{
				if (e > 0 && e < 150)
				{
					printf("* 메추리알 가지고 장난하지 마시오~^^\n");
					fflush(stdin);
				}
				else if (e >= 150 && e <= 500)
				{
					return e;
				}
				else if (e > 500)
				{
					printf("* 타조알 가지고 장난하지 마시오~^^\n");
				}
				
			}	
		}
		else
		{
			printf("다시 입력하시오.\n");
			fflush(stdin);
		}
	}
}

void output(int i)
{
	printf("* 현재 달걀의 수 : %d\n", i);
}