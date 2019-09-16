#pragma warning(disable : 4996)
#include <stdio.h>
int inputintNum();
void output(int);
int main()
{
	int station,fee;
	int i = 1;
	
	while (i <= 5)
	{
		station = inputintNum();
		if (station >= 1 && station <= 5)
		{
			fee = 600;
		}
		else if (station >= 6 && station <= 10)
		{
			fee = 800;
		}
		else if (station > 10)
		{
			fee = 800 + ((station - 9) / 2) * 100;
		}
		
		output(fee);
		i++;
	}
	return 0;
}

int inputintNum()
{
	int s,fee,res;
	while (1)
	{
		printf("역수를 입력하시오 :");
		scanf("%d", &s);
		if ( s >= 0 )
		{
			if (getchar() == '\n')
			{
				break;
			}

		}
		else
		{
			printf("Input Error\n");
			fflush(stdin);
		}
		
	}
	return s;
}

void output(int f)
{
	printf("요금 : %d원\n", f);
	return;
}