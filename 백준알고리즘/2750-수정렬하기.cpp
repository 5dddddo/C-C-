#include <iostream>
using namespace std;
bool num[2001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a;
		num[1000 + a] = true;
	}
	for (int i = 0; i < 2001; i++) {
		if (!num[i]) continue;
		for (int j = 0; j < num[i]; j++) {
			cout << -1000 + i << endl;
		}
	}
	return 0;
}
