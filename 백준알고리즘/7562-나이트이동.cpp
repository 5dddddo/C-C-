#include <iostream>
using namespace std;
#include <queue>
#include <cstring>
int map[300][300];
queue <pair<int, int>> k;
pair <int, int> s, e;
int dir[8][2] = { {-1,-2},{ -2, -1},
{ -2, 1},{ -1, 2},
{1 ,2 },{2 ,1 }, 
{2,-1},{1 ,-2 } }; 
int n;
int main() {
	int tcCnt;
	cin >> tcCnt;
	for (int t = 1; t <= tcCnt; t++) {
		memset(map, false, sizeof(map));
		cin >> n >> s.first >> s.second >> e.first >> e.second;
		k.push(s);
		map[s.first][s.second] = 1;
		while (!k.empty()) {
			pair<int, int> tmp = k.front();
			k.pop();
			for (int i = 0; i < 8; i++) {
				int nx = tmp.first + dir[i][0];
				int ny = tmp.second + dir[i][1];
				if (nx >= 0 && ny >= 0 && nx < n &&ny < n) {
					if (!map[nx][ny]) {
						map[nx][ny] = map[tmp.first][tmp.second] + 1;
						k.push({ nx, ny });
					}
				}
			}
		}
		cout << map[e.first][e.second] - 1 << endl;
	}

	return 0;
}
