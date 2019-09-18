#include <stdio.h>
#include <assert.h>
#include "graph.h"

int check[MAX_VERTEX];
void initGraph(GraphMatrix *gm, char *fileName)
{

	int i, j, k, w = 0;
	char str[3];
	FILE *fp;
	fp = fopen(fileName, "rt");
	assert(fp != NULL);
	fscanf(fp, "%d%d", &gm->vertexCnt, &gm->edgeCnt);
	for (i = 0; i < gm->vertexCnt; i++)
	{
		for (j = 0; j < gm->vertexCnt; j++)
		{
			gm->graph[i][j] = 1000;
			if (i == j)
				gm->graph[i][j] = 0;
		}
	}
	for (k = 0; k < gm->edgeCnt; k++)
	{
		fscanf(fp, "%s%d", str, &w);
		gm->graph[str[0] - 'A'][str[1] - 'A'] = w;
		gm->graph[str[1] - 'A'][str[0] - 'A'] = w;
	}
	fclose(fp);
}
void outputGraph(GraphMatrix *gm)
{
	int i, j;
	for (i = 0; i < gm->vertexCnt; i++)
	{
		printf("%c ", i + 'A');
		for (j = 0; j < gm->vertexCnt; j++)
			printf("%4d ", gm->graph[i][j]);
		printf("\n");
	}

}
