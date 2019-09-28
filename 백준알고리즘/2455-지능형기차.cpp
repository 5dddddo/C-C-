#include <iostream>
#include <vector>
using namespace std;
vector <pair<int, int>> v;
int main() {
	int ans = -1, total = 0;
	int a, b;
	for (int i = 0; i < 4; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0; i < v.size(); i++) {
		total += v[i].second - v[i].first;
		if (ans < total) ans = total;
	}
	cout << ans << endl;

	return 0;
}