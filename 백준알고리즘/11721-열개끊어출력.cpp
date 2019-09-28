#include <iostream>
#include <string>
using namespace std;

int main() {
	int cnt;
	string str;
	cin >> str;
	cnt = str.length();
	for (int i = 0; i < str.length(); i += 10) {
		if (cnt >= 10) {
			cout << str.substr(i, 10) << endl;
			cnt -= 10;
		}
		else {
			cout << str.substr(i,cnt) << endl;
			break;
		}

	}
	return 0;
}