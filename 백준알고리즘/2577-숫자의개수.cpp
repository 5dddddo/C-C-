#include <iostream>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cout.tie(NULL);
	cin.tie(NULL);
	int num[3];
	long long sum;
	int cnt[10] = {};
	cin >> num[0] >> num[1] >> num[2];
	sum = num[0] * num[1] * num[2];

	while (sum) {
		cnt[sum % 10]++;
		sum /= 10;
	}


	for (int i = 0; i < 10; i++)
		cout << cnt[i] << "\n";



	return 0;
}