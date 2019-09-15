#pragma warning (disable : 4996)
#include<stdlib.h> // rand(), srand() 함수를 사용하기 위해서 인클루드 함 
#include<time.h> // time() 함수를 사용하기 위해서 인클루드 함 
#include<stdio.h> 
int random(int);
int input();
int output(int,int,int *,int *);

int main()
{
	int num, n, a, i = 0, j = 0;
	srand(time(NULL)); // 프로그램 수행될때 마다 똑같은 난수가 발생되는것을 예방 
	// 아래 random()함수 사용전에 꼭 한번만 호출해 주어야함 
	// 시스템 시간을 난수 씨앗값으로 사용해서 매번 다른 난수가 발생함 
	// 주의사항 : 이부분은 프로그램 시작할때 딱 1회만 수행되게 해야함 
	// 여러번 수행시키면 프로그램의 실행속도를 매우 저하시키는 현상이 나타남 

	// 반복문을 이용해서 10개의 난수를 발생시켜 출력해본다 
	 // 0~2사이의 난수를 발생시킴 
	while (1)
	{
		num = random(3);
		n = input();
		a = output(n, num,&i,&j);
		if (a == -1)
		{
			printf("게임 결과 : %d승 %d무\n",j,i);
			break;
		}
	}
	return 0;
}

// 난수발생 함수 - 과제 작성시 아래 함수를 복사하여 붙여놓고 사용하면됩니다. 
int random(int n)
{
	int res;
	res = rand() % n; // 0부터 n-1까지의 수중 난수 발생 
	return res;
}

int input()
{
	int n;

	while (1)
	{	
		printf("# 바위는 0,가위는 1, 보는 2 중에서 선택하세요 : ");
		if (scanf("%d", &n) == 1)
		{
			if (getchar() == '\n')
			{
				if (n >= 0 && n <= 2)
				{
					return n;
				}
			}
		}
		else
		{
			printf("다시 입력하시오.\n");
			fflush(stdin);
		}
	}
}

int output(int n, int num, int *i, int *j)
{
	if (n == 0)
	{
		if (num == 0)
		{
			printf("당신은 바위 선택, 컴퓨터는 바위 선택 : 비겼습니다.\n");
			*i += 1;
		}
		if (num == 1)
		{
			printf("당신은 바위 선택, 컴퓨터는 가위 선택 : 이겼습니다.\n");
			*j += 1;
		}
		else if (num == 2)
		{
			printf("당신은 바위 선택, 컴퓨터는 보 선택 : 졌습니다.\n");
			return -1;
		}
		
	}
	else if (n == 1)
	{
		
		if (num == 0)
		{
			printf("당신은 가위 선택, 컴퓨터는 바위 선택 : 졌습니다.\n");
			return -1;
		}
		else if (num == 1)
		{
			printf("당신은 가위 선택, 컴퓨터는 가위 선택 : 비겼습니다.\n");
			*i += 1;
		}
		else if (num == 2)
		{
			printf("당신은 가위 선택, 컴퓨터는 보 선택 : 이겼습니다.\n");
			*j += 1;
		}
	}
	else if (n == 2)
	{
		if (num == 0)
		{
			printf("당신은 보 선택, 컴퓨터는 바위 선택 : 이겼습니다.\n");
			*j += 1;
		}
		else if (num == 1)
		{
			printf("당신은 보 선택, 컴퓨터는 가위 선택 : 졌습니다.\n");
			return -1;
		}
		else if (num == 2)
		{
			printf("당신은 보 선택, 컴퓨터는 보 선택 : 비겼습니다.\n");
			*i += 1;
		}
	}
}