#include <iostream>
#include <queue>;
using namespace std;
int F, S, G, U, D;
int map[1000001];
bool visited[1000001];
queue <int> que;
int main() {
	cin >> F >> S >> G >> U >> D;
	que.push(S);
	visited[S] = true;
	map[S] = 0;
	while (!que.empty()) {
		int here = que.front();
		que.pop();
		if (here == G) { cout << map[here] << endl; return 0; }
		int dir[2] = { here + U, here - D };
		for (int i = 0; i < 2; i++) {
			int next = dir[i];
			if (next <= F && !visited[next] && next >= 1) {
				que.push(next);
				visited[next] = true;
				map[next] = map[here] + 1;
			}
		}
	}
	cout << "use the stairs" << endl;

	return 0;
}