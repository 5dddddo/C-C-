#include <iostream>
using namespace std;
int R, C;
char map[25][25];
bool visited[25][25];
int px[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
pair<int, int >ans;
void dfs(int, int, int);
bool dir(int, int, int);
int bit;
int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			cin >> map[i][j];

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			if (!visited[i][j] && map[i][j] != '.')
				dfs(i, j, 5);

	cout << ans.first << ' ' << ans.second << ' ';

	switch (bit)
	{
	case 3: cout << "|"; break;
	case 12: cout << "-"; break;
	case 15: cout << "+"; break;
	case 5: cout << "1"; break;
	case 6: cout << "2"; break;
	case 10: cout << "3"; break;
	case 9: cout << "4"; break;
	}
	return 0;
}

void dfs(int x, int y, int d) {
	if (map[x][y] == '.') {
		ans.first = x + 1;
		ans.second = y + 1;
		bit |= (1 << d);
		return;
	}

	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		int nx = x + px[i][0];
		int ny = y + px[i][1];
		if (dir(x, y, i) && !visited[nx][ny] && nx >= 0 && ny >= 0 && nx < R && ny < C) {
			dfs(nx, ny, i);
		}
	}
}

bool dir(int x, int y, int d) {
	if (map[x][y] == '|') if (d == 0 || d == 1) return 1;
	if (map[x][y] == '-') if (d == 2 || d == 3) return 1;
	if (map[x][y] == '+') return 1;
	if (map[x][y] == '1') if (d == 1 || d == 3) return 1;
	if (map[x][y] == '2') if (d == 0 || d == 3) return 1;
	if (map[x][y] == '3') if (d == 0 || d == 2) return 1;
	if (map[x][y] == '4') if (d == 1 || d == 2) return 1;
	return 0;
}