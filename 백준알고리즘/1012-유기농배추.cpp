#include <iostream>
using namespace std;
#include <vector>
int map[50][50];
bool visited[50][50];
int plusX[4] = { 0,0,-1,1 };
int plusY[4] = { -1,1,0,0 };
int n, m, k, cnt;
void dfs(int y, int x);
int main() {
	int tcCnt, x, y;
	cin >> tcCnt;
	for (int t = 1; t <= tcCnt; t++) {
		cin >> m >> n >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				map[i][j] = 0;
				visited[i][j] = false;
			}
		}
		cnt = 0;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			map[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && map[i][j]) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << endl;
	}
	return 0;
}

void dfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int newX = x + plusX[i];
		int newY = y + plusY[i];
		if (newX >= 0 && newY >= 0 && newX < m && newY < n) {
			if (map[newY][newX] && !visited[newY][newX])
				dfs(newY, newX);
		}
	}
}