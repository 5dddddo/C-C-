#include <iostream>
using namespace std;
#pragma warning (disable : 4996)
class Save
{
private:
	char name[20];
	int capital;
	int profit;
	int tax;
	int tot;
	static double ratio;
public:
	static double tax_ratio;
	Save(const char *np = "아무개", int n = 0);
	void calculate();
	friend ostream &operator<<(ostream &os, const Save &br);
	static void set_ratio(double r);
};
double Save::ratio = 0.2;
double Save::tax_ratio = 0.1;
Save::Save(const char *np, int n)
{
	strcpy(name, np);
	capital = n;
	profit = ratio * capital;
	tax = profit * tax_ratio;
}
void Save::calculate()
{
	tot = capital + profit - tax;
}
ostream &operator<<(ostream &os, const Save &br)
{
	os << "이름 : " << br.name << endl;
	os << "원금 : " << br.capital << endl;
	os << "이자소득 : " << br.profit << endl;
	os << "세금 : " << br.tax << endl;
	os << "총금액 : " << br.tot << endl;
	os << "이율 : " << br.ratio << endl;
	os << "세율 : " << br.tax_ratio << endl;
	return os;
}
void Save::set_ratio(double r)
{
	ratio = r;
}
int main()
{
	Save a("철이", 1000000);
	a.calculate();
	cout << a << endl;
	Save::tax_ratio = 0.15;
	Save::set_ratio(0.25);
	Save b("메텔", 2000000);
	b.calculate();
	cout << b << endl;
	return 0;
}