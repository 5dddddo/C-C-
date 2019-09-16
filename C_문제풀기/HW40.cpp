#include <stdio.h>
#include <conio.h>
#include<stdlib.h> // rand(), srand() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
#include<time.h> // time() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� ��
void random(int, int, int *);
void ballCount(int, int *, int *, int *);
void output(int, int *, int *, int *);
void main()
{
	int size, ball = 0, strike = 0, i = 1;
	int cNum[4] = { 0 }; //��ǻ�� ����
	size = sizeof(cNum) / sizeof(cNum[0]);
	srand(time(NULL)); // ���α׷� ����ɶ� ���� �Ȱ��� ������ �߻��Ǵ°��� ���� 
	// �Ʒ� random()�Լ� ������� �� �ѹ��� ȣ���� �־���� 
	// �ý��� �ð��� ���� ���Ѱ����� ����ؼ� �Ź� �ٸ� ������ �߻��� 
	// ���ǻ��� : �̺κ��� ���α׷� �����Ҷ� �� 1ȸ�� ����ǰ� �ؾ��� 
	// ������ �����Ű�� ���α׷��� ����ӵ��� �ſ� ���Ͻ�Ű�� ������ ��Ÿ�� 

	random(size,10,cNum); // 0~9������ ������ �߻���Ŵ 
	while (1)
	{
		printf("# %d�� :",i++);
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

// �����߻� �Լ� - ���� �ۼ��� �Ʒ� �Լ��� �����Ͽ� �ٿ����� ����ϸ�˴ϴ�. 
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