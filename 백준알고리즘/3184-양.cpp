//#include <iostream>
//using namespace std;
//char map[250][250];
//bool visited[250][250];
//int dir[4][2] = { {-1,0},{ 1, 0},{0, -1},{ 0, 1} };
//int R, C, wt, st, wc, sc;
//void dfs(int, int);
//int main() {
//	cin >> R >> C;
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			cin >> map[i][j];
//			if (map[i][j] == '.' || map[i][j] == '#') continue;
//			if (map[i][j] == 'v') {
//				wt++; continue;
//			}
//			if (map[i][j] == 'o') {
//				st++; continue;
//			}
//		}
//	}
//
//	for (int i = 0; i < R; i++) {
//		for (int j = 0; j < C; j++) {
//			if (!visited[i][j] && map[i][j] != '#') {
//				dfs(i, j);
//				if (wc >= sc) st -= sc;
//				else wt -= wc;
//				wc = 0; sc = 0;
//			}
//		}
//	}
//	cout << st << ' ' << wt << endl;
//	return 0;
//}
//void dfs(int x, int y) {
//	if (map[x][y] == 'v') wc++;
//	if (map[x][y] == 'o') sc++;
//	visited[x][y] = true;
//	for (int i = 0; i < 4; i++) {
//		int nx = x + dir[i][0];
//		int ny = y + dir[i][1];
//		if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
//			if (!visited[nx][ny] && map[nx][ny] != '#')
//				dfs(nx, ny);
//		}
//	}
//}

#include <iostream>
using namespace std;
#include <queue>
queue <pair<int, int>> que;
char map[250][250];
bool visited[250][250];
int dir[4][2] = { { -1,0 },{ 1, 0 },{ 0, -1 },{ 0, 1 } };
int R, C, wt, st, wc, sc;
int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == '.' || map[i][j] == '#') continue;
			if (map[i][j] == 'v') {
				wt++; continue;
			}
			if (map[i][j] == 'k') {
				st++; continue;
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (!visited[i][j] && map[i][j] != '#') {
				que.push(make_pair(i,j));
				visited[i][j] = true;
				while (!que.empty()) {
					pair<int, int> tmp = que.front();
					que.pop();
					if (map[tmp.first][tmp.second] == 'v') wc++;
					if (map[tmp.first][tmp.second] == 'k') sc++;
					for (int k = 0; k < 4; k++) {
						int nx = tmp.first + dir[k][0];
						int ny = tmp.second + dir[k][1];
						if (nx >= 0 && ny >= 0 && nx < R && ny < C) {
							if (!visited[nx][ny] && map[nx][ny] != '#') {
								visited[nx][ny] = true;
								que.push(make_pair(nx, ny));
							}
						}
					}
				}
			}
			if (wc >= sc) st -= sc;
			else wt -= wc;
			wc = 0; sc = 0;
		}
	}
	cout << st << ' ' << wt << endl;
	return 0;
}