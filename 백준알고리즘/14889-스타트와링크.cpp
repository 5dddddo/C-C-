//¿ÏÀüÅ½»ö -> dfs(Àç±Í)
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
void go(int, int start, int link);
int main() {
	cin >> n;
	go(0, 0, 0);

	return 0;
}

void go(int s, int start, int link) {
	if (link > n / 2 || start >= n)return;
	if (link == n/2) {
		cout << s << endl; return;
	}
	if (start < n / 2) go(s|(1<<start), start + 1, link+1);
	if (start < n / 2) go(s, start+1 , link);
}