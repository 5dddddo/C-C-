#include <iostream>
#include <queue>
//#include <math.h>
using namespace std;
int map[101][101];
bool visited[101][101];
int dir[4][2] = { { 0, 1},{-1 , 0},{ 0,-1 },{ 1, 0} };
struct dragon {
	int x, y, d, g;
};
queue <dragon> que;

void checkDragonCurve();
void countRectangle();
int main() {
	int cnt;
	cin >> cnt;
	for (int i = 0; i < cnt; i++) {
		dragon tmp;
		cin >> tmp.x >> tmp.y >> tmp.d >> tmp.g;
		map[tmp.y][tmp.x] = 1;
		que.push(tmp);
	}
	checkDragonCurve();
	countRectangle();
	return 0;
}

void checkDragonCurve() {
	while (!que.empty()) {
		int x = que.front().x;
		int y = que.front().y;
		int d = que.front().d;
		int g = que.front().g;
		que.pop();

		int nx = x + dir[d][1];
		int ny = y + dir[d][0];
		map[ny][nx] = 1;
		cout << ny << ' ' << nx << endl;
		int ng = 1;
		x = nx;
		y = ny;

		while (ng <= g) {
			for (int i = 0; i < pow(2, ng - 1); i++) {
				int nd = (d + 1) % 4;
				int nx = x + dir[nd][1];
				int ny = y + dir[nd][0];
				cout << ny << ' ' << nx << endl;
				map[ny][nx] = 1;
				x = nx;
				y = ny;
				d = nd;
			}
			ng++;
		}
	}

}
void countRectangle() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			cout << map[i][j] << ' ';
		}
		cout << endl;
	}
}
