#include <stdio.h>
#include <conio.h>
#include<stdlib.h> // rand(), srand() 함수를 사용하기 위해서 인클루드 함 
#include<time.h> // time() 함수를 사용하기 위해서 인클루드 함
void random(int, int, int *);
void ballCount(int, int *, int *, int *);
void output(int, int *, int *, int *);
void main()
{
	int size, ball = 0, strike = 0, i = 1;
	int cNum[4] = { 0 }; //컴퓨터 숫자
	size = sizeof(cNum) / sizeof(cNum[0]);
	srand(time(NULL)); // 프로그램 수행될때 마다 똑같은 난수가 발생되는것을 예방 
	// 아래 random()함수 사용전에 꼭 한번만 호출해 주어야함 
	// 시스템 시간을 난수 씨앗값으로 사용해서 매번 다른 난수가 발생함 
	// 주의사항 : 이부분은 프로그램 시작할때 딱 1회만 수행되게 해야함 
	// 여러번 수행시키면 프로그램의 실행속도를 매우 저하시키는 현상이 나타남 

	random(size,10,cNum); // 0~9사이의 난수를 발생시킴 
	while (1)
	{
		printf("# %d차 :",i++);
		ballCount(size, &ball, &strike, cNum);
		if (strike == 4)
		{
			printf("OK!!!\n");
			break;
		}
		output(size, &ball, &strike, cNum);
	}
	return;
}

// 난수발생 함수 - 과제 작성시 아래 함수를 복사하여 붙여놓고 사용하면됩니다. 
void random(int size,int n,int *cNum)
{
	int i, j;
	for (i = 0; i < size; i++)
	{
		cNum[i] = rand() % n;
		for (j = 0; j < i; j++)
		{
			if (cNum[j] == cNum[i])
			{
				i--;
				break;
			}
		}	
	}
}

void ballCount(int size,int *bc, int *sc,int *cNum)
{
	int i, j, temp;
	for (i = 0; i < size; i++)
	{
		temp = getche() - '0';
		for (j = 0; j < size; j++)
		{
			if (temp == cNum[j])
			{
				if (i == j)
				{
					++*sc;
				}
				else
				{
					++*bc;
				}
				break;
			}
		}
		printf(" ");
	}
}

void output(int size, int *bc, int *sc, int *cNum)
{
	if (*bc > 0 || (*sc > 0 && *sc < 4))
	{
		printf("%dS %dB\n", *sc, *bc);	
	}
	else if (*sc == 0 && *bc == 0)
	{
		printf("No!\n");
	}
	else if (*sc == 4)
	{
		printf("OK!!!\n");
	}
	*sc = 0;
	*bc = 0;
}