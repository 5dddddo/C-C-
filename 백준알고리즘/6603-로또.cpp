#include<iostream>
using namespace std;
int k = 1;
int S[13];
int answer[6];
void dfs(int, int);
int main() {
	while (cin >> k && k) {
		for (int i = 0; i < k; i++)
			cin >> S[i];
		dfs(0, 0);
		cout << endl;
	}
	return 0;
}

void dfs(int pos, int depth) {
	if (depth == 6) {
		for (int i = 0; i < 6; i++)
			cout << answer[i] << ' ';
		cout << endl;
		return;
	}
	for (int i = pos; i < k; i++) {
		answer[depth] = S[i];
		dfs(i + 1, depth + 1);
	}

}
