#pragma warning(disable : 4996)
#include <stdio.h>
int input(char *);
int calcDay(int);
void output(int, int);

int main()
{
	int height, day;
	height = input("* 우물의 깊이를 입력하시오(cm단위) : ");
	//day = calcDay(height);
	//output(height, day);
	return 0;
}

int input(char * message)
{
	int h;
	int a;
	while (1)
	{
		printf(message);
		a = scanf("%d", &h);
		if (a == 1)
		{
			if (h >= 0 && getchar() == '\n')
			{
				break;
			}
			else if (h<0 && getchar() == '\n')
			{	
				printf("다시 입력\n");
				continue;
			}
			else
			{
				break;
			}
		}
		return h;
	}
}

/*int calcDay(int h)
{
	int day;

}*/