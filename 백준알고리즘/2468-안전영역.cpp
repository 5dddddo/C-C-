#include <iostream>
using namespace std;
int map[100][100];
bool visited[100][100];
int px[4] = { 0,0,-1,1 };
int py[4] = { -1,1,0,0 };
int n, maxHeight = -1, minHeight = 987654321;
int ans;
void dfs(int, int, int);
int main() {
	int cnt;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (maxHeight < map[i][j]) maxHeight = map[i][j];
			if (minHeight > map[i][j])  minHeight = map[i][j];
		}
	}
	if (minHeight == maxHeight) {
		cout << 1 << endl;
		return 0;
	}

	for (int k = minHeight; k < maxHeight; k++) {
		cnt = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				visited[i][j] = false;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && map[i][j] > k) {
					cnt++;
					dfs(i, j, k);
				}
			}
		}
		if (ans < cnt) ans = cnt;
	}
	cout << ans << endl;
	return 0;
}

void dfs(int x, int y, int h) {
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + px[i];
		int ny = y + py[i];
		if (nx >= 0 && ny >= 0 && nx < n&&ny < n) {
			if (!visited[nx][ny] && map[nx][ny] > h)
				dfs(nx, ny, h);
		}
	}

}