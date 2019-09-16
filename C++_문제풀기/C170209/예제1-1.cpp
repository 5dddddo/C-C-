#include <iostream>
using namespace std;
void my_flush();
int main()
{
	int intNumber;
	double doubleNumber;
	char ch;
	char str[100];

	cout << "정수값 입력 : ";
	cin >> intNumber;

	cout << "실수값 입력 : ";
	cin >> doubleNumber;

	cout << "문자입력 : ";
	cin >> ch;

	cout << "문자열 입력: ";
	cin >> str;

	cout << "intNumber : " << intNumber << endl;
	cout << "doubleNumber : " << doubleNumber << endl;
	cout << "ch : " << ch << endl;
	cout << "str : " << str << endl;

	my_flush();
	cin.getline(str, sizeof(str));
	cout << "입력 받은 문자열 : " << str << endl;
	cout << "여백문자 입력하세요(space,tab,endter): ";
	ch = cin.get();
	cout << "입력한 여백문자의 아스키코드 값 : " << (int)ch << endl;
	return 0;
}

void my_flush()
{
	while (cin.get() != '\n');
}