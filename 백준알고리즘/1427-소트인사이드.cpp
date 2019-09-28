#include <iostream>
using namespace std;
int num[10];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, tmp;
	cin >> a;
	while (a) {
		tmp = a % 10;
		num[tmp]++;
		a /= 10;
	}

	for (int i = 9; i >= 0; i--) {
		for (int j = 0; j < num[i]; j++)
			cout << i;
	}
	return 0;
}
