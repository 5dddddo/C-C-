#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#include <cstring>
using namespace std;
char wheel[5][8]; //0 : N, 1 : S
int dir[5];
struct info {
	int n, d, c;
};
vector <pair<int, int>> v;
int k;
void rotation();
void check();
void calValue();

int main() {
	for (int i = 1; i <= 4; i++)
		for (int j = 0; j < 8; j++)
			cin >> wheel[i][j];
	int n, d;
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> n >> d;
		v.push_back({ n,d });
	}
	check();
	calValue();
	return 0;
}
void check() {
	queue <info> que;
	for (int i = 0; i < k; i++) {
		int n = v[i].first;
		int d = v[i].second;
		que.push({ n,d,0 }); //c==왼
		que.push({ n,d,1 }); //c==오
		while (!que.empty()) {
			info tmp = que.front();
			dir[tmp.n] = tmp.d;
			que.pop();
			if (n >= 1 && n <= 4) {
				if (tmp.c == 1) {
					if (tmp.n == 4) continue;
					if (wheel[tmp.n][2] != wheel[tmp.n + 1][6])
						que.push({ tmp.n + 1,-tmp.d,tmp.c });
				}
				else {
					if (tmp.n == 1) continue;
					if (wheel[tmp.n][6] != wheel[tmp.n - 1][2])
						que.push({ tmp.n - 1,-tmp.d,tmp.c });
				}
			}
		}
		rotation();
		memset(dir, 0, sizeof(dir));
	}
}

void rotation() {
	for (int i = 1; i <= 4; i++) {
		if (dir[i] == 1) { // 시계
			int tmp = wheel[i][7];
			for (int j = 7; j >= 1; j--) wheel[i][j] = wheel[i][j - 1];
			wheel[i][0] = tmp;
		}
		else if (dir[i] == -1) { // 반시계
			int tmp = wheel[i][0];
			for (int j = 0; j <= 6; j++) wheel[i][j] = wheel[i][j + 1];
			wheel[i][7] = tmp;
		}
	}
}
void calValue() {
	int sum = 0;
	for (int i = 1; i <= 4; i++) {
		if (wheel[i][0] == '1')
			sum += pow(2, i-1);
	}
	cout << sum << endl;
}