#include<iostream>
using namespace std;
int maxN, minN;
void gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	maxN = a;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tcnt;
	pair<int, int > xy;
	cin >> tcnt;
	for (int i = 0; i < tcnt; i++) {
		int m, n, x, y, cnt = 0, plus;
		bool flag = false;
		cin >> m >> n >> x >> y;
		if (x == y) {
			cout << x << endl;
			continue;
		}
		if (m < n) {
			int tmp = n;
			n = m;
			m = tmp;
			tmp = x;
			x = y;
			y = tmp;
		}
		gcd(m, n);
		minN = m * n / maxN;
		xy.first = y;
		xy.second = y;
		cnt = y;
		plus = n;

		for (int j = 0; j < minN / plus; j++) {
			if (x == xy.first && y == xy.second) {
				cout << cnt << endl;
				flag = true;
				break;
			}
			xy.first = (xy.first + n) % m == 0 ? m : (xy.first + n) % m;
			cnt += n;
		}
		if (!flag)
			cout << -1 << endl;
	}
	return 0;
}
