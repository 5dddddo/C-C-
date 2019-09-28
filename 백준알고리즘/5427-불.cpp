#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char map[1000][1000];
bool visited[1000][1000];
int dir[4][2] = { {-1,0},{1 ,0 },{0 ,-1 },{ 0, 1} };
struct info {
	int x, y, cnt;
	bool fire;
};
int h, w;
queue <pair<int, int>> tmp;
int bfs();
pair<int, int> start;
int main() {
	int tcCnt;
	cin >> tcCnt;
	for (int t = 0; t < tcCnt; t++) {
		cin >> w >> h;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
				if (map[i][j] == '*') tmp.push({ i, j });
				if (map[i][j] == '@') start = { i,j };
			}
		}
		memset(visited, 0, sizeof(visited));
		int ans = bfs();
		if (ans) cout << ans << endl;
		else cout << "IMPOSSIBLE" << endl;
	}
	return 0;
}
int bfs() {
	queue <info> que;
	int size = tmp.size();
	for (int i = 0; i < size; i++) {
		que.push({ tmp.front().first,tmp.front().second,0,1 });
		tmp.pop();
	}
	visited[start.first][start.second] = true;
	que.push({ start.first,start.second,0,0 });

	while (!que.empty()) {
		info next = que.front();
		que.pop();
		int x = next.x;
		int y = next.y;
		int cnt = next.cnt;
		bool fire = next.fire;

		if (!fire && (x == 0 || x == h - 1 || y == 0 || y == w - 1))
			return cnt + 1;
		if (!fire && visited[x][y]) continue;
		else if (!fire && !visited[x][y]) visited[x][y] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
			if (map[nx][ny] == '#' || map[nx][ny] == '*') continue;

			if (fire) map[nx][ny] = '*';
			que.push({ nx,ny,cnt + 1,fire });
		}
	}
	return 0;

}

