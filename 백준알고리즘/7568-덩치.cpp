#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct info {
	int n, w, h, c;
	bool operator < (const info &t) const {
		if (w != t.w) return w > t.w;
		else  return h < t.h;
	}
};
bool cmp(info a, info b) {
	return a.n < b.n;
}
vector<info> v;
priority_queue <info> que;
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int w, h;
		cin >> w >> h;
		que.push({ i,w,h,1 });
	}
	while (!que.empty()) {
		v.push_back(que.top());
		que.pop();
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if (v[i].h < v[j].h)
				v[i].c++;
		}
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++)
		cout << v[i].c << endl;
	return 0;
}