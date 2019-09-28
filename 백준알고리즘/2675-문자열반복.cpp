#include <iostream>
#include <string>
using namespace std;
int main() {

	int tcnt, r;
	string str;
	cin >> tcnt;
	for (int i = 0; i < tcnt; i++) {
		cin >> r >> str;

		for (int j = 0; j < str.length(); j++)
			for (int k = 0; k < r; k++)
				cout << str[j];
		cout << endl;

	}
	return 0;
}