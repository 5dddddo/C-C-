#include <iostream>
#include <string>
using namespace std;

int main() {
	int num[8] = {};
	int flag;
	string res[3] = { "ascending","descending", "mixed" };

	for (int i = 0; i < 8; i++)
		cin >> num[i];
	if (num[0] == 1) flag = 0;
	else if (num[0] == 8) flag = 1;
	else flag = 2;

	for (int i = 0; i < 7; i++) {

		if (num[i] + 1 == num[i + 1]) {
			if (flag != 0) {
				flag = 2;
				break;
			}
		}
		else if (num[i] - 1 == num[i + 1]) {
			if (flag != 1) {
				flag = 2;
				break;
			}
		}
		else flag = 2;
	}

	cout << res[flag] << endl;


	return 0;
}