#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	string str("     숭실대학교 오은애  ");
	string apple = "apple", banana("바나나banana");
	cout << "str 초기값 : " << str << endl << endl;
	string str1("오은애");
	cout << "str1 : " << str1 << endl << endl;
	string str2(str1);
	cout << "apple : " << apple << "	apple[7] : " << apple[3] << "	apple.at(6) : " << apple.at(3) << endl << endl;
	cout << "str1.empty() : " << str1.empty() << "	str.empty() : " << str.empty() << endl << endl;
	cout << "str1[3]에 01056113427 " << str1.insert(6, "01056113427") << "	str1 길이 : " << str1.length() << endl << endl;
	cout << banana << " 문자열에서 n은 " << banana.find("n") << "번째 방에 위치" << endl << endl;
	cout << str << " 문자열에 없는 a를 찾으면 " << str.find("a") << "이 return됨" << endl << endl;
//	cout << "apple + banana => " << apple + banana << endl << endl;
	cout << "apple[7]부터 2글자 지우기 :" << apple.erase(1, 2) << endl << endl;

	string temp;
	cout << "여백 없는 문자열 입력 : ";
	cin >> temp;
	cout << "여백 없는 문자열 입력 결과 : " << temp << endl;
	cin.ignore();
	cout << "여백 있는 문자열 입력 : ";
	getline(cin, temp);
	cout << "여백 있는 문자열 입력 결과 : " << temp << endl;
	return 0;
}