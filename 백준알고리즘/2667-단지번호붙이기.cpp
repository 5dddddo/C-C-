#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <string>
vector<int> ans;
int map[26][26], n, cnt;
bool visited[26][26];
int plusX[4] = { 0,0,-1,1 };
int plusY[4] = { -1,1,0,0 };
void dfs(int, int);
int main() {
	string st;
	cin >> n;
	for (int j = 0; j < n; j++) {
		cin >> st;
		for (int i = 0; i < st.size(); i++)
			map[j][i] = st[i] - '0';
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j]) {
				dfs(i, j);
				ans.push_back(cnt);
				cnt = 0;
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;
	return 0;
}

void dfs(int x, int y) {
	cnt++;
	visited[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int newX = x + plusX[i];
		int newY = y + plusY[i];
		if (!visited[newX][newY] && map[newX][newY])
			dfs(newX, newY);

	}
}