#include<iostream>
#include <string>
using namespace std;
int main() {

	int num;
	string str;
	cin >> num >> str;
	num = 0;
	for (int i = 0; i < str.length(); i++) 
		num += str[i] - '0';
	cout <<num<< endl;

	return 0;
}