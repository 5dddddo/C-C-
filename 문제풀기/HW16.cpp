#pragma warning(disable : 4996)
#include <stdio.h>
int input(char *);
int calcDay(int);
void output(int, int);

int main()
{
	int height, day;
	height = input("* �칰�� ���̸� �Է��Ͻÿ�(cm����) : ");
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
				printf("�ٽ� �Է�\n");
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