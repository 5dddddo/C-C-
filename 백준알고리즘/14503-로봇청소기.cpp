#include <iostream>
#include <queue>
using namespace std;
int map[50][50];
int N, M;
struct info {
	int x, y, d;
};
int dir[4][2] = { { -1,0 },{ 0,1 },{ 1,0 } ,{ 0,-1 } }; //ºÏµ¿³²¼­
int ans;
void dfs(info);
int main() {
	info cur;
	cin >> N >> M >> cur.x >> cur.y >> cur.d;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	dfs(cur);
	cout << ans << endl;
	return 0;
}

void dfs(info tmp) {
	int x = tmp.x;
	int y = tmp.y;
	int d = tmp.d;
	if (map[x][y] == 1) return;
	if (map[x][y] == 0) {
		map[x][y] = 2;
		ans++;
	}
	for (int i = 0; i < 4; i++) {
		int nd = (d + 3 - i) % 4;
		int nx = x + dir[nd][0];
		int ny = y + dir[nd][1];
		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
		if (map[nx][ny] != 0) continue;
		if (map[nx][ny] == 0) {
			dfs({ nx, ny, nd });
			return;
		}
	}
	int nx = x + dir[(d + 2) % 4][0];
	int ny = y + dir[(d + 2) % 4][1];
	dfs({ nx,ny,d });
}