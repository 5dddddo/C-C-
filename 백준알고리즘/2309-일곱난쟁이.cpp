#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v(9);
int main() {
	int sum = 0;
	bool flag = false;
	for (int i = 0; i < 9; i++) {
		cin >> v[i];
		sum += v[i];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = i + 1; j < 9; j++) {
			if (sum - (v[i] + v[j]) == 100) {
				v[i] = 0;
				v[j] = 0;
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	sort(v.begin(), v.end());
	for (int i = 2; i < 9; i++) cout << v[i] << ' ';
	return 0;
}