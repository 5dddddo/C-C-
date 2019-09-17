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
	Save(const char *np = "�ƹ���", int n = 0);
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
	os << "�̸� : " << br.name << endl;
	os << "���� : " << br.capital << endl;
	os << "���ڼҵ� : " << br.profit << endl;
	os << "���� : " << br.tax << endl;
	os << "�ѱݾ� : " << br.tot << endl;
	os << "���� : " << br.ratio << endl;
	os << "���� : " << br.tax_ratio << endl;
	return os;
}
void Save::set_ratio(double r)
{
	ratio = r;
}
int main()
{
	Save a("ö��", 1000000);
	a.calculate();
	cout << a << endl;
	Save::tax_ratio = 0.15;
	Save::set_ratio(0.25);
	Save b("����", 2000000);
	b.calculate();
	cout << b << endl;
	return 0;
}