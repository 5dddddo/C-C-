#pragma warning (disable : 4996)
#include <stdio.h>
void input(char *,int *);
int calcNum(int);
void outputNum(int);
int main()
{
	int m, n;
	input("�����Է� : ",&m);
	n = calcNum(m);
	outputNum(n);
	return 0;
}

void input(char *message, int *m)
{	
	while (1)
	{
		printf(message);
		if (scanf("%d", m) == 1)
		{
			if (getchar() == '\n')
			{
				if (*m > 0)
				{
					break;
				}
			}
		}
		else
		{
			printf("�ٽ��Է�.\n");
			fflush(stdin);
		}
	}
}

int calcNum(int m)
{
	int n = 1, sum = 0;
	while (1)
	{
		sum += n;
		if (m == sum)
		{
			break;
		}
		else if (m < sum)
		{
			return 0;
		}
		n++;
	}
	return n;
}

void outputNum(int n)
{	
	if (n != 0)
	{
		printf("������ %d��° ���Դϴ�.\n", n);
	}
	else if (n == 0)
	{
		printf("������ �հ� ��ġ���� �ʴ� ���Դϴ�.\n");
	}

}