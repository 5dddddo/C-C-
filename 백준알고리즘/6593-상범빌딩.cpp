#include <iostream>
#include<queue>
#include<cstring>
using namespace std;
char map[30][30][30];
int visited[30][30][30];
int L, R, C;
struct data_type {
	int x, y, z;
};
int dir[6][3] = { { -1,0,0 },{ 1,0 ,0 },
{ 0,-1 ,0 },{ 0,1, 0 },
{ 0 ,0,-1 },{ 0,0,1 } };
queue <data_type> que;
data_type e;
void bfs();
int main() {
	while (cin >> L >> R >> C && L&&R&&C) {
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					cin >> map[i][j][k];
					if (map[i][j][k] == '.' || map[i][j][k] == '#') continue;
					if (map[i][j][k] == 'S') {
						que.push({ i,j,k });
						continue;
					}
					if (map[i][j][k] == 'E') {
						e = { i,j,k };
						continue;
					}
				}
			}
		}
		bfs();
		memset(visited, 0, sizeof(visited));
		while (!que.empty()) que.pop();
	}
}

void bfs() {
	while (!que.empty()) {
		data_type tmp = que.front();
		if (tmp.x == e.x && tmp.y == e.y&& tmp.z == e.z) {
				cout << "Escaped in " << visited[e.x][e.y][e.z] << " minute(s)." << endl;
			return;
		}
		que.pop();
		for (int i = 0; i < 6; i++) {
			int nx = tmp.x + dir[i][0];
			int ny = tmp.y + dir[i][1];
			int nz = tmp.z + dir[i][2];
			if (nx >= 0 && ny >= 0 && nz >= 0 && nx < L && ny < R && nz < C) {
				if (map[nx][ny][nz] != '#' && !visited[nx][ny][nz]) {
					visited[nx][ny][nz] = visited[tmp.x][tmp.y][tmp.z] + 1;
					que.push({ nx,ny,nz });
				}
			}
		}
	}
	cout << "Trapped!" << endl;
}