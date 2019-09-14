#pragma warning (disable : 4996)
#include <stdio.h>
#include<stdlib.h> // rand(), srand() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
#include<time.h> // time() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
void random(int,int,int (*)[5]);
void output(int(*)[5],int);
void sum1(int(*)[5],int);
void sum2(int(*)[5],int);
void sum3(int(*)[5],int);
void main()
{
	int row, str[5][5];
	srand(time(NULL)); // ���α׷� ����ɶ� ���� �Ȱ��� ������ �߻��Ǵ°��� ���� 
	// �Ʒ� random()�Լ� ������� �� �ѹ��� ȣ���� �־���� 
	// �ý��� �ð��� ���� ���Ѱ����� ����ؼ� �Ź� �ٸ� ������ �߻��� 
	// ���ǻ��� : �̺κ��� ���α׷� �����Ҷ� �� 1ȸ�� ����ǰ� �ؾ��� 
	// ������ �����Ű�� ���α׷��� ����ӵ��� �ſ� ���Ͻ�Ű�� ������ ��Ÿ�� 
	row = sizeof(str) / sizeof(str[0]);
	random(21, row, str); // 0~9������ ������ �߻���Ŵ
	output(str, row);
	sum1(str, row);
	sum2(str, row);
	sum3(str, row);
}

// �����߻� �Լ� - ���� �ۼ��� �Ʒ� �Լ��� �����Ͽ� �ٿ����� ����ϸ�˴ϴ�. 
void random(int n, int row, int(*p)[5])
{
	int i, j, res=0;
	 // 0���� n-1������ ���� ���� �߻� 
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < 5; j++)
		{
			while (1)
			{
				res = rand() % n;
				if (res > 0)
				{
					p[i][j] = res;
					break;
				}
			}
		}
	}
}

void output(int(*p)[5], int row)
{
	int i, j;
	for (i = 0; i < row; i++)
	{
		printf("%d�� �� : ",i);
		for (j = 0; j < 5; j++)
		{
			printf("%2d ",p[i][j]);
		}
		printf("\n");
	}
}

void sum1(int(*p)[5], int row)
{
	int i, j, sum = 0;
	for (i = 0; i < row; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			sum += p[i][j];
		}
	}
	printf("sum1 = %3d\n", sum);
}
void sum2(int(*p)[5], int row)
{
	int i, sum = 0;
	for (i = 0; i < row; i++)
	{
		sum += p[i][i];
	}
	printf("sum2 = %3d\n", sum);
}
void sum3(int(*p)[5], int row)
{
	int i, j, sum = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; i > j; j++)
		{
			sum += p[i][j];
		}
	}
	printf("sum3 = %3d\n", sum);
}

