#include<stdio.h>
#include<malloc.h>
#include "graph.h"
void displayTitle(char *message);
void dijkstra(GraphMatrix *g, int vNum, int *weightArray, int *parent);
void printWeightArray(int *weightArray, int vNum, int vCnt);
void printParent(int *parent, int vCnt);
void pathPrint(int *parent, int * weightArray, int startvNum, int endVnum);

int main()
{
	GraphMatrix g;
	int weightArray[MAX_VERTEX];
	int parent[MAX_VERTEX];
	int i;

	initGraph(&g, "c:\\data\\graphData2.txt");

	displayTitle("[가중 그래프의 인접 행렬 출력]");
	outputGraph(&g);
	NEWL; NEWL;
	
	displayTitle("[가중치 변화 상태 출력]");
	printWeightArray(g.graph[5], 5, g.vertexCnt);
	dijkstra(&g, 5, weightArray, parent);

	displayTitle("[정점간의 부모, 자식관계 출력]");
	printParent(parent, g.vertexCnt);

	displayTitle("[F기준 각 정점으로의 path 출력]");
	for (i = 0; i < g.vertexCnt; ++i)
		pathPrint(parent, weightArray, 5, i);
	
	return 0;
}

void displayTitle(char *message)
{

	printf("\n-----------------------------------------------------\n");
	printf(" %s\n", message);
	printf("-----------------------------------------------------\n");
}

void dijkstra(GraphMatrix *g, int vNum, int *weightArray, int *parent)
{
	int i, minIndex, temp, min, dist,cnt = 0;

	for (i = 0; i < g->vertexCnt; i++)
	{
		weightArray[i] = g->graph[vNum][i];
		parent[i] = vNum;
		check[i] = 0;
	}
	check[vNum] = 1;
	
	while (cnt < g->vertexCnt-1)
	{
		min = 0;
		for (i = 1; i < g->vertexCnt; i++)
		{
			if (check[i] == 0)
			{
				if (weightArray[min] > weightArray[i])
				{
					min = i;
				}
			}
		}
		temp = weightArray[min];
		for (i = 0; i < g->vertexCnt; i++)
		{
			if (check[i] == 0)
			{
				if (weightArray[i] == temp)
				{
					minIndex = i;
					break;
				}
			}
		}
		check[minIndex] = 1;
		for (i = 0; i < g->vertexCnt; i++)
		{
			dist = weightArray[minIndex] + g->graph[minIndex][i];
			if (dist < weightArray[i])
			{
				weightArray[i] = dist;
				parent[i] = minIndex;
			}
		}

		printWeightArray(weightArray, minIndex, g->vertexCnt);
		cnt++;
	}
}
void printWeightArray(int *weightArray, int vNum, int vCnt)
{
	printf("%c : ", vNum + 'A');
	for (int i = 0; i < vCnt; i++)
		printf("%4d ", weightArray[i]);
	printf("\n");

}
void printParent(int *parent, int vCnt)
{
	int i;
	printf("child :   ");
	for (i = 0; i < vCnt; i++)
		printf("%c ", i + 'A');
	printf("\n");
	printf("Parent :  ");
	for (i = 0; i < vCnt; i++)
	{
		if (i == 5)
			printf("* ");
		else
			printf("%c ", parent[i] + 'A');
	}
}
void pathPrint(int *parent, int * weightArray, int startvNum, int endVnum)
{/*
	int i = startvNum;
	int j = endVnum;
	for (i = startvNum; i != endVnum;)
	{
		printf("%c -> ", i + 'A');
		i = parent[j];
		if (i != startvNum)
			printf("%c -> ", i + 'A');
		i = endVnum;
	}
	printf("%c (weight : %d) ", i + 'A',weightArray[i]);
	printf("\n");
	*/
	int i, temp, ary[11] = { 0 };
	temp = endVnum;
	if (startvNum != endVnum)
	{
		for (i = 0; i < 11; i++)
		{
			ary[i] = parent[temp];
			temp = parent[temp];
			if (temp == startvNum)
				break;
		}
		for (i = 10; i >= 0; i--)
		{
			if (ary[i] != 0)
				printf(" %c ->", ary[i] + 'A');
		}
		printf(" %c  (weight : %d)\n", endVnum + 'A', weightArray[endVnum]);
	}
	else
		printf(" %c  (weight : %d)\n", endVnum + 'A', 0);

}