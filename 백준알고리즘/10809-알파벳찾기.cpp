#include <iostream>
#include <string>
using namespace std;
int alpha[26];
int main() {

	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	string str;
	cin >> str;
	for (int i = 0; i < 26; i++)
		alpha[i] = -1;

	for (int i = 0; i < str.length(); i++) {
		if (alpha[str[i] - 'a'] == -1) {
			alpha[str[i] - 'a'] = i;
		}
		else continue;
	}

	for (int i = 0; i < 26; i++)
		cout << alpha[i] << ' ';
	return 0;
}