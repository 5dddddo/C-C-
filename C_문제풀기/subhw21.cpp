#pragma warning (disable : 4996)
#include<stdlib.h> // rand(), srand() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
#include<time.h> // time() �Լ��� ����ϱ� ���ؼ� ��Ŭ��� �� 
#include<stdio.h> 
int random(int);
int input(int *,int *,int);
void output(int,int,int);
void main()
{
	int num, j, i = 1, n1 = 0, n2 = 100;
	srand(time(NULL)); // ���α׷� ����ɶ� ���� �Ȱ��� ������ �߻��Ǵ°��� ���� 
	// �Ʒ� random()�Լ� ������� �� �ѹ��� ȣ���� �־���� 
	// �ý��� �ð��� ���� ���Ѱ����� ����ؼ� �Ź� �ٸ� ������ �߻��� 
	// ���ǻ��� : �̺κ��� ���α׷� �����Ҷ� �� 1ȸ�� ����ǰ� �ؾ��� 
	// ������ �����Ű�� ���α׷��� ����ӵ��� �ſ� ���Ͻ�Ű�� ������ ��Ÿ�� 

	 // �ݺ����� �̿��ؼ� 10���� ������ �߻����� ����غ��� 
	num = random(101); // 0~100������ ������ �߻���Ŵ
	while (1)
	{
		j = input(&n1,&n2,num);
		if (j < 0)
		{
			printf("���~�¾Ҵ�~~~��ī��ī~~%d��° ���� ���߼̽��ϴ�.\n", i);
			break;
		}
		output(n1,n2,num);
		i++;
	}
	
}

// �����߻� �Լ� - ���� �ۼ��� �Ʒ� �Լ��� �����Ͽ� �ٿ����� ����ϸ�˴ϴ�. 
int random(int n)
{
	int res;
	res = rand() % n; // 0���� n-1������ ���� ���� �߻� 
	return res;
}

int input(int *n1,int *n2,int num)
{
	int n;
	while (1)
	{
		printf("# ���ڸ� �Է��Ͻÿ� : ");
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
				printf("�ٽ� �Է��Ͻÿ�.\n");
				fflush(stdin);
			}
		}
		else
		{
			printf("�ٽ� �Է��Ͻÿ�.\n");
			fflush(stdin);
		}
	}
}

void output(int n1,int n2,int num)
{
	if (num != n1 || num != n2)
	{
		printf("%d ���ٴ� ũ�� %d ���ٴ� �۽��ϴ�.\n", n1, n2);
	}

}

