#include <iostream>
using namespace std;

int main() {
	int tcCnt;
	int N, M, a, b;
	cin >> tcCnt;
	for (int t = 0; t < tcCnt; t++) {
		cin >> N >> M;
		for (int i = 0; i < M; i++)
			cin >> a >> b;
		cout << N - 1 << endl;
	}
	return 0;
}