#pragma once
#pragma warning (disable : 4996)
#define MAX_VERTEX 100
#define Newl printf("\n");

extern int check[];
typedef struct
{
	int graph[MAX_VERTEX][MAX_VERTEX];
	int vertexCnt;
	int edgeCnt;
}GraphMatrix;

void initGraph(GraphMatrix *gm, char *fileName);
void outputGraph(GraphMatrix *gm);
void DFS_Matrix(GraphMatrix *gm);
void DFS_recursive(GraphMatrix *gm, int vNum);
void visit(int vNum);
void nrDFS_Matrix(GraphMatrix *gm);
void BFS_Matrix(GraphMatrix *gm);
int countGraphComponents(GraphMatrix *gm);

typedef struct _node
{
	int vertex;
	struct _node *next;
}Node;

typedef struct
{
	Node *graph[MAX_VERTEX];
	int vertexCnt;
	int edgeCnt;
}GraphList;

void initGraph_List(GraphList *g, char *fileName);
void outputGraph_List(GraphList *g);
int addNode(GraphList *g, int vNum1, int vNum2);
void destroyGraph_List(GraphList *g);

