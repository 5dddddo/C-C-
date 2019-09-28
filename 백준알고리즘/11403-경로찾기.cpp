#include <stdio.h>
int Graph[101][101];
bool visited[101][101];
int n;
void dfs(int, int, int);
int main() {
	scanf("%d",&n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &Graph[i][j]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (Graph[i][j])
				dfs(i, i, j);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			printf("%d ", Graph[i][j]);
		printf("\n");
	}
	return 0;
}

void dfs(int pos, int start, int next) {
	Graph[pos][next] = 1;
	visited[pos][next] = true;
	for (int i = 1; i <= n; i++) {
		if (!visited[pos][i] && Graph[next][i])
			dfs(pos, next, i);
	}

}