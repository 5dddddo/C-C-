#include <iostream>
using namespace std;
#include <vector>
#include <string>
#define ABS(x) (x>0? x: -(x))
int cvCnt;
vector <pair<int, int>> xy;
bool visited[102];
bool dist(pair<int, int>, pair<int, int>);
void dfs(int pos);
int main() {
	vector <string> ans;
	int tcCnt;
	pair <int,int> input;
	cin >> tcCnt;
	for (int t = 1; t <= tcCnt; t++) {
		cin >> cvCnt;
		for (int i = 0; i < cvCnt + 2; i++) {
			cin >> input.first >> input.second;
			xy.push_back(input);
		}
		dfs(0);
		visited[cvCnt + 1] ? ans.push_back("happy") : ans.push_back("sad");
		for (int i = 0; i < cvCnt + 2; i++) visited[i] = false;
		xy.resize(0);
	}
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << endl;
	}
	return 0;
}

bool dist(pair<int, int>a, pair<int, int>b) {
	if (ABS(a.first - b.first) + ABS(a.second - b.second) <= 1000)
		return true;
	else return false;
}
void dfs(int pos) {
	visited[pos] = true;
	for (int i = 1; i < cvCnt + 2; i++) {
		if (dist(xy[pos], xy[i]) && !visited[i])
			dfs(i);
	}
}

