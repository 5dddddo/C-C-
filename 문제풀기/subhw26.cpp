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
	printf("***�ް� ������ �������ϴ�.\n\n");
	return 0;
}

int input()
{
	int e, i = 1;
	while (1)
	{
		printf("# ����� ���Ը� �Է��ϼ���(���� : g) : ");
		if (scanf("%d", &e) == 1)
		{
			if (getchar() == '\n')
			{
				if (e > 0 && e < 150)
				{
					printf("* ���߸��� ������ �峭���� ���ÿ�~^^\n");
					fflush(stdin);
				}
				else if (e >= 150 && e <= 500)
				{
					return e;
				}
				else if (e > 500)
				{
					printf("* Ÿ���� ������ �峭���� ���ÿ�~^^\n");
				}
				
			}	
		}
		else
		{
			printf("�ٽ� �Է��Ͻÿ�.\n");
			fflush(stdin);
		}
	}
}

void output(int i)
{
	printf("* ���� �ް��� �� : %d\n", i);
}