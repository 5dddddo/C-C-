#include<iostream>
using namespace std;
struct Savings{
	int w500;
	int w100;
	int w50;
	int w10;
};
void init(Savings &s);
void input(int &unit, int &cnt);
void save(Savings &s, int unit, int cnt);
int total(Savings &s);
int main()
{
	int unit, cnt, sum;
	Savings saveMoney;
	init(saveMoney);
	while (1)
	{
		input(unit, cnt);
		if (unit == 10 || unit == 100 || unit == 50 || unit == 500)
			save(saveMoney, unit, cnt);
		else break;
	}
	sum = total(saveMoney);
	cout << "총 저금액 : " << sum << endl;
	return 0;
}

void init(Savings &s)
{
	s.w10 = 0;
	s.w100 = 0;
	s.w50 = 0;
	s.w500 = 0;
}
void input(int &unit, int &cnt)
{
	cout << "동전의 금액 : ";
	cin >> unit;
	if (unit != -1)
	{
		while (cin.fail() || (unit != 10 && unit != 100 && unit != 50 && unit != 500))
		{
			cin.clear();
			while (cin.get() != '\n');
			cout << "동전의 금액 : ";
			cin >> unit;
			if (unit == -1) return;
		}
	}
	else return;
	cout << "동전의 개수 : ";
	cin >> cnt;
}
void save(Savings &s, int unit, int cnt)
{
	if (unit == 10)
		s.w10 += cnt;
	else if (unit == 100)
		s.w100 += cnt;
	else if (unit == 50)
		s.w50 += cnt;
	else s.w500 += cnt;
	int sum = 10 * s.w10 + 100 * s.w100 + 50 * s.w50 + 500 * s.w500;
	cout << sum << endl;
}
int total(Savings &s)
{
	int sum = 0;
	sum = 10 * s.w10 + 100 * s.w100 + 50 * s.w50 + 500 * s.w500;
	return sum;
}