#include <iostream>
#include <queue>
using namespace std;
char map[50][50];
bool visited[50][50][64];
bool flag = false;
int N, M, cnt;
void bfs(pair<int,int>);
int dir[4][2] = { {-1,0},{ 1, 0},{0 ,-1},{ 0,1 } };
struct info {
	int x, y, key;
};
queue <info> que;
int main() {
	cin >> N >> M;
	pair<int,int> start;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == '0') {
				start.first = i;
				start.second = j;
			}
		}
	}
	bfs(start);

	return 0;
}
void bfs(pair<int, int> s) {
	que.push({ s.first, s.second, 0 });
	visited[s.first][s.second][0] = true;

	while (!que.empty()) {
		int size = que.size();
		while (size--) {
			info tmp = que.front();
			que.pop();
			int x = tmp.x;
			int y = tmp.y;
			int k = tmp.key;
			cout << x << ' ' << y << endl;
			if (map[x][y] == '1') {
				flag = true; break;
			}
			for (int i = 0; i < 4; i++) {
				int nx = tmp.x + dir[i][0];
				int ny = tmp.y + dir[i][1];
				int nk = k;
				if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
					if (map[nx][ny] == '#') continue;
					if (map[nx][ny] >= 'A' && map[nx][ny] <= 'F')
						if (!(nk &(1 << (map[nx][ny] - 'A'))))
							continue;
					if (map[nx][ny] >= 'a' && map[nx][ny] <= 'f')
						nk |= (1 << (map[nx][ny] - 'a'));
					if (visited[nx][ny][nk]) continue;
					que.push({ nx,ny,nk });
					visited[nx][ny][nk] = true;
				}
			}
		}
		if (flag) break;
		else cnt++;
	}
	if (flag) cout << cnt << endl;
	else cout << "-1" << endl;
}