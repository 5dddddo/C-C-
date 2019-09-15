#pragma warning (disable : 4996)
#include<stdlib.h> // rand(), srand() 함수를 사용하기 위해서 인클루드 함 
#include<time.h> // time() 함수를 사용하기 위해서 인클루드 함 
#include<stdio.h> 
int random(int);
int input(int *,int *,int);
void output(int,int,int);
void main()
{
	int num, j, i = 1, n1 = 0, n2 = 100;
	srand(time(NULL)); // 프로그램 수행될때 마다 똑같은 난수가 발생되는것을 예방 
	// 아래 random()함수 사용전에 꼭 한번만 호출해 주어야함 
	// 시스템 시간을 난수 씨앗값으로 사용해서 매번 다른 난수가 발생함 
	// 주의사항 : 이부분은 프로그램 시작할때 딱 1회만 수행되게 해야함 
	// 여러번 수행시키면 프로그램의 실행속도를 매우 저하시키는 현상이 나타남 

	 // 반복문을 이용해서 10개의 난수를 발생시켜 출력해본다 
	num = random(101); // 0~100사이의 난수를 발생시킴
	while (1)
	{
		j = input(&n1,&n2,num);
		if (j < 0)
		{
			printf("우와~맞았당~~~추카추카~~%d번째 만에 맞추셨습니다.\n", i);
			break;
		}
		output(n1,n2,num);
		i++;
	}
	
}

// 난수발생 함수 - 과제 작성시 아래 함수를 복사하여 붙여놓고 사용하면됩니다. 
int random(int n)
{
	int res;
	res = rand() % n; // 0부터 n-1까지의 수중 난수 발생 
	return res;
}

int input(int *n1,int *n2,int num)
{
	int n;
	while (1)
	{
		printf("# 숫자를 입력하시오 : ");
		if (scanf("%d", &n) == 1)
		{
			if (getchar() == '\n')
			{
				if (n > 0)
				{
					if (num > n)
					{
						*n1 = n;
						return 1;
					}
					else if (num < n)
					{
						*n2 = n;
						return 1;
					}
					else
					{
						return -1;
					}
				}
			}
			else
			{
				printf("다시 입력하시오.\n");
				fflush(stdin);
			}
		}
		else
		{
			printf("다시 입력하시오.\n");
			fflush(stdin);
		}
	}
}

void output(int n1,int n2,int num)
{
	if (num != n1 || num != n2)
	{
		printf("%d 보다는 크고 %d 보다는 작습니다.\n", n1, n2);
	}

}

