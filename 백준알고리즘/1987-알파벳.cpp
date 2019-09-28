#include <iostream>
using namespace std;
char map[21][21];
int R, C;
int plusX[4] = { 0,0,-1,1 };
int plusY[4] = { -1,1,0,0 };
bool alphabet[26];
int res = 1;
void dfs(int, int, int);
int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		cin >> map[i];

	dfs(0, 0, res);
	cout << res << endl;
	return 0;
}
void dfs(int x, int y, int cnt) {
	alphabet[map[x][y] - 'A'] = true;
	if (cnt > res) res = cnt;
	for (int i = 0; i < 4; i++) {
		int newX = x + plusX[i];
		int newY = y + plusY[i];
		if (newX >= 0 && newY >= 0 && newX < R && newY < C) {
			if (!alphabet[map[newX][newY] - 'A']) {
				dfs(newX, newY, cnt + 1);
				alphabet[map[newX][newY] - 'A'] = false;
			}
		}
	}
}