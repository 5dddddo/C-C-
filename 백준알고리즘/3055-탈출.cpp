#include <iostream>
#include <queue>
using namespace std;
int R, C;
char map[50][50];
bool visited[50][50];
int dir[4][2] = { {-1,0},{ 1, 0},{ 0, -1},{0 , 1} };
int bfs();
struct info {
	int x, y;
	int cnt;
	bool water;
};
queue <pair<int, int>> que;
queue <info> k;
pair<int, int> s, d;
int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == '*') {
				que.push({ i,j }); continue;
			}
			if (map[i][j] == 'D') d = { i,j };
			if (map[i][j] == 'S') s = { i,j };
		}
	}
	int ans = bfs();
	if (ans) cout << ans << endl;
	else cout << "KAKTUS" << endl;
	return 0;
}

int bfs() {
	for (int i = 0; i < que.size(); i++)
		k.push({ que.front().first,que.front().second,0,1 });

	k.push({ s.first,s.second,0,0 });
	while (!k.empty()) {
		int x = k.front().x;
		int y = k.front().y;
		int cnt = k.front().cnt;
		bool water = k.front().water;
		k.pop();

		if (!water && x == d.first && y == d.second) return cnt;
		if (!water && visited[x][y]) continue;
		else if (!water && !visited[x][y]) visited[x][y] = true;

		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
			if (map[nx][ny] == 'X' || map[nx][ny] == '*') continue;
			if (water && map[nx][ny] == 'D') continue;
			if (water) map[nx][ny] = '*';
			k.push({ nx, ny, cnt + 1, water });
		}
	}
	return 0;
}

