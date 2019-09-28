#include<iostream>
using namespace std;
char map[100][100] = { 0, };
bool visited[100][100] = { false, };
int plusX[4] = { 0,0,-1,1 };
int plusY[4] = { -1,1,0,0 };


int n, cnt1 = 0, cnt2 = 0;
void dfs(int x, int y);
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				dfs(i, j);
				cnt1++;
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = false;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] == 'R') map[i][j] = 'G';

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				dfs(i, j);
				cnt2++;
			}
		}
	}
	cout << cnt1 << ' ' << cnt2 << endl;

	return 0;
}
void dfs(int x, int y) {
	for (int i = 0; i < 4; i++) {
		int newX = x + plusX[i];
		int newY = y + plusY[i];
		if (newX >= 0 && newX < n && newY >= 0 && newY < n)
			if (map[x][y] == map[newX][newY] && !visited[newX][newY]) {
				visited[newX][newY] = true;
				dfs(newX, newY);
			}
	}
}