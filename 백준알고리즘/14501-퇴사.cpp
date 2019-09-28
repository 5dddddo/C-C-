#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
vector <pair<int, int>> v(16);
int ans = 0;
void dfs(int, int);
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int t, p;
		cin >> t >> p;
		v[i].first = t;
		v[i].second = p;
	}

	dfs(1, 0);
	cout << ans << endl;
	return 0;
}

void dfs(int d, int sum) {
	if (d == n + 1) {
		ans = max(ans, sum);
		return;
	}
	if (d + v[d].first <= n + 1) dfs(d + v[d].first, sum + v[d].second);
	if (d + 1 <= n + 1) dfs(d + 1, sum);
}