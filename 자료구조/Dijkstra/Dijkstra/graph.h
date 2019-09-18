#pragma once
#pragma warning (disable : 4996)
#define MAX_VERTEX 100
#define WEIGHT_MAX 1000
#define NEWL printf("\n");

extern int check[];
typedef struct
{
	int graph[MAX_VERTEX][MAX_VERTEX];
	int vertexCnt;
	int edgeCnt;
}GraphMatrix;

void initGraph(GraphMatrix *gm, char *fileName);
void outputGraph(GraphMatrix *gm);