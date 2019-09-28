#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int N, M, ans;
int dir[4][2] = { {-1,0},{ 0, 1},{1 ,0 },{ 0, -1} };
struct cameraInfo {
	int x, y, cNum, dir = 0;
};
vector <cameraInfo> v;
int map[7][7], int cnt[8];
void dfs(cameraInfo);
int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0 && map[i][j] != 6)
				v.push_back({ i,j, map[i][j] });
		}
	}

	for (int i = 0; i < v.size(); i++) {
		dfs(i);
	}
	return 0;
}
int dirSelect(int num) {
	if (num == 1 && num == 3 || num == 4)
		return 4;
	else if()
}
void dfs(int num) {
	for (int i = 0; i < dirSelect(num); i++) {
		int newX = ;
		int newY =
	}

}