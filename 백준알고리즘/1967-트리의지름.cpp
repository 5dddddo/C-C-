#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N;
bool visited[10001];
vector<pair<int, int>>v[10001];
void dfs(int, int);
int ans;
int endPoint;
int main() {
	int p, c, w;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> p >> c >> w;
		v[p].push_back({ c, w });
		v[c].push_back({ p,w });
	}
	dfs(1, 0);
	ans = 0;
	memset(visited, 0, sizeof(visited));
	dfs(endPoint, 0);
	cout << ans << endl;
	return 0;

}

void dfs(int node, int weight) {
	visited[node] = true;
	if (ans < weight) {
		ans = weight;
		endPoint = node;
	}
	for (int i = 0; i < v[node].size(); i++) {
		if (visited[v[node][i].first]) continue;
		dfs(v[node][i].first, v[node][i].second + weight);
	}

}