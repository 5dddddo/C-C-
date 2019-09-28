#include<iostream>
#include <string>
using namespace std;
int main() {

	int m, d, sum = 0;
	string days[] = { "SUN","MON", "TUE", "WED", "THU", "FRI", "SAT" };
	int months[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	cin >> m >> d;
	for (int i = 0; i < m - 1; i++)
		sum += months[i];
	sum += d;
	cout << days[sum % 7] << endl;
	return 0;
}