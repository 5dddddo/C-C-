#include <iostream>
#include <cstring>
#include <string>
using namespace std;
int main()
{
	string str("     ���Ǵ��б� ������  ");
	string apple = "apple", banana("�ٳ���banana");
	cout << "str �ʱⰪ : " << str << endl << endl;
	string str1("������");
	cout << "str1 : " << str1 << endl << endl;
	string str2(str1);
	cout << "apple : " << apple << "	apple[7] : " << apple[3] << "	apple.at(6) : " << apple.at(3) << endl << endl;
	cout << "str1.empty() : " << str1.empty() << "	str.empty() : " << str.empty() << endl << endl;
	cout << "str1[3]�� 01056113427 " << str1.insert(6, "01056113427") << "	str1 ���� : " << str1.length() << endl << endl;
	cout << banana << " ���ڿ����� n�� " << banana.find("n") << "��° �濡 ��ġ" << endl << endl;
	cout << str << " ���ڿ��� ���� a�� ã���� " << str.find("a") << "�� return��" << endl << endl;
//	cout << "apple + banana => " << apple + banana << endl << endl;
	cout << "apple[7]���� 2���� ����� :" << apple.erase(1, 2) << endl << endl;

	string temp;
	cout << "���� ���� ���ڿ� �Է� : ";
	cin >> temp;
	cout << "���� ���� ���ڿ� �Է� ��� : " << temp << endl;
	cin.ignore();
	cout << "���� �ִ� ���ڿ� �Է� : ";
	getline(cin, temp);
	cout << "���� �ִ� ���ڿ� �Է� ��� : " << temp << endl;
	return 0;
}