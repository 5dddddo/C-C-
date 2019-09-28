#include <iostream>
using namespace std;
#include <queue>
int map[1000][1000];
bool visited[1000][1000];
int px[4] = { 0,0,-1,1 };
int py[4] = { -1,1,0,0 };
int N, M;
queue <pair<int, int>>que;

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1)	que.push({ i,j });
		}
	}
	while (!que.empty()) {
		pair <int, int> now = que.front();
		que.pop();
		visited[now.first][now.second] = true;
		for (int i = 0; i < 4; i++) {
			int nx = now.first+ px[i];
			int ny = now.second + py[i];
			if (nx >= 0 && ny >= 0 && nx < N &&ny < M) {
				if (!map[nx][ny] & !visited[nx][ny]) {
					map[nx][ny] = map[now.first][now.second] + 1;
					que.push({ nx,ny });
				}
			}
		}
	}
	int day = -5;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!map[i][j]) {
				cout << "-1" << endl;
				return 0;
			}
			if (day < map[i][j]) day = map[i][j];
		}
	}

	cout << day -1 << endl;
	return 0;
}