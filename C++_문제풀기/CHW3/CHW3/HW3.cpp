#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	char name[20];
	int subject[3], sum;
	double mean;
	cout << "이름 : ";
	cin.getline(name, sizeof(name));
	cout << "세 과목의 점수 : " << endl;
	cin >> subject[0] >> subject[1] >> subject[2];
	sum = subject[0] + subject[1] + subject[2];
	mean = sum / 3.0;
	cout << fixed;
	cout << setprecision(2);
	cout << "\n		=====< 성적표 >=====\n"
		<< "========================================================\n"
		<< "     이름	국어	영어	수학	총점	평균	\n"
		<< "========================================================\n"
		<< setw(10) << name << setw(9) << subject[0] << setw(8) << subject[1] << setw(8) << subject[2] 
		<< setw(8) << sum << setw(9) << mean << endl;
	return 0;
}