                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    #include <iostream>
#include <queue>
using namespace std;
struct info {
	int x, y, cnt;
	bool flag;
};
char map[101][101];
bool visited[2][101][101];
int dir[4][2] = { { -1,0 },{ 1,0 },{ 0, -1 },{ 0 ,1 } };
queue <info> que;
int N, M;
int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	que.push({ 1,1,1,false });
	visited[0][1][1] = true;
	while (!que.empty()) {
		info tmp = que.front();
		que.pop();
		if (tmp.x == N && tmp.y == M) {
			cout << tmp.cnt << endl;
			return 0;
		}
		for (int i = 0; i < 4; i++) {
			cout << i << endl;
			int nx = tmp.x + dir[i][0];
			int ny = tmp.y + dir[i][1];
			if (nx > 0 && ny > 0 && nx <= N && ny <= M) {
				if (map[nx][ny] == '1') {
					if (!tmp.flag) {
						if (!visited[true][nx][ny]) {
							visited[true][nx][ny] = true;
							que.push({ nx,ny,tmp.cnt + 1,true });
						}
					}
				}
				else {
					if (!visited[tmp.flag][nx][ny]) {
						visited[tmp.flag][nx][ny] = true;
						que.push({ nx,ny,tmp.cnt + 1,tmp.flag });
					}
				}
			}
		}
	}
	cout << "-1" << endl;
	return 0;
}