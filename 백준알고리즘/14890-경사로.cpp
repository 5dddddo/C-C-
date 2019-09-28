#include <iostream>
using namespace std;
#define ABS(x) x>0 ? x : -(x)
int N, L, ans;
int map[100][100];
bool visited[100][100];
void search();
int main() {
	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	}
	search();
	return 0;
}
void search() {
	for (int i = 0; i < N; i++) {
		int cnt1 = 1, cnt2 = 1, big = 0; bool flag = false;
		for (int j = 0; j < N - 1; j++) {
			if (map[i][j] == map[i][j + 1]) {
				if (!flag) {
					cnt1++;
					if (cnt1 == N) {
						ans++; cout << i << endl;  break;
					}
					continue;
				}
				else {
					cnt2++;
					if (big == 1 && cnt2 >= L) {
						for (int k = j - cnt2 + 1, n = 0; n < L; k++, n++) {
							if (visited[i][k]) break;
							visited[i][k] = true;
						}
						cnt1 = cnt2; cnt2 = 1; flag = false; big = 0;
					}
					else if (big == 2 && cnt1 >= L) {
						for (int k = j - cnt2 + 1, n = 0; n < L; k--, n++) {
							if (visited[i][k]) break;
							visited[i][k] = true;
						}
						cnt1 = cnt2; cnt2 = 1; flag = false; big = 0;
					}
				}
			}
			else if (ABS(map[i][j] - map[i][j + 1]) > 1)
				break;
			else {
				if (!flag) {
					flag = true;
					map[i][j] > map[i][j + 1] ? big = 1 : big = 2; continue;
				}
			}

			if (j == N - 2) {
				cout << i << endl;  ans++;
			}
		}
	}
	cout << ans << endl;

}