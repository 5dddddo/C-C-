#pragma warning(disable :4996)
#include <stdio.h>
#include <assert.h>
#define MAX_CNT 100
int weight[MAX_CNT + 1];
int value[MAX_CNT + 1];
int n;
int totWeight;
void fileLoad(char * fileName);
int knapsack(int itemNum,int remainWeight);
int main()
{
	fileLoad("c:\\data\\knapsack3.txt");
	printf("최대 가치 :%d\n\n", knapsack(1,totWeight));
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
int knapsack(int itemNum, int remainWeight)
{
	int tmp1= 0,tmp2;
	if (itemNum > n) return 0;
	if (weight[itemNum] > remainWeight)
		return knapsack(itemNum + 1, remainWeight);
	else if (weight[itemNum] < remainWeight)
	{
		tmp1 = knapsack(itemNum + 1, remainWeight - weight[itemNum]);
		tmp2 = knapsack(itemNum + 1, remainWeight);
	}
	
	if (value[tmp1] > value[tmp2])
		return tmp1;

}
