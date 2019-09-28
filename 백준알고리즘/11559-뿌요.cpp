#include <iostream>
using namespace std;
#include <vector>
#define R 12
#define C 6
void dfs(int, int);
vector <pair<int, int>> tmp;
int px[4] = { 0,0,-1,1 };
int py[4] = { -1,1,0,0 };
char map[R][C];
bool visited[R][C];
int combo, cnt;
int main() {
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> map[i][j];
	while (1) {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] != '.' && !visited[i][j]) {
					dfs(i, j);
					if (cnt < 4) {
						while (cnt) {
							tmp.pop_back();
							cnt--;
						}
					}
					cnt = 0;
				}
			}
		}
		if (!tmp.size()) {
			cout << combo << endl;
			return 0;
		}
		for (int i = 0; i < tmp.size(); i++)
			map[tmp[i].first][tmp[i].second] = '.';

		combo++;
		for (int i = R - 1; i >= 0; i--) {
			for (int j = 0; j < C; j++) {
				if (map[i][j] == '.' && i) {
					for (int k = i - 1; k >= 0; k--) {
						if (map[k][j] != '.') {
							map[i][j] = map[k][j];
							map[k][j] = '.';
							break;
						}
					}
				}
			}
		}

		for (int i = 0; i < R; i++)
			for (int j = 0; j < C; j++)
				visited[i][j] = false;
		tmp.resize(0);
	}
	return 0;
}


void dfs(int x, int y) {
	cnt++;
	visited[x][y] = true;
	tmp.push_back(make_pair(x, y));
	for (int i = 0; i < 4; i++) {
		int nx = x + px[i];
		int ny = y + py[i];
		if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
			if (map[x][y] == map[nx][ny] && !visited[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}
}