#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
bool a[100][100];
bool visited[100][100] = { false , };
int plusX[4] = { 0,0,-1,1 };
int plusY[4] = { -1,1,0,0 };
void solve(int, int);
vector <int > section;
int M, N, K, cnt;
int main() {
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int j = x1; j < x2; j++)
			for (int k = y1; k < y2; k++) {
				if (a[j][k]) continue;
				a[j][k] = true;
			}
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			if (!a[i][j] && !visited[i][j]) {
				solve(i, j);
				section.push_back(cnt);
				cnt = 0;
			}
		}
	cout << section.size() << endl;
	sort(section.begin(), section.end());
	for (int i = 0; i < section.size(); i++)
		cout << section[i] << ' ';
	return 0;
}

void solve(int x, int y) {
	visited[x][y] = true;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int newX = x + plusX[i];
		int newY = y + plusY[i];
		if (newX >= 0 && newX < N && newY >= 0 && newY < M)
			if (!a[newX][newY] && !visited[newX][newY])
				solve(newX, newY);
	}
}