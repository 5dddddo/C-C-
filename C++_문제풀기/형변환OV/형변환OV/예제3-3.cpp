#include <iostream>
using namespace std;
class Time
{
private: 
	int hour;
	int min;
public:
	Time(int h = 0, int m = 0);
	Time(double t);
//	operator double() const;
	double to_double();
	void show();
};

Time::Time(int h, int m)
{
	cout << "int,int ������ ȣ��..." << endl;
	hour = h;
	min = m;
}

Time::Time(double t)
{
	cout << "double ������ ȣ��..." << endl;
	hour = int(t);
	min = (int)((t - hour)*60.0);
}

//Time::operator double() const
//{
//	cout << "����ȯ�Լ� ȣ��..." << endl;
//	double temp;
//	temp = hour + min / 60.0;
//	return temp;
//}
void Time::show()
{
	cout << this->hour << "�ð� " << this->min << "��" << endl;
}

double Time::to_double()
{
	double temp;
	temp = hour + min / 60.0;
	return temp;
}

int main()
{
	Time a;
	a = 3.5;
	a.show();
	//double res;
	//res = 1.0 + a;
	//cout << res << endl;

	double res = 1.5 + a.to_double();

	cout << res << endl;

	return 0;
}
