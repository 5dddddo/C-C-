#include<iostream>
#include <string>
using namespace std;
int main() {
	ios_base::sync_with_stdio;
	cin.tie(NULL);
	cout.tie(NULL);

	string n1, n2;
	cin >> n1 >> n2;

	char tmp;
	tmp = n1[0];
	n1[0] = n1[2];
	n1[2] = tmp;

	tmp = n2[0];
	n2[0] = n2[2];
	n2[2] = tmp;

	cout << (n1 > n2 ? n1 : n2) << endl;

	return 0;
}