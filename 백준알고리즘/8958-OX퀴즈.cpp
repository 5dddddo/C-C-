#include <iostream>
#include <string>
using namespace std;

int main() {

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string str;
		int sum = 0, cnt = 0;
		cin >> str;

		for (int j = 0; j < str.length(); j++) {
			if (str[j] == 'O')
				sum += (++cnt);
			else cnt = 0;
		}
		cout << sum << endl;
	}

	return 0;
}