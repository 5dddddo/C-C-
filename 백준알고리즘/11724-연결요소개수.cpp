#include <iostream>
using namespace std;
int parent[1001];
int n, e;
void makeGraph() {
	for (int i = 1; i <= n; i++)
		parent[i] = i;
}
int find(int i) {
	if (parent[i] == i) return i;
	return find(parent[i]);
}
int main() {
	int a, b, u, v;
	scanf("%d %d", &n, &e);
	makeGraph();

	for (int i = 0; i < e; i++) {
		scanf("%d %d", &a, &b);
		u = find(a); v = find(b);
		if (u == v) continue;
		parent[v] = u;
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (parent[i] == i)
			cnt++;
	}
	printf("%d\n", cnt);

}