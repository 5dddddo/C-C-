#pragma warning (disable : 4996)
#include <stdio.h>
int input1();
int input2(int);
void output(int,int);
int main()
{
	int num1, num2;
	num1 = input1();
	num2 = input2(num1);
	output(num1, num2);
	return 0;
}

int input1()
{
	int n;
	while (1)
	{
		printf("# ���۰��� �Է��ϼ��� : ");
		if (scanf("%d", &n) == 1)
		{
			if (getchar() == '\n')
			{
				if (n > 0)
				{
					return n;
				}
			}
		}
		else
		{
			fflush(stdin);
		}
	}
	return n;
}
int input2(int n1)
{
	int n2;
	while (1)
	{
		printf("# ������ �Է��ϼ��� : ");
		if (scanf("%d", &n2) == 1)
		{
			if (getchar() == '\n')
			{
				if (n2 > n1)
				{
					return n2;
				}
				else
				{
					fflush(stdin);
				}
			}
			else
			{
				fflush(stdin);
			}
		}
		else
		{
			fflush(stdin);
		}
	}
}

void output(int n1, int n2)
{
	char m;
	int i, sum = 0;
	while (1)
	{
		printf("%d~%d ������ ¦���� ���� ���ұ��? Ȧ���� ���� ���ұ��?(¦�� :e/Ȧ��:o) :  ",n1,n2);
		if (scanf("%c", &m) == 1)
		{
			if (m == 'e')
			{
				if (n1 % 2 == 0)
				{
					printf("%d~%d������ ¦��(", n1, n2);
					for (i = n1; i <= n2;)
					{
						printf("%d ", i);
						sum += i;
						i += 2;
					}
					printf(")�� ���� %d�Դϴ�.\n", sum);
					break;
				}
				else
				{
					printf("%d~%d������ ¦��(", n1, n2);
					for (i = n1 + 1; i <= n2;)
					{
						printf("%d ", i);
						sum += i;
						i += 2;
					}
					printf(")�� ���� %d�Դϴ�.\n", sum);
					break;
				}
			}
			else if (m == 'o')
			{
				if (n1 % 2 == 0)
				{
					printf("%d~%d������ Ȧ��(", n1, n2);
					for (i = n1 + 1; i <= n2;)
					{
						printf("%d ", i);
						sum += i;
						i += 2;
					}
					printf(")�� ���� %d�Դϴ�.\n", sum);
					break;
				}
				else
				{
					printf("%d~%d������ Ȧ��(", n1, n2);
					for (i = n1; i <= n2;)
					{
						printf("%d ", i);
						sum += i;
						i += 2;
					}
					printf(")�� ���� %d�Դϴ�.\n", sum);
					break;
				}
				
			}
			else
			{
				fflush(stdin);
			}
		}
		else
		{
			fflush(stdin);
		}
	}
}