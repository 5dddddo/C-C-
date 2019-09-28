#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
char map[50][50];
int visited[50][50];
int dir[4][2] = { {-1,0},{ 1,0 },{0 , -1},{ 0,1 } };
int R, C, ans = -1;
queue <pair<int, int>> que;
void bfs();
int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] == 'L') {
				que.push({ i,j });
				bfs();
				memset(visited, 0, sizeof(visited));
			}
		}
	}
	cout << ans << endl;
	return 0;
}

void bfs() {
	while (!que.empty()) {
		pair<int, int> tmp = que.front();
		que.pop();
		for (int i = 0; i < 4; i++) {
			int nx = tmp.first + dir[i][0];
			int ny = tmp.second + dir[i][1];
			if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
				if (!visited[nx][ny] && map[nx][ny] == 'L') {
					que.push({ nx,ny });
					visited[nx][ny] = visited[tmp.first][tmp.second] + 1;
					if (visited[nx][ny] > ans) {
						ans = visited[nx][ny];
					}
				}
			}
		}
	}
}