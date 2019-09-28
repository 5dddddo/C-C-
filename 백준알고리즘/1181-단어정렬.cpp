#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int visited[20001];
int main() {

	vector <string> str;
	int n, maxL = 0;
	string tmp ,tmp2;
	cin >> n;
	int k = n;
	while (k--) {
		cin >> tmp;
		str.push_back(tmp);
		if (maxL < tmp.length()) maxL = tmp.length();
	}

	sort(str.begin(), str.end());
	tmp2 = str[0];
	tmp = str[n - 1];
	if (tmp == tmp2) {
		cout << tmp << endl;
		return 0;
	}
	for (int j = 1; j <= maxL; j++) {
		for (int i = 0; i < n; i++) {
			if (visited[i]) continue;
			if (!visited[i] && str[i] != tmp && str[i].size() == j) {
				visited[i] = true;
				tmp = str[i];
				cout << str[i] << endl;
			}
		}
	}
	return 0;
}
