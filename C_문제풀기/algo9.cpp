#pragma warning (disable : 4996)
#include <stdio.h>
void input(char *,int *);
int calcodd(int);
int maxodd(int, int);
void output(int,int);
int main()
{
	int n1, n2, n3, n4, n5, max = 0, sum = 0;
	input("���� �Է� : ", &n1);
	input("���� �Է� : ", &n2);
	input("���� �Է� : ", &n3);
	input("���� �Է� : ", &n4);
	input("���� �Է� : ", &n5);
	sum += calcodd(n1);
	sum += calcodd(n2);
	sum += calcodd(n3);
	sum += calcodd(n4);
	sum += calcodd(n5);
	max = maxodd(max, n1);
	max = maxodd(max, n2);
	max = maxodd(max, n3);
	max = maxodd(max, n4);
	max = maxodd(max, n5);
	output(sum,max);
	return 0;
}

void input(char *m, int *n)
{
	while (1)
	{
		printf(m);
		if (scanf("%d", n) == 1)
		{
			if (getchar() == '\n')
			{
				if (*n > 0)
				{
					break;
				}
				else
				{
					printf("�ٽ��Է�.\n");
					fflush(stdin);
				}
			}
			else
			{
				printf("�ٽ��Է�.\n");
				fflush(stdin);
			}
		}
		else
		{
			printf("�ٽ��Է�.\n");
			fflush(stdin);
		}
	}
}

int calcodd(int n)
{
	int sum = 0;
	if (n % 2 == 1)
	{
		sum = n;
		return sum;
	}
}

int maxodd(int max,int n)
{
	if (n % 2 == 1)
	{
		if (n >= max)
		{
			return n;
		}
		else
		{
			return max;
		}
	}
	return max;
}
void output(int sum,int max)
{
	if (sum != 0)
	{
		printf("�� : %d\n", sum);
		printf("�ִ밪 : %d\n", max);
	}
	else
	{
		printf("Ȧ���� �Էµ��� �ʾҽ��ϴ�.\n");
	}
}