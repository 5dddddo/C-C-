#include <iostream>
#include <string>
using namespace std;
int alpha[26];
int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);
	int max = 0, index = -1;
	bool flag = false;
	string str;
	cin >> str;

	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		alpha[str[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		if (max < alpha[i]) {
			index = i;
			max = alpha[i];
			flag = false;
		}
		else if (max == alpha[i] && index != -1)
			flag = true;
	}
	if (flag) cout << '?' << endl;
	else cout << (char)(index + 'A') << endl;

	return 0;
}