#pragma warning(disable :4996)
#include <stdio.h>
#include <assert.h>
#define MAX_CNT 100
int weight[MAX_CNT+1];
int value[MAX_CNT+1];
int n;
int totWeight;
void fileLoad(char * fileName);
int knapsack(void);
int makePermutaionTable(int(*indexArt)[4]);
int main()
{
	fileLoad("c:\\data\\knapsack1.txt");
	printf("최대 가치 :%d\n\n", knapsack());
	return 0;
}

void fileLoad(char * fileName)
{
	FILE *fp;
	int i;
	fp = fopen(fileName, "rt");
	assert(fp != NULL);
	fscanf(fp, "%d %d\n", &n, &totWeight);
	for (i = 1; i < totWeight; i++)
	{
		fscanf(fp, "%d %d \n", &weight[i], &value[i]);
	}
	fclose(fp);
	return;
}
int knapsack(void)
{
	int i, k, maxWeight[2] = {}, totVi[2] = {};
	int ary[24][4];
	makePermutaionTable(ary);
	
	for (i = 1; i < 24; i++)
	{
		k = 0;
		maxWeight[0] = 0;
		totVi[0] = 0;
		while (k < 4)
		{
			maxWeight[0] += weight[ary[i][k]];
			totVi[0] += value[ary[i][k]];
			if (totWeight < maxWeight[0])
			{
				maxWeight[0] -= weight[ary[i][k]];
				totVi[0] -= value[ary[i][k]];
				break;
			}
			k++;
		}
		if (totVi[1] < totVi[0])
			totVi[1] = totVi[0];
	}
	return totVi[1];
}
int makePermutaionTable(int(*indexAry)[4])
{
	int i, j, k, l;  // iterator
	int cnt = 0;  // 순열의 개수 저장 변수
	for (i = 1; i <= n; ++i)
	{
		for (j = 1; j <= n; ++j)
		{
			if (j != i)
			{
				for (k = 1; k <= n; ++k)
				{
					if (k != i && k != j)
					{
						for (l = 1; l <= n; ++l)
						{
							if (l != i && l != j && l != k)
							{
								indexAry[cnt][0] = i;
								indexAry[cnt][1] = j;
								indexAry[cnt][2] = k;
								indexAry[cnt][3] = l;
								++cnt;  // 순열의 개수 카운트
							}

						}
					}
				}
			}
		}
	}
	return cnt;
}