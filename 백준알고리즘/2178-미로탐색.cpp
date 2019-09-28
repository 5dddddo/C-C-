#include <iostream>
#include <queue>
using namespace std;
char map[101][101];
int visited[101][101];
int dir[4][2] = { {-1,0},{1,0 },{ 0, -1},{0 ,1 } };
queue <pair<int, int>> que;
int N, M;
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	que.push({ 1, 1 });
	visited[1][1] = 1;
	while (!que.empty()) {
		pair<int, int>tmp = que.front();
		que.pop();
		if (tmp.first == N && tmp.second == M) {
			cout << visited[tmp.first][tmp.second] << endl;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			int nx = tmp.first + dir[i][0];
			int ny = tmp.second + dir[i][1];
			if (nx > 0 && ny > 0 && nx <= N && ny <= M){
				if (!visited[nx][ny] && map[nx][ny] != '0') {
					que.push({ nx,ny });
					visited[nx][ny] =visited[tmp.first][tmp.second] + 1;
				}
			}
		}
	}
	return 0;
}