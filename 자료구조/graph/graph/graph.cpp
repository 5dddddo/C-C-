#include <stdio.h>
#include <assert.h>
#include <malloc.h>
#include "graph.h"
#include "stack.h"
#include "queue.h"

int check[MAX_VERTEX];
void initGraph(GraphMatrix *gm, char *fileName)
{
	int i, j, k;
	char str[3];
	FILE *fp;
	fp = fopen(fileName, "rt");
	assert(fp != NULL);
	fscanf(fp, "%d%d", &gm->vertexCnt, &gm->edgeCnt);
	for (i = 0; i < gm->vertexCnt; i++)
	{
		for (j = 0; j < gm->vertexCnt; j++)
			gm->graph[i][j] = 0;
	}
	for (k = 0; k < gm->edgeCnt; k++)
	{
		fscanf(fp, "%s", str);
		gm->graph[str[0] - 'A'][str[1] - 'A'] = 1;
		gm->graph[str[1] - 'A'][str[0] - 'A'] = 1;
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
			printf("%d ", gm->graph[i][j]);
		printf("\n");
	}

}
void DFS_Matrix(GraphMatrix *gm)
{
	int i;
	for (i = 0; i < gm->vertexCnt; ++i)
		check[i] = 0;
	for (i = 0; i < gm->vertexCnt; ++i)
		if (check[i] == 0)
			DFS_recursive(gm, i);
	return;
}

void DFS_recursive(GraphMatrix *gm, int vNum)
{
	int j;
	check[vNum] = 1;	
	visit(vNum);

	for (j = 0; j<gm->vertexCnt; j++)
		if (gm->graph[vNum][j] != 0)
			if (check[j] == 0)
			{
				check[j] = 1;
				DFS_recursive(gm, j);
			}
}
void visit(int vNum)
{
	printf("%c ", 'A' + vNum);
}
void nrDFS_Matrix(GraphMatrix *gm)
{
	int i, j;
	Stack stk;
	initStack(&stk, 18);
	for (i = 0; i < gm->vertexCnt; i++)
		check[i] = 0;
	for (i = 0; i < gm->vertexCnt; i++)
	{
		if (check[i] != 1)
		{
			push(&stk, i);
			check[i] = 1;
			while (!isStackEmpty(&stk))
			{
				pop(&stk, &i);
				visit(i);
				for (j = 0; j <= gm->vertexCnt; j++)
					if (gm->graph[i][j] == 1)
						if (check[j] != 1)
						{
							push(&stk, j);
							check[j] = 1;
						}
			}	
		}
	}
	destroyStack(&stk);
	return;
}
void BFS_Matrix(GraphMatrix *gm)
{
	int i, j;
	Queue que;
	initQueue(&que, 18);
	for (i = 0; i < gm->vertexCnt; i++)
		check[i] = 0;
	for (i = 0; i < gm->vertexCnt; i++)
	{
		if (check[i] != 1)
		{
			enqueue(&que, i);
			check[i] = 1;
		}
		while (!isQueueEmpty(&que))
		{
			dequeue(&que, &i);
			visit(i);
			for (j = 0; j <= gm->vertexCnt; j++)
				if (gm->graph[i][j] == 1)
					if (check[j] != 1)
					{
						enqueue(&que, j);
						check[j] = 1;
					}
		}
	}
	destroyQueue(&que);
}
int countGraphComponents(GraphMatrix *gm)
{
	int i, j, cnt = 0;
	Queue que;
	initQueue(&que, 18);
	for (i = 0; i < gm->vertexCnt; i++)
		check[i] = 0;
	for (i = 0; i < gm->vertexCnt; i++)
	{
		if (check[i] != 1)
		{
			enqueue(&que, i);
			check[i] = 1;
		}
		while (!isQueueEmpty(&que))
		{
			dequeue(&que, &i);

			for (j = 0; j <= gm->vertexCnt; j++)
			{
				if (gm->graph[i][j] == 1)
				{
					if (check[j] != 1)
					{
						enqueue(&que, j);
						check[j] = 1;
					}
				}
			}
			visit(i);
		}
		cnt++;
		printf("\n");
	}
	destroyQueue(&que);
	return cnt;
}
void initGraph_List(GraphList *g, char *fileName)
{
	int i, j;
	char str[3];
	FILE *fp;
	Node *np;
	fp = fopen(fileName, "rt");
	assert(fp != NULL);
	fscanf(fp, "%d%d", &g->vertexCnt, &g->edgeCnt);
	for (i = 0; i < g->vertexCnt; i++)
			g->graph[i] = NULL;
	
	for (j = 0; j < g->edgeCnt; j++)
	{
		fscanf(fp, "%s", str);
		np = (Node *)calloc(1, sizeof(Node));
		np->vertex = str[1] - 'A';
		if (g->graph[str[0] - 'A'] != NULL)
			np->next = g->graph[str[0] - 'A'];
		g->graph[str[0] - 'A'] = np;

		np = (Node *)calloc(1, sizeof(Node));
		np->vertex = str[0] - 'A';
		if (g->graph[str[1] - 'A'] != NULL)
			np->next = g->graph[str[1] - 'A'];
		g->graph[str[1] - 'A'] = np;
	}
	fclose(fp);
}
void outputGraph_List(GraphList *g)
{
	Node *p;
	int i;
		for (i = 0; i < g->vertexCnt; i++)
		{
			printf("%c : ", i + 'A');
			p = g->graph[i];
			while (p != NULL)
			{
				printf("%c  ", p->vertex + 'A');
				p = p->next;
			}
			printf("\n");
		}
}
int addNode(GraphList *g, int vNum1, int vNum2)
{
	return 0;
}
void destroyGraph_List(GraphList *g)
{
	Node *p, *n;
	n = NULL;
	int i;
	for (i = 0; i < g->vertexCnt; i++)
	{
		while (g->graph[i] != 0)
		{
			p = g->graph[i];
			g->graph[i] = p->next;
			free(p);
		}
	}

}

