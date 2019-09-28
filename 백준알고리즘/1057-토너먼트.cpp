#include <iostream>
#include <vector>
using namespace std;
int r;
int n, num1, num2;

int main() {
	cin >> n >> num1 >> num2;
	while (num1 != num2) {
		num1 = num1 / 2 + num1 % 2;
		num2 = num2 / 2 + num2 % 2;
		r++;
	}
	cout << r << endl;
	return 0;
}