#include <iostream>
using namespace std;
#include <queue>
int map[100][100][100];
bool visited[100][100][100];
int M, N, H;
int dir[6][3] = { {-1,0,0},{1,0 ,0 },
{0,-1 ,0 },{ 0,1, 0},
{0 ,0,-1 },{ 0,0,1 } };
struct data_type {
	int x, y, z;
};
int cnt, ans;
queue <data_type> que;
int main() {
	cin >> M >> N >> H;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < M; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					que.push({ i,j,k });
					continue;
				}
				if (map[i][j][k] == 0) cnt++;
			}
		}
	}
	if (!cnt) {
		cout << "0" << endl;
		return 0;
	}
	while (!que.empty()) {
		int size = que.size();
		for (int j = 0; j < size; j++) {
			data_type tmp;
			tmp = que.front();
			visited[tmp.x][tmp.y][tmp.z] = true;
			que.pop();
			for (int i = 0; i < 6; i++) {
				int nx = tmp.x + dir[i][0];
				int ny = tmp.y + dir[i][1];
				int nz = tmp.z + dir[i][2];
				if (nx >= 0 && ny >= 0 && nz >= 0 && nx < H&&ny < N&&nz < M) {
					if (!visited[nx][ny][nz] && !map[nx][ny][nz]) {
						que.push({ nx, ny, nz });
						map[nx][ny][nz] = 1;
						cnt--;
					}
				}
			}
		}
		ans++;
		if (!cnt) {
			cout << ans << endl;
			return 0;
		}
	}
	cout << "-1" << endl;
	return 0;
}