//#include <iostream>
//#include <queue>
//using namespace std;
//void bfs();
//int map[20][20];
//bool visited[20][20];
//int dir[4][2] = { {-1,0},{ 0, -1 } ,{ 0,1 } ,{ 1 ,0 } };
//int N;
//int sSize = 2, cnt = 0, ans = 0;
//struct shark {
//	int x, y, d;
//	int size = 2, cnt = 0;
//	bool operator < (const shark &t) const {
//		if (d == t.d) {
//			if (x == t.x) return y > t.y;
//			else return x > t.x;
//		}
//		else return d > t.d;
//	}
//};
//struct info {
//	int x, y, d;
//};
//shark baby;
//queue <info> que;
//int main() {
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < N; j++) {
//			cin >> map[i][j];
//			if (map[i][j] == 9) {
//				que.push({ i,j,0 });
//				map[i][j] = 0;
//			}
//		}
//	}
//	bfs();
//	return 0;
//}
//
//void bfs() {
//	while (!que.empty()) {
//		info tmp = que.front();
//		que.pop();
//		if (0 < map[tmp.x][tmp.y] && map[tmp.x][tmp.y] < baby.size) {
//			cout << tmp.x << ' ' << tmp.y << ' ' << tmp.d << ' ' << endl;
//			map[tmp.x][tmp.y] = 0;
//			baby.d = tmp.d;
//			if ((++baby.cnt) == baby.size) {
//				baby.size++;
//				baby.cnt = 0;
//			}
//			memset(visited, 0, sizeof(visited));
//			while (!que.empty()) que.pop();
//		}
//		for (int i = 0; i < 4; i++) {
//			int newX = tmp.x + dir[i][0];
//			int newY = tmp.y + dir[i][1];
//			if (newX < 0 || newY < 0 || newX >= N || newY >= N) continue;
//			if (visited[newX][newY]) continue;
//			if (map[newX][newY] > 0 && map[newX][newY] > baby.size) continue;
//			/*if (map[newX][newY] <= baby.size && map[newX][newY] >= 0) {*/
//				que.push({ newX,newY,tmp.d + 1 });
//				visited[newX][newY] = true;
//			/*}*/
//		}
//	}
//	cout << baby.d << endl;
//}

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
void bfs();
int map[20][20];
bool visited[20][20];
int dir[4][2] = { { -1,0 },{ 0, -1 },{ 1 ,0 } ,{ 0 , 1 } };
int N;
struct shark {
	int x, y, d;
	bool operator < (const shark &t) const {
		if (d == t.d) {
			if (x == t.x) return y > t.y;
			else return x >t.x;
		}
		else return d <t.d;
	}
	int size = 2, cnt = 0;
};

struct s {
	int d, x, y;
	bool operator <(const shark &t) const {
		if (d == t.d) {
			if (x == t.x) return y > t.y;
			else x > t.x;
		}
	}
};
shark baby;
priority_queue <shark> que;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				baby.x = i; baby.y = j;
			}
		}
	}

	que.push({ 4, 2,0 });
	que.push({ 4, 1,0 });
	que.push({ 2, 6,0 });
	que.push({ 1, 3,0 });
	while (!que.empty()) {
		cout << que.top().x << ' ' << que.top().y << endl;
		que.pop();
	}
	//bfs();
	return 0;
}

void bfs() {
	que.push({ baby.x,baby.y,0 });
	map[baby.x][baby.y] = 0;
	while (!que.empty()) {
		shark tmp = que.top();
		que.pop();
		if (0 < map[tmp.x][tmp.y] && map[tmp.x][tmp.y] < baby.size) {
			map[tmp.x][tmp.y] = 0;
			baby.d = tmp.d;
			if ((++baby.cnt) == baby.size) {
				baby.size++;
				baby.cnt = 0;
			}
			memset(visited, 0, sizeof(visited));
			while (!que.empty()) que.pop();
		}
		for (int i = 0; i < 4; i++) {
			int newX = tmp.x + dir[i][0];
			int newY = tmp.y + dir[i][1];
			if (newX < 0 || newY < 0 || newX >= N || newY >= N) continue;
			if (visited[newX][newY]) continue;
			if (map[newX][newY] <= baby.size && map[newX][newY] >= 0) {
				que.push({ newX,newY,tmp.d + 1 });
				visited[newX][newY] = true;
			}
		}
		
	}
	cout << baby.d << endl;
}