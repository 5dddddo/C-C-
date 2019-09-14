#pragma warning (disable : 4996)
#include <stdio.h>
#include<stdlib.h> // rand(), srand() 함수를 사용하기 위해서 인클루드 함 
#include<time.h> // time() 함수를 사용하기 위해서 인클루드 함 
void random(int,int,int (*)[5]);
void output(int(*)[5],int);
void sum1(int(*)[5],int);
void sum2(int(*)[5],int);
void sum3(int(*)[5],int);
void main()
{
	int row, str[5][5];
	srand(time(NULL)); // 프로그램 수행될때 마다 똑같은 난수가 발생되는것을 예방 
	// 아래 random()함수 사용전에 꼭 한번만 호출해 주어야함 
	// 시스템 시간을 난수 씨앗값으로 사용해서 매번 다른 난수가 발생함 
	// 주의사항 : 이부분은 프로그램 시작할때 딱 1회만 수행되게 해야함 
	// 여러번 수행시키면 프로그램의 실행속도를 매우 저하시키는 현상이 나타남 
	row = sizeof(str) / sizeof(str[0]);
	random(21, row, str); // 0~9사이의 난수를 발생시킴
	output(str, row);
	sum1(str, row);
	sum2(str, row);
	sum3(str, row);
}

// 난수발생 함수 - 과제 작성시 아래 함수를 복사하여 붙여놓고 사용하면됩니다. 
void random(int n, int row, int(*p)[5])
{
	int i, j, res=0;
	 // 0부터 n-1까지의 수중 난수 발생 
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
		printf("%d번 행 : ",i);
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

