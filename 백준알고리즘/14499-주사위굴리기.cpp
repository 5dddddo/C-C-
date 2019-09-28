#include <iostream>
#include <cstring>
using namespace std;
int map[20][20];
int N, M, x, y, k;
int cmd[1000];
int dice[6], ndice[6];
int dir[5][2] = { {0,0}, {0,1},{0, -1},{ -1,0 },{1 ,0 } };
void moveDice(int);
void solve();

int main() {
	cin >> N >> M >> x >> y >> k;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	for (int i = 0; i < k; i++)
		cin >> cmd[i];
	solve();
	return 0;
}

void moveDice(int d) {
	if (d == 1) {
		dice[5] = ndice[3];
		dice[3] = ndice[0];
		dice[0] = ndice[1];
		dice[1] = ndice[5];
	}
	else if (d == 2) {
		dice[5] = ndice[1];
		dice[1] = ndice[0];
		dice[0] = ndice[3];
		dice[3] = ndice[5];
	}
	else if (d == 3) {
		dice[5] = ndice[2];
		dice[0] = ndice[4];
		dice[4] = ndice[5];
		dice[2] = ndice[0];
	}
	else if (d == 4) {
		dice[5] = ndice[4];
		dice[4] = ndice[0];
		dice[0] = ndice[2];
		dice[2] = ndice[5];
	}
}

void solve() {
	int sx = x, sy = y;
	for (int i = 0; i < k; i++) {
		int nx = sx + dir[cmd[i]][0];
		int ny = sy + dir[cmd[i]][1];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M)  continue;
		memcpy(ndice, dice, sizeof(dice));
		moveDice(cmd[i]);
		if (!map[nx][ny])
			map[nx][ny] = dice[5];
		else {
			dice[5] = map[nx][ny];
			map[nx][ny] = 0;
		}
		cout << dice[0] << endl;
		sx = nx;
		sy = ny;
	}
}