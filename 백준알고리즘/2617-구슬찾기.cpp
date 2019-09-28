#include <iostream>
using namespace std;
#include <vector>
#define MAX 100
int N, M;
vector <int> heavy[MAX], light[MAX];
bool hVisited[MAX], lVisited[MAX];
void hDfs(int);
void lDfs(int);
int cnt;
int main() {
	cin >> N >> M;
	vector <bool> res(N + 1);
	int h, l;
	for (int i = 0; i < M; i++) {
		cin >> h >> l;
		heavy[h].push_back(l);
		light[l].push_back(h);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			hVisited[j] = false;
			lVisited[j] = false;
		}
		cnt = 0;
		hDfs(i);
		if (cnt > (N + 1) / 2) {
			res[i] = true;
			continue;
		}
		cnt = 0;
		lDfs(i);
		if (cnt > (N + 1) / 2)
			res[i] = true;
	}
	cnt = 0;
	for (int i = 1; i <= N; i++)
		if (res[i]) cnt++;

	cout << cnt << endl;
	return 0;
}

void  hDfs(int pos) {
	hVisited[pos] = true;
	cnt++;
	for (int i = 0; i < heavy[pos].size(); i++) {
		if (!hVisited[heavy[pos][i]])
			hDfs(heavy[pos][i]);
	}
}
void lDfs(int pos) {
	lVisited[pos] = true;
	cnt++;
	for (int i = 0; i < light[pos].size(); i++) {
		if (!lVisited[light[pos][i]])
			lDfs(light[pos][i]);
	}
}