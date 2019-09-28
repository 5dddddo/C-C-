#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	int tcCnt;
	cin >> tcCnt;
	for (int t = 0; t < tcCnt; t++) {
		int N, tmp, cnt = 1, num;
		vector <int> v;
		queue <pair<int, int>> que;

		cin >> N >> num;
		for (int i = 0; i < N; i++) {
			cin >> tmp;
			que.push({ i,tmp });
			v.push_back(tmp);
		}
		sort(v.begin(), v.end());

		while (!que.empty()) {
			pair<int, int > tmp = que.front();
			que.pop();
			if (v.back() == tmp.second) {
				if (tmp.first == num) break;
				else {
					v.pop_back(); cnt++;
				}
			}
			else if (v.back() > tmp.second)
				que.push(tmp);
		}
		cout << cnt << endl;
	}

	return 0;
}