#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	char name[20];
	int subject[3], sum;
	double mean;
	cout << "�̸� : ";
	cin.getline(name, sizeof(name));
	cout << "�� ������ ���� : " << endl;
	cin >> subject[0] >> subject[1] >> subject[2];
	sum = subject[0] + subject[1] + subject[2];
	mean = sum / 3.0;
	cout << fixed;
	cout << setprecision(2);
	cout << "\n		=====< ����ǥ >=====\n"
		<< "========================================================\n"
		<< "     �̸�	����	����	����	����	���	\n"
		<< "========================================================\n"
		<< setw(10) << name << setw(9) << subject[0] << setw(8) << subject[1] << setw(8) << subject[2] 
		<< setw(8) << sum << setw(9) << mean << endl;
	return 0;
}