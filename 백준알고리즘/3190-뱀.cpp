#include<iostream>
#include <vector>
#include <queue>
using namespace std;
int map[101][101];
int N, cnt = 1;
int dir[4][2] = { {-1,0},{ 0,1 },{ 1, 0},{0, -1} };
struct info {
	int x, y, d;
};
char cmd[10001];
queue <pair<int, int>> que;
info head, tail;
void solve();
int main() {
	int k, x, y, L;
	char c;
	cin >> N >> k;
	for (int i = 0; i < k; i++) {
		cin >> x >> y;
		map[x][y] = 1;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> x >> c;
		cmd[x+1] = c;
	}
	solve();

	return 0;
}

void solve() {
	que.push({ 1, 1 });
	head = { 1,1,1 };
	map[1][1] = 2;
	while (1) {
		if (cmd[cnt] == 'D')
			head.d = (head.d + 1) % 4;
		else if (cmd[cnt] == 'L')
			head.d = (head.d + 3) % 4;
		int nx = head.x + dir[head.d][0];
		int ny = head.y + dir[head.d][1];
		if (nx< 1 || ny < 1 || nx >N || ny >N || map[nx][ny] == 2) {
			cout << cnt << endl;
			return;
		}
		if (map[nx][ny] == 0) {
			map[que.front().first][que.front().second] = 0;
			que.pop();
		}
		que.push({ nx,ny });
		map[nx][ny] = 2;
		head.x = nx;
		head.y = ny;
		cnt++;
	}
}
