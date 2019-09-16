#pragma warning (disable : 4996)
#include<stdlib.h> // rand(), srand() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
#include<time.h> // time() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
#include<stdio.h> 
int random(int);
int input();
int output(int,int,int *,int *);

int main()
{
	int num, n, a, i = 0, j = 0;
	srand(time(NULL)); // ���α׷� ����ɶ� ���� �Ȱ��� ������ �߻��Ǵ°��� ���� 
	// �Ʒ� random()�Լ� ������� �� �ѹ��� ȣ���� �־���� 
	// �ý��� �ð��� ���� ���Ѱ����� ����ؼ� �Ź� �ٸ� ������ �߻��� 
	// ���ǻ��� : �̺κ��� ���α׷� �����Ҷ� �� 1ȸ�� ����ǰ� �ؾ��� 
	// ������ �����Ű�� ���α׷��� ����ӵ��� �ſ� ���Ͻ�Ű�� ������ ��Ÿ�� 

	// �ݺ����� �̿��ؼ� 10���� ������ �߻����� ����غ��� 
	 // 0~2������ ������ �߻���Ŵ 
	while (1)
	{
		num = random(3);
		n = input();
		a = output(n, num,&i,&j);
		if (a == -1)
		{
			printf("���� ��� : %d�� %d��\n",j,i);
			break;
		}
	}
	return 0;
}

// �����߻� �Լ� - ���� �ۼ��� �Ʒ� �Լ��� �����Ͽ� �ٿ����� ����ϸ�˴ϴ�. 
int random(int n)
{
	int res;
	res = rand() % n; // 0���� n-1������ ���� ���� �߻� 
	return res;
}

int input()
{
	int n;

	while (1)
	{	
		printf("# ������ 0,������ 1, ���� 2 �߿��� �����ϼ��� : ");
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
			printf("�ٽ� �Է��Ͻÿ�.\n");
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
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n");
			*i += 1;
		}
		if (num == 1)
		{
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�.\n");
			*j += 1;
		}
		else if (num == 2)
		{
			printf("����� ���� ����, ��ǻ�ʹ� �� ���� : �����ϴ�.\n");
			return -1;
		}
		
	}
	else if (n == 1)
	{
		
		if (num == 0)
		{
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n");
			return -1;
		}
		else if (num == 1)
		{
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n");
			*i += 1;
		}
		else if (num == 2)
		{
			printf("����� ���� ����, ��ǻ�ʹ� �� ���� : �̰���ϴ�.\n");
			*j += 1;
		}
	}
	else if (n == 2)
	{
		if (num == 0)
		{
			printf("����� �� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�.\n");
			*j += 1;
		}
		else if (num == 1)
		{
			printf("����� �� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n");
			return -1;
		}
		else if (num == 2)
		{
			printf("����� �� ����, ��ǻ�ʹ� �� ���� : �����ϴ�.\n");
			*i += 1;
		}
	}
}