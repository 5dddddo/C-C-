#pragma warning (disable : 4996)
#include <stdio.h>
void input(char *, int *);
int calcNum(int,int,int);
void output(int);
int main()
{
	int a, r, num,n;
	input("���� �Է� : ", &a);
	input("���� �Է� : ", &r);
	input("������ �� �Է� : ", &num);
	n = calcNum(a,r,num);
	output(n);
	return 0;
}

void input(char *message, int *n)
{
	while (1)
	{
		printf(message);
		if (scanf("%d", n) == 1)
		{
			if (getchar() == '\n')
			{
				if (*n > 0)
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

int calcNum(int a, int r, int num)
{
	int n = 1;
	int res;
	res = a;

	while(1)
	{
		res *= r;
		n++;
		if (num == res)
		{
			break;
		}
		else if (num < res)
		{
			return 0;
		}
		
	}
	return n;
}

void output(int n)
{
	if (n != 0)
	{
		printf("%d��° ���Դϴ�.\n",n);
	}
	else
	{
		printf("������ ���ԵǾ� ���� �ʽ��ϴ�.\n");
	}
}