#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int num[101], n;
bool visited[101];
vector<int> ans;
void dfs(int start, int next);
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> num[i];

	for (int i = 1; i <= n; i++) {
		if (num[i] == 0) continue;
		if (i == num[i]) {
			ans.push_back(i);
			continue;
		}
		for (int j = 1; j <= n; j++) visited[j] = false;
		visited[i] = true;
		dfs(i, num[i]);
	}

	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << endl;

	return 0;
}

void dfs(int start, int next) {
	if (start == next) {
		for (int i = 1; i <= n; i++) {
			if (visited[i]) {
				ans.push_back(i);
				num[i] = 0;
			}
		}return;
	}
	if (visited[next] || num[next] == 0) return;

	visited[next] = true;
	dfs(start, num[next]);
}